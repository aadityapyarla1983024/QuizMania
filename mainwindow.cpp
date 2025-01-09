#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <regex>
#include <string>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <SmtpMime>
#include <QString>
#include <QTimer>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QCryptographicHash>
#include <QByteArray>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    ui->setupUi(this);
    connect(this, SIGNAL(noEmptyField()), this, SLOT(noEmptyFieldCheck()));
    connect(this, SIGNAL(resendTimerFinished()), this, SLOT(on_resendTimerFinished_emmited()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(on_email_textEdited(QString)));
    connect(ui->firstName, SIGNAL(textEdited()), this, SLOT(on_firstName_textEdited()));
    connect(ui->lastName, SIGNAL(textEdited()), this, SLOT(on_lastName_textEdited()));
    connect(ui->username, SIGNAL(textEdited(QString)), this, SLOT(on_username_textEdited(QString)));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
    connect(ui->changeEmailButton, SIGNAL(clicked()), this, SLOT(on_changeEmailButton_clicked()));
    connect(ui->resendButton, SIGNAL(clicked()), this, SLOT(on_resendButton_clicked()));
    connect(ui->emailConfirmCode, SIGNAL(textEdited(QString)), this, SLOT(on_emailConfirmCode_textEdited(QString)));
    connect(ui->passwordInput1, SIGNAL(textEdited(QString)), this, SLOT(on_passwordInput1_textEdited(QString)));
    connect(ui->passwordInput2, SIGNAL(textEdited(QString)), this, SLOT(on_passwordInput2_textEdited(QString)));
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    db.setHostName("127.0.0.1");
    db.setDatabaseName("QuizMania");
    db.setPort(33061);
    db.setUserName("root");
    db.setPassword("24bcs003");
    db.open();
    register_query.prepare("INSERT INTO users (first_name, last_name, user_name, user_email, user_password_hash) "
                           "VALUES ( :first_name, :last_name, :user_name, :user_email, :user_password_hash)");
    db_fetch_query.exec("SELECT user_name, user_email FROM users") ? qDebug() << "Fetched database successfully" :
        qDebug() << "Error while fetching database";
    while (db_fetch_query.next()) {
        existingUsernames.insert(db_fetch_query.value(0).toString());
        existsingEmails.insert(db_fetch_query.value(1).toString());
    }
    login_query_username.prepare("SELECT user_password_hash FROM users WHERE user_name = :user_name");
    
    login_query_email.prepare("SELECT user_password_hash FROM users WHERE user_email = :user_email");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::noEmptyFieldCheck() {
    if(m_emailValid && m_firstName && m_lastName && m_userName) {
        ui->nextButton->setEnabled(true);
    } else {
        ui->nextButton->setEnabled(false);
    }
}

bool MainWindow::isEmailValid(const std::string& email)
{

    // Regular expression definition
    const std::regex pattern(
        R"((^[A-Za-z0-9]+(?:[._%+-]*[A-Za-z0-9]+)*@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$))");

    // Match the string pattern
    // with regular expression
    return regex_match(email, pattern);
}

void MainWindow::on_resendTimerFinished_emmited() {
    ui->resendButton->setDisabled(false);
}


void MainWindow::on_email_textEdited(const QString &email)
{
    if (isEmailValid(email.toStdString())) {
        if(existsingEmails.contains(email)) {
            ui->emailLabel->setText("⛔️ Your email already exists, please login to continue");
            m_emailValid = false;
        } else {
            ui->emailLabel->setText("✅ You have entered a valid email.");
            m_emailValid = true;
        }


    } else {
        ui->emailLabel->setText("⛔️ Please enter a valid email.");
        m_emailValid = false;
    }
    emit noEmptyFieldCheck();
}


void MainWindow::on_firstName_textEdited()
{

    if (ui->firstName->text().isEmpty()) {
        m_firstName = false;

    } else {
        m_firstName = true;
    }
    emit noEmptyFieldCheck();
}


void MainWindow::on_lastName_textEdited()
{
    if (ui->lastName->text().isEmpty()) {
        m_lastName = false;

    } else {
        m_lastName = true;
    }
    emit noEmptyFieldCheck();
}


void MainWindow::on_username_textEdited(const QString &username) {
    if (existingUsernames.contains(username)) {
        ui->usernameLabel->setText("⛔️ Your username is already taken");
        m_userName = false;

    } else {
        ui->usernameLabel->setText("✅ You have entered a valid username.");
        m_userName = true;
    }
    emit noEmptyFieldCheck();
}


void MainWindow::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    m_email = ui->email->text();
    ui->recieveEmailLabel->setText("Email: " + m_email);
    sendEmailConfirmation();
    resendTimer();
}

void MainWindow::on_changeEmailButton_clicked() {
    m_emailSent = false;
    ui->stackedWidget->setCurrentIndex(1);
    ui->emailConfirmCode->clear();

    ui->email->clear();
    ui->email->setFocus();
    m_emailValid = false;
    emit noEmptyFieldCheck();
    ui->registerWidget_2->setWindowTitle("User Registeration - QuizMania");
}

std::string MainWindow::oneTimePasswordGenerator() {
    std::srand(std::time(0));
    int otptemp = std::rand() % 1000000;
    otp = std::to_string(otptemp);
    while (otp.length() < 6) {
        otp = "0" + otp;
    }
    return otp;
}


void MainWindow::resendTimer() {
    // If there's a previously running timer, stop it
    if (timer) {
        resendTimerStop();
    }

    ui->resendButton->setDisabled(true);

    // Initialize seconds counter for this new session
    int seconds = 120;
    ui->resendTimer->setText(QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 10).rightJustified(2, '0'));
    // Create a new QTimer instance only if there's no active timer
    if (timer == nullptr) {
        timer = new QTimer(this);

        // Connect the timeout signal to the lambda function
        connect(timer, &QTimer::timeout, this, [this, seconds] () mutable {
            seconds--;  // Decrease the counter by 1
            int minutes = seconds / 60;
            int remainingSeconds = seconds % 60;
            ui->resendTimer->setText(QString::number(minutes) + ":" + QString::number(remainingSeconds, 10).rightJustified(2, '0'));

            if (seconds <= 0) {
                ui->resendButton->setDisabled(false);  // Enable the resend button
                ui->resendTimer->setText("");  // Clear the timer display
                timer->stop();  // Stop the timer
                delete timer;  // Free the memory for the timer
                timer = nullptr;  // Set the timer pointer to null
            }
        });

        // Start the timer with a 1-second interval (1000 ms)
        timer->start(1000);
    }
}


void MainWindow::sendEmailConfirmation() {
    if(m_emailSent) {
        return;
    }

    MimeMessage message;

    EmailAddress sender("aaditya.pyarla1@gmail.com", "QuizMania");
    message.setSender(sender);

    EmailAddress to(m_email, ui->firstName->text() + " " + ui->lastName->text());
    message.addRecipient(to);

    message.setSubject("Verify Your Account - QuizMania");
    otp = oneTimePasswordGenerator();
    std::string emailBody =
        "<html>"
        "<head>"
        "<style>"
        "body {"
        "    font-family: Arial, sans-serif;"
        "    margin: 0;"
        "    padding: 0;"
        "    background-color: #f4f4f9;"
        "}"
        ".email-container {"
        "    width: 100%;"
        "    max-width: 600px;"
        "    margin: 0 auto;"
        "    background-color: #ffffff;"
        "    padding: 20px;"
        "    border-radius: 8px;"
        "    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);"
        "}"
        ".email-header {"
        "    text-align: center;"
        "    margin-bottom: 20px;"
        "}"
        ".email-header img {"
        "    max-width: 150px;"
        "}"
        ".email-content {"
        "    font-size: 16px;"
        "    line-height: 1.5;"
        "    color: #333333;"
        "}"
        ".otp-code {"
        "    display: inline-block;"
        "    padding: 10px 20px;"
        "    background-color: #4CAF50;"
        "    color: #ffffff;"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    border-radius: 4px;"
        "    margin: 20px 0;"
        "}"
        ".footer {"
        "    text-align: center;"
        "    font-size: 12px;"
        "    color: #888888;"
        "    margin-top: 30px;"
        "}"
        ".footer a {"
        "    color: #4CAF50;"
        "    text-decoration: none;"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<div class='email-container'>"
        "<div class='email-header'>"
        "<img src='https://img.freepik.com/premium-photo/secure-email-concept-with-padlock-icon_989822-6557.jpg?semt=ais_hybrid' alt='Platform Logo' />"
        "</div>"
        "<div class='email-content'>"
        "<p>Hi there,</p>"
        "<p>Thank you for signing up with QuizMania. To complete your registration, please use the One-Time Password (OTP) below:</p>"
        "<div class='otp-code'>" + otp + "</div>"
                "<p>This OTP is valid for the next 10 minutes. Please enter it on the Desktop App to proceed.</p>"
                "<p>If you didn't request this, please ignore this email.</p>"
                "<p>Thank you, and we look forward to helping you and your child with an enriching educational experience!</p>"
                "</div>"
                "<div class='footer'>"
                "<p>&copy; 2025 QuizMania. All rights reserved.</p>"
                "<p>If you have any questions, visit our <a href='https://github.com/aadityapyarla1983024'>Support Center</a>.</p>"
                "</div>"
                "</div>"
                "</body>"
                "</html>";
    QString emailContent = QString::fromUtf8(emailBody.c_str());
    MimeHtml html;
    html.setHtml(emailContent);
    message.addPart(&html);

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
    }

    smtp.login("aaditya.pyarla1@gmail.com", "pqnv kovn blmv jawy");
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "Failed to login!";
    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";
    }

    smtp.quit();
    m_emailSent = true;
    return;
}

void MainWindow::resendTimerStop() {
    if (timer != nullptr) {
        qDebug() << "Stopping and deleting timer";
        timer->stop();
        disconnect(timer, &QTimer::timeout, this, nullptr); // Disconnect previous connections
        delete timer;
        timer = nullptr;
    } else {
        qDebug() << "Timer was already null";
    }
}

void MainWindow::on_resendButton_clicked()
{
    sendEmailConfirmation();
    resendTimer();
}

void MainWindow::on_emailConfirmCode_textEdited(const QString& otpinput)
{
    if (otpinput.toStdString() != otp) {
        ui->otpValidationMessage->setText("⛔️ Please enter a valid OTP");

    } else {
        ui->stackedWidget->setCurrentIndex(3);
        resendTimerStop();
        ui->resendTimer->setText("");
    }
}

void MainWindow::strongPasswordValidator(std::string& input)
{
    int n = input.length();

    // Checking lower alphabet in string
    // bool hasLower = false, hasUpper = false, hasDigit = false, specialChar = false;
    std::string normalChars = "abcdefghijklmnopqrstu"
                              "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            passwordValidationResult[0] = true;
        if (isupper(input[i]))
            passwordValidationResult[1] = true;
        if (isdigit(input[i]))
            passwordValidationResult[2] = true;

        size_t special = input.find_first_not_of(normalChars);
        if (special != std::string::npos)
            passwordValidationResult[3] = true;
    }
    return;
}


void MainWindow::on_passwordInput1_textEdited(const QString &password)
{
    std::string passwordInput1 = password.toStdString();
    strongPasswordValidator(passwordInput1);

    if(passwordValidationResult[1]) {
        ui->uppercaseLabel->setText("✅ At least 1 uppercase");
    } else {
        ui->uppercaseLabel->setText("⛔️ At least 1 uppercase");
    }
    if(passwordValidationResult[2]) {
        ui->oneNumberLabel->setText("✅ At least 1 number");
    } else {
        ui->oneNumberLabel->setText("⛔️ At least 1 number");
    }
    if(passwordValidationResult[3]) {
        ui->specialCharacterLabel->setText("✅ At least 1 special character (@, #, $, &, !, %)");
    } else {
        ui->specialCharacterLabel->setText("⛔️ At least 1 special character (@, #, $, &, !, %)");
    }
}


void MainWindow::on_passwordInput2_textEdited(const QString &password2)
{
    bool passwordMatch = false;
    if(password2.toStdString() == ui->passwordInput1->text().toStdString()) {
        ui->passwordMatchMessage->setText("✅ Your password match each other");
        passwordMatch = true;
    } else {
        passwordMatch = false;
        ui->passwordMatchMessage->setText("⛔ Your password don't match each other");
    }
    if(passwordValidationResult[0] && passwordValidationResult[1] && passwordValidationResult[2] && passwordValidationResult[3] && passwordMatch) {
        ui->confirmPasswordButton->setDisabled(false);
    } else {
        ui->confirmPasswordButton->setDisabled(true);
    }
}




void MainWindow::on_eyeButton1_clicked()
{
    if(ui->passwordInput1->echoMode() == QLineEdit::Password) {
        ui->passwordInput1->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordInput1->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_eyeButton2_clicked()
{
    if(ui->passwordInput2->echoMode() == QLineEdit::Normal) {
        ui->passwordInput2->setEchoMode(QLineEdit::Password);
    } else {
        ui->passwordInput2->setEchoMode(QLineEdit::Normal);
    }
}


void MainWindow::on_registerLink_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loginLink_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_confirmPasswordButton_clicked()
{
    register_query.bindValue(":first_name", ui->firstName->text());
    register_query.bindValue(":last_name", ui->lastName->text());
    register_query.bindValue(":user_name", ui->username->text());
    register_query.bindValue(":user_email", ui->email->text());

    register_query.bindValue(":user_password_hash", hashPassword(ui->passwordInput1->text()));
    if (!register_query.exec()) {
        QSqlError error = register_query.lastError();
        qDebug() << error.text();
    } else {
        qDebug() << "Registered Successfully";
    }
    ui->stackedWidget->setCurrentIndex(0);
}


QString MainWindow::hashPassword(const QString& password) {
    QByteArray passwordBytes = password.toUtf8();
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(passwordBytes);
    QByteArray hashed = hash.result();
    return hashed.toHex();
}


void MainWindow::on_loginButton_clicked() {
    login_query_username.bindValue(":user_name", ui->loginUsernameEmailInput->text());
    login_query_email.bindValue(":user_email", ui->loginUsernameEmailInput->text());

    bool username_valid = false;
    bool email_valid = false;

    if (login_query_username.exec()) {
        login_query_username.next();
        if (login_query_username.value(0).toString() == hashPassword(ui->loginPasswordInput->text())) {
            username_valid = true;
        }
    }

    if (login_query_email.exec()) {
        login_query_email.next();
        if (login_query_email.value(0).toString() == hashPassword(ui->loginPasswordInput->text())) {
            email_valid = true;
        }
    }

    if (username_valid || email_valid) {
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->loginMessageLabel->setText("⛔ Your entered credentials are invalid");
    }
}