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
    QLabel *registerHeading;
    QVBoxLayout *verticalLayout;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *username;
    QLabel *usernameLabel;
    QLineEdit *email;
    QSpacerItem *verticalSpacer;
    QLabel *emailLabel;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginLink;
    QLabel *registerIllustration;
    QWidget *registerWidget_2;
    QFrame *emailFrame;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *emailConfirmHeading;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *emailConfirmCode;
    QLabel *otpValidationMessage;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *changeEmailButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *resendTimer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *resendButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *recieveEmailLabel;
    QLabel *emailConfirmIllustration;
    QWidget *registerWidget_3;
    QFrame *passwordFrame_3;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *ConfirmPasswordIllustration;
    QGridLayout *gridLayout_3;
    QLabel *createPasswordHeader;
    QLabel *eightCharacterLabel;
    QLabel *uppercaseLabel;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *confirmPasswordButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *passwordInput1;
    QLineEdit *passwordInput2;
    QLabel *passwordMatchMessage;
    QLabel *specialCharacterLabel;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *oneNumberLabel;

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
"#loginLink {\n"
"\n"
"	background-color: transparent;\n"
"	border: transparent;\n"
"	font: 500 10pt;\n"
"	padding: 0px 15px 0px 0px;\n"
"	margin-top: 10px\n"
"\n"
"}\n"
"\n"
"#loginLink:hover {\n"
"	text-decoration: underline;\n"
"}\n"
"\n"
"\n"
"\n"
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
""
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
"        background-color: rgb(168, 197, 163);\n"
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
        registerHeading = new QLabel(registerFrame);
        registerHeading->setObjectName("registerHeading");
        registerHeading->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font: 600 italic 16pt \"Cascadia Mono\";"));

        gridLayout->addWidget(registerHeading, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        emailLabel = new QLabel(registerFrame);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setEnabled(true);
        emailLabel->setAutoFillBackground(false);
        emailLabel->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(emailLabel, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        nextButton = new QPushButton(registerFrame);
        nextButton->setObjectName("nextButton");
        nextButton->setEnabled(false);
        nextButton->setCursor(QCursor(Qt::PointingHandCursor));
        nextButton->setAutoFillBackground(false);

        horizontalLayout_6->addWidget(nextButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_6, 9, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 11, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 12, 0, 1, 1);

        loginLink = new QPushButton(registerFrame);
        loginLink->setObjectName("loginLink");
        loginLink->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(loginLink, 10, 0, 1, 1);


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
        emailConfirmHeading = new QLabel(emailFrame);
        emailConfirmHeading->setObjectName("emailConfirmHeading");
        emailConfirmHeading->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font: 600 italic 16pt \"Cascadia Mono\";"));
        emailConfirmHeading->setWordWrap(true);

        gridLayout_2->addWidget(emailConfirmHeading, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);

        emailConfirmCode = new QLineEdit(emailFrame);
        emailConfirmCode->setObjectName("emailConfirmCode");
        emailConfirmCode->setMaxLength(6);
        emailConfirmCode->setClearButtonEnabled(true);

        gridLayout_2->addWidget(emailConfirmCode, 4, 0, 1, 1);

        otpValidationMessage = new QLabel(emailFrame);
        otpValidationMessage->setObjectName("otpValidationMessage");

        gridLayout_2->addWidget(otpValidationMessage, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 9, 0, 1, 1);

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


        gridLayout_2->addLayout(horizontalLayout_10, 8, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 0, 1, 1);

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


        gridLayout_2->addLayout(horizontalLayout_8, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 7, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        gridLayout_2->addLayout(verticalLayout_2, 10, 0, 1, 1);

        recieveEmailLabel = new QLabel(emailFrame);
        recieveEmailLabel->setObjectName("recieveEmailLabel");

        gridLayout_2->addWidget(recieveEmailLabel, 3, 0, 1, 1);


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
        registerWidget_3 = new QWidget();
        registerWidget_3->setObjectName("registerWidget_3");
        passwordFrame_3 = new QFrame(registerWidget_3);
        passwordFrame_3->setObjectName("passwordFrame_3");
        passwordFrame_3->setEnabled(true);
        passwordFrame_3->setGeometry(QRect(40, 90, 1201, 650));
        passwordFrame_3->setMinimumSize(QSize(1201, 650));
        passwordFrame_3->setMaximumSize(QSize(1147, 578));
        passwordFrame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
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
        passwordFrame_3->setFrameShape(QFrame::NoFrame);
        horizontalLayout_11 = new QHBoxLayout(passwordFrame_3);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        ConfirmPasswordIllustration = new QLabel(passwordFrame_3);
        ConfirmPasswordIllustration->setObjectName("ConfirmPasswordIllustration");
        ConfirmPasswordIllustration->setMinimumSize(QSize(580, 500));
        ConfirmPasswordIllustration->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"margin-right: 40px;\n"
""));
        ConfirmPasswordIllustration->setPixmap(QPixmap(QString::fromUtf8(":/UserValidation/media/rb_4685.png")));
        ConfirmPasswordIllustration->setScaledContents(true);
        ConfirmPasswordIllustration->setWordWrap(false);

        horizontalLayout_12->addWidget(ConfirmPasswordIllustration);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, -1, -1, -1);
        createPasswordHeader = new QLabel(passwordFrame_3);
        createPasswordHeader->setObjectName("createPasswordHeader");
        createPasswordHeader->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font: 600 italic 16pt \"Cascadia Mono\";"));

        gridLayout_3->addWidget(createPasswordHeader, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        eightCharacterLabel = new QLabel(passwordFrame_3);
        eightCharacterLabel->setObjectName("eightCharacterLabel");

        gridLayout_3->addWidget(eightCharacterLabel, 6, 0, 1, 1);

        uppercaseLabel = new QLabel(passwordFrame_3);
        uppercaseLabel->setObjectName("uppercaseLabel");

        gridLayout_3->addWidget(uppercaseLabel, 4, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        confirmPasswordButton = new QPushButton(passwordFrame_3);
        confirmPasswordButton->setObjectName("confirmPasswordButton");
        confirmPasswordButton->setEnabled(false);
        confirmPasswordButton->setCursor(QCursor(Qt::PointingHandCursor));
        confirmPasswordButton->setAutoFillBackground(false);

        horizontalLayout_13->addWidget(confirmPasswordButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);


        gridLayout_3->addLayout(horizontalLayout_13, 13, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_9);

        passwordInput1 = new QLineEdit(passwordFrame_3);
        passwordInput1->setObjectName("passwordInput1");

        verticalLayout_3->addWidget(passwordInput1);

        passwordInput2 = new QLineEdit(passwordFrame_3);
        passwordInput2->setObjectName("passwordInput2");

        verticalLayout_3->addWidget(passwordInput2);

        passwordMatchMessage = new QLabel(passwordFrame_3);
        passwordMatchMessage->setObjectName("passwordMatchMessage");

        verticalLayout_3->addWidget(passwordMatchMessage);

        specialCharacterLabel = new QLabel(passwordFrame_3);
        specialCharacterLabel->setObjectName("specialCharacterLabel");

        verticalLayout_3->addWidget(specialCharacterLabel);


        gridLayout_3->addLayout(verticalLayout_3, 2, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_8, 14, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");

        gridLayout_3->addLayout(horizontalLayout_14, 15, 0, 1, 1);

        oneNumberLabel = new QLabel(passwordFrame_3);
        oneNumberLabel->setObjectName("oneNumberLabel");

        gridLayout_3->addWidget(oneNumberLabel, 3, 0, 1, 1);


        horizontalLayout_12->addLayout(gridLayout_3);

        horizontalLayout_12->setStretch(0, 3);
        horizontalLayout_12->setStretch(1, 2);

        horizontalLayout_11->addLayout(horizontalLayout_12);

        stackedWidget->addWidget(registerWidget_3);

        horizontalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(confirmPasswordButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionewkljfnwef->setText(QCoreApplication::translate("MainWindow", "ewkljfnwef''", nullptr));
        actionwlkemfm->setText(QCoreApplication::translate("MainWindow", "wlkemfm", nullptr));
        action_kmf->setText(QCoreApplication::translate("MainWindow", ";kmf", nullptr));
        registerHeading->setText(QCoreApplication::translate("MainWindow", "Join our Community !", nullptr));
        firstName->setPlaceholderText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        usernameLabel->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        emailLabel->setText(QString());
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next \342\236\241\357\270\217", nullptr));
        loginLink->setText(QCoreApplication::translate("MainWindow", "Already have an account?", nullptr));
        registerIllustration->setText(QString());
        emailConfirmHeading->setText(QCoreApplication::translate("MainWindow", "Please check your inbox for confirmation !", nullptr));
        emailConfirmCode->setInputMask(QString());
        emailConfirmCode->setPlaceholderText(QCoreApplication::translate("MainWindow", "6-Digit Code", nullptr));
        otpValidationMessage->setText(QString());
        changeEmailButton->setText(QCoreApplication::translate("MainWindow", "Change Email", nullptr));
        resendTimer->setText(QString());
        resendButton->setText(QCoreApplication::translate("MainWindow", "Resend", nullptr));
        recieveEmailLabel->setText(QString());
        emailConfirmIllustration->setText(QString());
        ConfirmPasswordIllustration->setText(QString());
        createPasswordHeader->setText(QCoreApplication::translate("MainWindow", "Create a Secure Password", nullptr));
        eightCharacterLabel->setText(QString());
        uppercaseLabel->setText(QString());
        confirmPasswordButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        passwordInput1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        passwordInput2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Re-enter Password", nullptr));
        passwordMatchMessage->setText(QString());
        specialCharacterLabel->setText(QString());
        oneNumberLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
