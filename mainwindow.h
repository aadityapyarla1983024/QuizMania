#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>

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

public slots:

signals:
    void noEmptyField(void);

private slots:
    void on_email_textEdited(const QString &arg1);

    void on_firstName_textEdited();

    void on_lastName_textEdited();

    void noEmptyFieldCheck();

    void on_username_textEdited();

    void on_nextButton_clicked();

    void on_changeEmailButton_clicked();

private:
    Ui::MainWindow *ui;

    bool isEmailValid(const std::string& email);
    bool m_emailValid = false;
    bool m_firstName = false;
    bool m_lastName = false;
    bool m_userName = false;
};
#endif // MAINWINDOW_H
