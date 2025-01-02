#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <regex>
#include <string>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <SmtpMime>
#include <QString>
#include <thread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(noEmptyField()), this, SLOT(noEmptyFieldCheck()));
    connect(this, SIGNAL(resendTimerFinished()), this, SLOT(on_resendTimerFinished_emmited()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(on_email_textEdited(QString)));
    connect(ui->firstName, SIGNAL(textEdited()), this, SLOT(on_firstName_textEdited()));
    connect(ui->lastName, SIGNAL(textEdited()), this, SLOT(on_lastName_textEdited()));
    connect(ui->username, SIGNAL(textEdited()), this, SLOT(on_username_textEdited()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
    connect(ui->changeEmailButton, SIGNAL(clicked()), this, SLOT(on_changeEmailButton_clicked()));
    connect(ui->resendButton, SIGNAL(clicked()), this, SLOT(on_resendButton_clicked()));
    connect(ui->emailConfirmCode, SIGNAL(textEdited(QString)), this, SLOT(on_emailConfirmCode_textEdited(QString)));

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
        ui->emailLabel->setText("✅ You have entered a valid email.");
        m_emailValid = true;

    } else {
        ui->emailLabel->setText("⚠️ Please enter a valid email.");
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


void MainWindow::on_username_textEdited() {
    if (ui->username->text().isEmpty()) {
        ui->usernameLabel->setText("⚠ You have entered a invalid username.");
        m_userName = false;

    } else {
        ui->usernameLabel->setText("✅ You have entered a valid username.");
        m_userName = true;
    }
    emit noEmptyFieldCheck();
}


void MainWindow::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    m_email = ui->email->text();
    sendEmailConfirmation();
    resendTimer();
}

void MainWindow::on_changeEmailButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->resendTimer->setText(QString::number(seconds / 60) + ":" + QString::number(seconds % 60));

    // Create a new QTimer instance only if there's no active timer
    if (timer == nullptr) {
        timer = new QTimer(this);

        // Connect the timeout signal to the lambda function
        connect(timer, &QTimer::timeout, this, [this, seconds] () mutable {
            seconds--;  // Decrease the counter by 1
            ui->resendTimer->setText(QString::number(seconds / 60) + ":" + QString::number(seconds % 60));

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
        ui->otpValidationMessage->setText("Please enter a valid OTP");

    } else {
        ui->otpValidationMessage->setText("Done");
        resendTimerStop();
        ui->resendTimer->setText("");
    }
}

