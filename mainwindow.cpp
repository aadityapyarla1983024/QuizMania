#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <regex>
#include <string>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(noEmptyField()), this, SLOT(noEmptyFieldCheck()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(on_email_textEdited(QString)));
    connect(ui->firstName, SIGNAL(textEdited()), this, SLOT(on_firstName_textEdited()));
    connect(ui->lastName, SIGNAL(textEdited()), this, SLOT(on_lastName_textEdited()));
    connect(ui->username, SIGNAL(textEdited()), this, SLOT(on_username_textEdited()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
    connect(ui->changeEmailButton, SIGNAL(clicked()), this, SLOT(on_changeEmailButton_clicked()));

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


void MainWindow::on_username_textEdited()
{
    if (ui->username->text().isEmpty()) {
        ui->usernameLabel->setText("⚠️ You have entered a invalid username.");
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
}

void MainWindow::on_changeEmailButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->emailConfirmCode->clear();
    ui->email->clear();
    ui->email->setFocus();
    m_emailValid = false;
    emit noEmptyFieldCheck();
    ui->registerWidget_2->setWindowTitle("User Registeration - QuizMania");
}

