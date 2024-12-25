/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *SignUp_text;
    QLabel *Username_text;
    QLineEdit *UsernameLineEdit;
    QPushButton *Back_Button;
    QLabel *Password_text;
    QLineEdit *Password_Line_Edit;
    QLabel *Mail_text;
    QLineEdit *Mail_Line_Edit;
    QLabel *SignUpScreen_2;
    QLabel *AuthScreen1_2;
    QLabel *LibManager_logo;
    QPushButton *signupButton;
    QPushButton *user_Button;
    QPushButton *admin_Button;
    QLabel *welcome_text;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(854, 480);
        SignUp->setStyleSheet(QString::fromUtf8("background-color:white"));
        SignUp_text = new QLabel(SignUp);
        SignUp_text->setObjectName("SignUp_text");
        SignUp_text->setGeometry(QRect(40, 30, 171, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(22);
        font.setWeight(QFont::Light);
        font.setItalic(false);
        SignUp_text->setFont(font);
        SignUp_text->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 300 22pt \"Calibri\";\n"
"background-color: transparent;"));
        Username_text = new QLabel(SignUp);
        Username_text->setObjectName("Username_text");
        Username_text->setGeometry(QRect(50, 235, 111, 20));
        Username_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        UsernameLineEdit = new QLineEdit(SignUp);
        UsernameLineEdit->setObjectName("UsernameLineEdit");
        UsernameLineEdit->setGeometry(QRect(40, 260, 341, 41));
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
        Back_Button = new QPushButton(SignUp);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(300, 20, 101, 41));
        Back_Button->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        Back_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        Password_text = new QLabel(SignUp);
        Password_text->setObjectName("Password_text");
        Password_text->setGeometry(QRect(50, 316, 111, 20));
        Password_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Password_Line_Edit = new QLineEdit(SignUp);
        Password_Line_Edit->setObjectName("Password_Line_Edit");
        Password_Line_Edit->setGeometry(QRect(40, 340, 341, 41));
        Password_Line_Edit->setFont(font1);
        Password_Line_Edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(214, 214, 214);\n"
"	border-radius: 15px;\n"
"	color: black; \n"
"    font-size: 13px;\n"
"    padding-left: 6px; \n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"	color: rgb(141,141,141); \n"
"    font-style: italic; \n"
"}"));
        Password_Line_Edit->setEchoMode(QLineEdit::EchoMode::Password);
        Mail_text = new QLabel(SignUp);
        Mail_text->setObjectName("Mail_text");
        Mail_text->setGeometry(QRect(50, 155, 111, 20));
        Mail_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Mail_Line_Edit = new QLineEdit(SignUp);
        Mail_Line_Edit->setObjectName("Mail_Line_Edit");
        Mail_Line_Edit->setGeometry(QRect(40, 180, 341, 41));
        Mail_Line_Edit->setFont(font1);
        Mail_Line_Edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        SignUpScreen_2 = new QLabel(SignUp);
        SignUpScreen_2->setObjectName("SignUpScreen_2");
        SignUpScreen_2->setGeometry(QRect(0, 0, 427, 480));
        SignUpScreen_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        AuthScreen1_2 = new QLabel(SignUp);
        AuthScreen1_2->setObjectName("AuthScreen1_2");
        AuthScreen1_2->setGeometry(QRect(427, 0, 428, 480));
        AuthScreen1_2->setStyleSheet(QString::fromUtf8("background-image:url(C:/LibManager/LibManager/LBResources/authScreen_imageV2.png)"));
        LibManager_logo = new QLabel(SignUp);
        LibManager_logo->setObjectName("LibManager_logo");
        LibManager_logo->setGeometry(QRect(465, 70, 349, 91));
        LibManager_logo->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/LibManager_logo_revised.png);\n"
"background-color:transparent;"));
        signupButton = new QPushButton(SignUp);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(40, 400, 341, 41));
        signupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        user_Button = new QPushButton(SignUp);
        user_Button->setObjectName("user_Button");
        user_Button->setGeometry(QRect(40, 100, 101, 41));
        user_Button->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        user_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        admin_Button = new QPushButton(SignUp);
        admin_Button->setObjectName("admin_Button");
        admin_Button->setGeometry(QRect(170, 100, 101, 41));
        admin_Button->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        admin_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        welcome_text = new QLabel(SignUp);
        welcome_text->setObjectName("welcome_text");
        welcome_text->setGeometry(QRect(484, 170, 312, 41));
        welcome_text->setStyleSheet(QString::fromUtf8("font: 18pt \"Calibri\";\n"
"color: white;\n"
"background-color:transparent;"));
        welcome_text->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 240, 361, 21));
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(SignUp);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(497, 280, 291, 21));
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(SignUp);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(525, 320, 231, 21));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: white;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AuthScreen1_2->raise();
        SignUpScreen_2->raise();
        SignUp_text->raise();
        Username_text->raise();
        UsernameLineEdit->raise();
        Back_Button->raise();
        Password_text->raise();
        Password_Line_Edit->raise();
        Mail_text->raise();
        Mail_Line_Edit->raise();
        LibManager_logo->raise();
        signupButton->raise();
        user_Button->raise();
        admin_Button->raise();
        welcome_text->raise();
        label->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "LibManager", nullptr));
        SignUp_text->setText(QCoreApplication::translate("SignUp", "<html><head/><body><p><span style=\" font-size:26pt;\">Sign Up</span></p></body></html>", nullptr));
        Username_text->setText(QCoreApplication::translate("SignUp", "Username:", nullptr));
        UsernameLineEdit->setText(QString());
        UsernameLineEdit->setPlaceholderText(QCoreApplication::translate("SignUp", "Choose a username", nullptr));
        Back_Button->setText(QCoreApplication::translate("SignUp", "Back", nullptr));
        Password_text->setText(QCoreApplication::translate("SignUp", "Password:", nullptr));
        Password_Line_Edit->setText(QString());
        Password_Line_Edit->setPlaceholderText(QCoreApplication::translate("SignUp", "Please set a password of at least 8 characters.", nullptr));
        Mail_text->setText(QCoreApplication::translate("SignUp", "E-mail:", nullptr));
        Mail_Line_Edit->setText(QString());
        Mail_Line_Edit->setPlaceholderText(QCoreApplication::translate("SignUp", "Please enter your e-mail", nullptr));
        SignUpScreen_2->setText(QString());
        AuthScreen1_2->setText(QString());
        LibManager_logo->setText(QString());
        signupButton->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        user_Button->setText(QCoreApplication::translate("SignUp", "User", nullptr));
        admin_Button->setText(QCoreApplication::translate("SignUp", "Admin", nullptr));
        welcome_text->setText(QCoreApplication::translate("SignUp", "Welcome to LibManager!", nullptr));
        label->setText(QCoreApplication::translate("SignUp", "Organize, track, and optimize your library effortlessly.", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "Create, edit, and maintain records of books.", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "New to LibManager? Sign up now.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
