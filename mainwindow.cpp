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



std::string MainWindow::oneTimePasswordGenerator() {
    std::srand(std::time(0));
    int otptemp = std::rand() % 1000000;
    otp = std::to_string(otptemp);
    while (otp.length() < 6) {
        otp = "0" + otp;
    }
    return otp;
}

void MainWindow::strongPasswordValidator(std::string& input)
{
    int n = input.length();
    if (n >= 8) {
        passwordValidationResult[4] = true;
    }

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



QString MainWindow::hashPassword(const QString& password) {
    QByteArray passwordBytes = password.toUtf8();
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(passwordBytes);
    QByteArray hashed = hash.result();
    return hashed.toHex();
}


