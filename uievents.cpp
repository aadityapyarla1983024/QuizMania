#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>


void MainWindow::on_resendButton_clicked()
{
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
    if(passwordValidationResult[4]) {
        ui->eightCharacterLabel->setText("✅ At least 8 character long");
    } else {
        ui->eightCharacterLabel->setText("⛔️ At least 8 character long");
    }
}


void MainWindow::on_passwordInput2_textEdited(const QString &password2)
{
    bool passwordMatch = false;
    if((password2.toStdString() == ui->passwordInput1->text().toStdString()) && (password2 != "")) {
        ui->passwordMatchMessage->setText("✅ Your password match each other");
        passwordMatch = true;
    } else {
        passwordMatch = false;
        ui->passwordMatchMessage->setText("⛔ Your password don't match each other");
    }
    if(passwordValidationResult[0] && passwordValidationResult[1] && passwordValidationResult[2] && passwordValidationResult[3] && passwordValidationResult[4] && passwordMatch) {
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
    db_fetch_query.exec("SELECT user_name, user_email FROM users") ? qDebug() << "Fetched database successfully" :
        qDebug() << "Error while fetching database";
    ui->stackedWidget->setCurrentIndex(0);
}

