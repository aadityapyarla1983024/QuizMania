/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionewkljfnwef;
    QAction *actionwlkemfm;
    QAction *action_kmf;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *registerWidget_1;
    QFrame *registerFrame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *username;
    QLabel *usernameLabel;
    QLineEdit *email;
    QLabel *registerHeading;
    QHBoxLayout *horizontalLayout;
    QLabel *emailLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *registerIllustration;
    QWidget *registerWidget_2;
    QFrame *emailFrame;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *resendTimer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *resendButton;
    QSpacerItem *verticalSpacer_4;
    QLabel *emailConfirmHeading;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *changeEmailButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *emailConfirmCode;
    QLabel *otpValidationMessage;
    QLabel *emailConfirmIllustration;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1358, 851);
        MainWindow->setMinimumSize(QSize(1246, 783));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 237, 220);\n"
"\n"
""));
        actionewkljfnwef = new QAction(MainWindow);
        actionewkljfnwef->setObjectName("actionewkljfnwef");
        actionwlkemfm = new QAction(MainWindow);
        actionwlkemfm->setObjectName("actionwlkemfm");
        action_kmf = new QAction(MainWindow);
        action_kmf->setObjectName("action_kmf");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");

        horizontalLayout_5->addLayout(horizontalLayout_9);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(1201, 650));
        registerWidget_1 = new QWidget();
        registerWidget_1->setObjectName("registerWidget_1");
        registerFrame = new QFrame(registerWidget_1);
        registerFrame->setObjectName("registerFrame");
        registerFrame->setEnabled(true);
        registerFrame->setGeometry(QRect(100, 70, 1201, 650));
        registerFrame->setMinimumSize(QSize(1201, 650));
        registerFrame->setMaximumSize(QSize(1147, 578));
        registerFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"        background-color: rgb(42, 45, 55);\n"
"        padding: 20px 20px 20px 40px;\n"
"        border-radius: 50px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"        border-bottom: 2px solid gray;\n"
"        background-color: rgb(42, 45, 55);\n"
"        padding: 10px 20px 10px 20px;\n"
"        font-size: 11pt;\n"
"        border-radius: 10px;\n"
"        margin-top: 30px;\n"
"    color: rgb(226, 226, 226);\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"        border-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton {\n"
"        padding: 10px 25px 10px 25px;\n"
"        border: 2px solid gray;\n"
"        border-radius: 10px;\n"
"        background-color: rgb(125, 197, 120);\n"
"        color:#ffffff;\n"
"        font: 600 italic 14pt \"Cascadia Mono\";\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"        background-color: rgb(76, 120, 73);\n"
"        border-radius: 10px;\n"
"\n"
"}\n"
"\n"
"QLabel {\n"
"        padding: 10px 40px 10px 10px;\n"
"    		color: white;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background"
                        "-color: rgb(168, 197, 163);\n"
"}\n"
"\n"
""));
        registerFrame->setFrameShape(QFrame::NoFrame);
        horizontalLayout_2 = new QHBoxLayout(registerFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(horizontalSpacer);

        nextButton = new QPushButton(registerFrame);
        nextButton->setObjectName("nextButton");
        nextButton->setEnabled(false);
        nextButton->setCursor(QCursor(Qt::PointingHandCursor));
        nextButton->setAutoFillBackground(false);

        horizontalLayout_6->addWidget(nextButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_6, 9, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        firstName = new QLineEdit(registerFrame);
        firstName->setObjectName("firstName");

        verticalLayout->addWidget(firstName);

        lastName = new QLineEdit(registerFrame);
        lastName->setObjectName("lastName");

        verticalLayout->addWidget(lastName);

        username = new QLineEdit(registerFrame);
        username->setObjectName("username");

        verticalLayout->addWidget(username);

        usernameLabel = new QLabel(registerFrame);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        email = new QLineEdit(registerFrame);
        email->setObjectName("email");
        email->setStyleSheet(QString::fromUtf8("margin-top: 10px"));

        verticalLayout->addWidget(email);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        registerHeading = new QLabel(registerFrame);
        registerHeading->setObjectName("registerHeading");
        registerHeading->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font: 600 italic 16pt \"Cascadia Mono\";"));

        gridLayout->addWidget(registerHeading, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 11, 0, 1, 1);

        emailLabel = new QLabel(registerFrame);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setEnabled(true);
        emailLabel->setAutoFillBackground(false);
        emailLabel->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(emailLabel, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 10, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        registerIllustration = new QLabel(registerFrame);
        registerIllustration->setObjectName("registerIllustration");
        registerIllustration->setMinimumSize(QSize(580, 500));
        registerIllustration->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"margin-left: 50px;\n"
""));
        registerIllustration->setPixmap(QPixmap(QString::fromUtf8(":/UserValidation/media/rb_7853.png")));
        registerIllustration->setScaledContents(true);
        registerIllustration->setWordWrap(false);

        horizontalLayout_3->addWidget(registerIllustration);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 3);

        horizontalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(registerWidget_1);
        registerWidget_2 = new QWidget();
        registerWidget_2->setObjectName("registerWidget_2");
        emailFrame = new QFrame(registerWidget_2);
        emailFrame->setObjectName("emailFrame");
        emailFrame->setEnabled(true);
        emailFrame->setGeometry(QRect(80, 70, 1201, 650));
        emailFrame->setMinimumSize(QSize(1201, 650));
        emailFrame->setMaximumSize(QSize(1201, 650));
        emailFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"        background-color: rgb(42, 45, 55);\n"
"        padding: 20px 20px 20px 40px;\n"
"        border-radius: 50px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"        border-bottom: 2px solid gray;\n"
"        background-color: rgb(42, 45, 55);\n"
"        padding: 10px 20px 10px 20px;\n"
"        font-size: 11pt;\n"
"        border-radius: 10px;\n"
"        margin-top: 30px;\n"
"    		color: rgb(226, 226, 226);\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"        border-color: #ffffff;\n"
"}\n"
"\n"
"#otpValidationMessage{\n"
"		font: 100 10pt;\n"
"color: rgb(226, 226, 226);\n"
"}\n"
"\n"
"QPushButton {\n"
"        padding: 10px 25px 10px 25px;\n"
"        border: 2px solid gray;\n"
"        border-radius: 10px;\n"
"        background-color: rgb(125, 197, 120);\n"
"        color:#ffffff;\n"
"        font: 600 italic 14pt \"Cascadia Mono\";\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"        background-color: rgb(76, 120, 73);\n"
"        border-radius: 10px;\n"
"}\n"
"\n"
"#resendButton {\n"
"	background-color: transpar"
                        "ent;\n"
"	border: transparent;\n"
"	font: 500 10pt;\n"
"	padding: 0px 15px 0px 0px;\n"
"}\n"
"\n"
"#resendButton:disabled {\n"
"	color: rgb(147, 147, 147)\n"
"}\n"
"\n"
"#resendButton:hover {\n"
"	text-decoration: underline;\n"
"}\n"
"\n"
"QLabel {\n"
"        padding: 10px 40px 10px 10px;\n"
"   		color: white;\n"
"		font: 600 11pt \"Fira Code SemiBold\";\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        background-color: rgb(168, 197, 163);\n"
"}\n"
"\n"
"#resendtimer {\n"
"	 color: rgb(147, 147, 147)\n"
"}\n"
"\n"
"\n"
""));
        emailFrame->setFrameShape(QFrame::NoFrame);
        horizontalLayout_4 = new QHBoxLayout(emailFrame);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, -1, -1, -1);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        resendTimer = new QLabel(emailFrame);
        resendTimer->setObjectName("resendTimer");

        horizontalLayout_8->addWidget(resendTimer);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        resendButton = new QPushButton(emailFrame);
        resendButton->setObjectName("resendButton");
        resendButton->setEnabled(false);
        resendButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_8->addWidget(resendButton);


        gridLayout_2->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 6, 0, 1, 1);

        emailConfirmHeading = new QLabel(emailFrame);
        emailConfirmHeading->setObjectName("emailConfirmHeading");
        emailConfirmHeading->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font: 600 italic 16pt \"Cascadia Mono\";"));
        emailConfirmHeading->setWordWrap(true);

        gridLayout_2->addWidget(emailConfirmHeading, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        gridLayout_2->addLayout(verticalLayout_2, 9, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 8, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        changeEmailButton = new QPushButton(emailFrame);
        changeEmailButton->setObjectName("changeEmailButton");
        changeEmailButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_10->addWidget(changeEmailButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_10, 7, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 0, 1, 1);

        emailConfirmCode = new QLineEdit(emailFrame);
        emailConfirmCode->setObjectName("emailConfirmCode");
        emailConfirmCode->setMaxLength(6);
        emailConfirmCode->setClearButtonEnabled(true);

        gridLayout_2->addWidget(emailConfirmCode, 3, 0, 1, 1);

        otpValidationMessage = new QLabel(emailFrame);
        otpValidationMessage->setObjectName("otpValidationMessage");

        gridLayout_2->addWidget(otpValidationMessage, 4, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_2);

        emailConfirmIllustration = new QLabel(emailFrame);
        emailConfirmIllustration->setObjectName("emailConfirmIllustration");
        emailConfirmIllustration->setMinimumSize(QSize(580, 500));
        emailConfirmIllustration->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"margin-left: 50px;\n"
""));
        emailConfirmIllustration->setPixmap(QPixmap(QString::fromUtf8(":/UserValidation/media/rb_21298.png")));
        emailConfirmIllustration->setScaledContents(true);
        emailConfirmIllustration->setWordWrap(false);

        horizontalLayout_7->addWidget(emailConfirmIllustration);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 3);

        horizontalLayout_4->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(registerWidget_2);

        horizontalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionewkljfnwef->setText(QCoreApplication::translate("MainWindow", "ewkljfnwef''", nullptr));
        actionwlkemfm->setText(QCoreApplication::translate("MainWindow", "wlkemfm", nullptr));
        action_kmf->setText(QCoreApplication::translate("MainWindow", ";kmf", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next \342\217\255\357\270\217", nullptr));
        firstName->setPlaceholderText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Your username is already taken.", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        registerHeading->setText(QCoreApplication::translate("MainWindow", "Join our Community !", nullptr));
        emailLabel->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Please enter a valid email.", nullptr));
        registerIllustration->setText(QString());
        resendTimer->setText(QString());
        resendButton->setText(QCoreApplication::translate("MainWindow", "Resend", nullptr));
        emailConfirmHeading->setText(QCoreApplication::translate("MainWindow", "Please check your inbox for confirmation !", nullptr));
        changeEmailButton->setText(QCoreApplication::translate("MainWindow", "Change Email", nullptr));
        emailConfirmCode->setInputMask(QString());
        emailConfirmCode->setPlaceholderText(QCoreApplication::translate("MainWindow", "6-Digit Code", nullptr));
        otpValidationMessage->setText(QString());
        emailConfirmIllustration->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
