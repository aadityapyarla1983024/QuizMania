#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credentials.h"
#include <SmtpMime>
#include <QTimer>

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

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


void MainWindow::sendEmailConfirmation() {
    if(m_emailSent) {
        return;
    }

    MimeMessage message;

    EmailAddress sender(EMAIL_SENDER, "QuizMania");
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

    SmtpClient smtp(SMTP_HOST, SMTP_PORT, SmtpClient::SslConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
    }

    smtp.login(EMAIL_SENDER, EMAIL_PASSWORD);
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