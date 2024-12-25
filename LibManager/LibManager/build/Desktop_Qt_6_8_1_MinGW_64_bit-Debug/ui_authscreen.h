/********************************************************************************
** Form generated from reading UI file 'authscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHSCREEN_H
#define UI_AUTHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthScreen
{
public:
    QWidget *centralwidget;
    QLabel *AuthScreen1;
    QLabel *SignIn_text;
    QLineEdit *UsernameLineEdit;
    QLabel *Username_text;
    QLineEdit *PasswordLineEdit;
    QLabel *Password_text;
    QPushButton *signinButton;
    QLabel *LibManager_logo;
    QLabel *welcome_text;
    QLabel *AuthScreen1_2;
    QPushButton *signupButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMainWindow *AuthScreen)
    {
        if (AuthScreen->objectName().isEmpty())
            AuthScreen->setObjectName("AuthScreen");
        AuthScreen->resize(854, 480);
        AuthScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 38, 38);"));
        centralwidget = new QWidget(AuthScreen);
        centralwidget->setObjectName("centralwidget");
        AuthScreen1 = new QLabel(centralwidget);
        AuthScreen1->setObjectName("AuthScreen1");
        AuthScreen1->setGeometry(QRect(0, 0, 427, 480));
        AuthScreen1->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        SignIn_text = new QLabel(centralwidget);
        SignIn_text->setObjectName("SignIn_text");
        SignIn_text->setGeometry(QRect(40, 40, 171, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(22);
        font.setWeight(QFont::Light);
        font.setItalic(false);
        SignIn_text->setFont(font);
        SignIn_text->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 300 22pt \"Calibri\";\n"
"background-color: transparent;"));
        UsernameLineEdit = new QLineEdit(centralwidget);
        UsernameLineEdit->setObjectName("UsernameLineEdit");
        UsernameLineEdit->setGeometry(QRect(40, 160, 341, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        UsernameLineEdit->setFont(font1);
        UsernameLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(214, 214, 214);\n"
"	border-radius: 15px;\n"
"	color: black; \n"
"    font-size: 16px;\n"
"    padding-left: 6px; \n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"	color: rgb(141,141,141); \n"
"    font-style: italic; \n"
"}"));
        Username_text = new QLabel(centralwidget);
        Username_text->setObjectName("Username_text");
        Username_text->setGeometry(QRect(50, 130, 111, 20));
        Username_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        PasswordLineEdit->setGeometry(QRect(40, 250, 341, 41));
        PasswordLineEdit->setFont(font1);
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(214, 214, 214);\n"
"	border-radius: 15px;\n"
"	color: black; \n"
"    font-size: 16px;\n"
"    padding-left: 10px; \n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"	color: rgb(141,141,141); \n"
"    font-style: italic; \n"
"}"));
        PasswordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        Password_text = new QLabel(centralwidget);
        Password_text->setObjectName("Password_text");
        Password_text->setGeometry(QRect(50, 220, 111, 20));
        Password_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        signinButton = new QPushButton(centralwidget);
        signinButton->setObjectName("signinButton");
        signinButton->setGeometry(QRect(40, 330, 341, 41));
        signinButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"		\n"
"	background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(90, 191, 47, 255), stop:1 rgba(13, 134, 0, 255));\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(136, 202, 129);\n"
"}"));
        LibManager_logo = new QLabel(centralwidget);
        LibManager_logo->setObjectName("LibManager_logo");
        LibManager_logo->setGeometry(QRect(465, 70, 349, 91));
        LibManager_logo->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/LibManager_logo_revised.png);\n"
"background-color:transparent;"));
        welcome_text = new QLabel(centralwidget);
        welcome_text->setObjectName("welcome_text");
        welcome_text->setGeometry(QRect(484, 170, 312, 41));
        welcome_text->setStyleSheet(QString::fromUtf8("font: 18pt \"Calibri\";\n"
"color:white;\n"
"background-color:transparent;"));
        welcome_text->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AuthScreen1_2 = new QLabel(centralwidget);
        AuthScreen1_2->setObjectName("AuthScreen1_2");
        AuthScreen1_2->setGeometry(QRect(427, 0, 428, 480));
        AuthScreen1_2->setStyleSheet(QString::fromUtf8("background-image:url(C:/LibManager/LibManager/LBResources/authScreen_imageV2.png)"));
        signupButton = new QPushButton(centralwidget);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(40, 390, 341, 41));
        signupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"		\n"
"	background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(90, 191, 47, 255), stop:1 rgba(13, 134, 0, 255));\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(136, 202, 129);\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(460, 240, 361, 21));
        label_4->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(497, 280, 291, 21));
        label_5->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(525, 320, 231, 21));
        label_6->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AuthScreen->setCentralWidget(centralwidget);
        AuthScreen1_2->raise();
        AuthScreen1->raise();
        SignIn_text->raise();
        UsernameLineEdit->raise();
        Username_text->raise();
        PasswordLineEdit->raise();
        Password_text->raise();
        signinButton->raise();
        welcome_text->raise();
        signupButton->raise();
        LibManager_logo->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(AuthScreen);

        QMetaObject::connectSlotsByName(AuthScreen);
    } // setupUi

    void retranslateUi(QMainWindow *AuthScreen)
    {
        AuthScreen->setWindowTitle(QCoreApplication::translate("AuthScreen", "AuthScreen", nullptr));
        AuthScreen1->setText(QString());
        SignIn_text->setText(QCoreApplication::translate("AuthScreen", "<html><head/><body><p><span style=\" font-size:26pt;\">Sign In</span></p></body></html>", nullptr));
        UsernameLineEdit->setText(QString());
        UsernameLineEdit->setPlaceholderText(QCoreApplication::translate("AuthScreen", "Username", nullptr));
        Username_text->setText(QCoreApplication::translate("AuthScreen", "USERNAME:", nullptr));
        PasswordLineEdit->setText(QString());
        PasswordLineEdit->setPlaceholderText(QCoreApplication::translate("AuthScreen", "Password", nullptr));
        Password_text->setText(QCoreApplication::translate("AuthScreen", "PASSWORD:", nullptr));
        signinButton->setText(QCoreApplication::translate("AuthScreen", "Sign in", nullptr));
        LibManager_logo->setText(QString());
        welcome_text->setText(QCoreApplication::translate("AuthScreen", "Welcome to LibManager!", nullptr));
        AuthScreen1_2->setText(QString());
        signupButton->setText(QCoreApplication::translate("AuthScreen", "Sign up", nullptr));
        label_4->setText(QCoreApplication::translate("AuthScreen", "Organize, track, and optimize your library effortlessly.", nullptr));
        label_5->setText(QCoreApplication::translate("AuthScreen", "Create, edit, and maintain records of books.", nullptr));
        label_6->setText(QCoreApplication::translate("AuthScreen", "Login to get started LibManager!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthScreen: public Ui_AuthScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHSCREEN_H
