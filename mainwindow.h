#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qsqlquery.h>
#include <string>
#include <QMainWindow>
#include <SmtpMime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSet>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void db_connect();
    void db_init_queries();

signals:
    void noEmptyField(void);
    void resendTimerFinished(void);

private slots:
    void on_email_textEdited(const QString &arg1);

    void on_firstName_textEdited();

    void on_lastName_textEdited();

    void noEmptyFieldCheck();

    void on_username_textEdited(const QString &username);

    void on_nextButton_clicked();

    void on_changeEmailButton_clicked();

    void on_resendButton_clicked();

    void on_resendTimerFinished_emmited();

    void on_emailConfirmCode_textEdited(const QString &arg1);

    void on_passwordInput1_textEdited(const QString &arg1);

    void on_passwordInput2_textEdited(const QString &arg1);

    void on_eyeButton1_clicked();

    void on_eyeButton2_clicked();

    void on_registerLink_clicked();

    void on_loginLink_clicked();

    void on_confirmPasswordButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer = nullptr;
    bool isEmailValid(const std::string& email);
    void strongPasswordValidator(std::string& input);
    QString m_email;
    std::array<bool, 5> passwordValidationResult = { false, false, false, false, false };
    bool m_emailSent = false;
    void resendTimerStop();
    bool m_emailValid = false;
    bool m_firstName = false;
    QString hashPassword(const QString& password);
    bool m_lastName = false;
    bool m_userName = false;
    std::string otp;
    void sendEmailConfirmation();
    void resendTimer();
    std::string oneTimePasswordGenerator();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQuery register_query;
    QSqlQuery login_query_username;
    QSqlQuery login_query_email;
    QSqlQuery db_fetch_query;
    QSet<QString> existingUsernames;
    QSet<QString> existsingEmails;
};
#endif // MAINWINDOW_H
