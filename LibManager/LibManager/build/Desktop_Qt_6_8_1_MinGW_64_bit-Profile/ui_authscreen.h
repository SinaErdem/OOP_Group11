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
#include <QtWidgets/QFrame>
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
    QFrame *line;
    QLabel *AuthScreen1;
    QLabel *SignIn_text;
    QLineEdit *UsernameLineEdit;
    QLabel *Username_text;
    QLineEdit *PasswordLineEdit;
    QLabel *Password_text;
    QPushButton *signinButton;
    QLabel *LibManager_logo;
    QLabel *welcome_text;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *AuthScreen1_2;
    QPushButton *signupButton;

    void setupUi(QMainWindow *AuthScreen)
    {
        if (AuthScreen->objectName().isEmpty())
            AuthScreen->setObjectName("AuthScreen");
        AuthScreen->resize(854, 480);
        AuthScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(166, 135, 166);"));
        centralwidget = new QWidget(AuthScreen);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(427, 0, 3, 480));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
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
        UsernameLineEdit->setGeometry(QRect(40, 150, 341, 41));
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
        Username_text->setGeometry(QRect(46, 125, 111, 20));
        Username_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        PasswordLineEdit->setGeometry(QRect(40, 280, 341, 41));
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
        Password_text = new QLabel(centralwidget);
        Password_text->setObjectName("Password_text");
        Password_text->setGeometry(QRect(50, 250, 111, 20));
        Password_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        signinButton = new QPushButton(centralwidget);
        signinButton->setObjectName("signinButton");
        signinButton->setGeometry(QRect(40, 350, 341, 41));
        signinButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"	background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));\n"
"}"));
        LibManager_logo = new QLabel(centralwidget);
        LibManager_logo->setObjectName("LibManager_logo");
        LibManager_logo->setGeometry(QRect(460, 60, 349, 79));
        LibManager_logo->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/full_logo_LibManager_relieved.png);\n"
"background-color:transparent;"));
        welcome_text = new QLabel(centralwidget);
        welcome_text->setObjectName("welcome_text");
        welcome_text->setGeometry(QRect(500, 150, 311, 41));
        welcome_text->setStyleSheet(QString::fromUtf8("font: 18pt \"Calibri\";\n"
"background-color:transparent;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 240, 391, 21));
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 280, 391, 21));
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 320, 391, 21));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AuthScreen1_2 = new QLabel(centralwidget);
        AuthScreen1_2->setObjectName("AuthScreen1_2");
        AuthScreen1_2->setGeometry(QRect(430, 0, 427, 480));
        AuthScreen1_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));"));
        signupButton = new QPushButton(centralwidget);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(40, 410, 341, 41));
        signupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"	background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));\n"
"}"));
        AuthScreen->setCentralWidget(centralwidget);
        AuthScreen1_2->raise();
        line->raise();
        AuthScreen1->raise();
        SignIn_text->raise();
        UsernameLineEdit->raise();
        Username_text->raise();
        PasswordLineEdit->raise();
        Password_text->raise();
        signinButton->raise();
        welcome_text->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        signupButton->raise();
        LibManager_logo->raise();

        retranslateUi(AuthScreen);

        QMetaObject::connectSlotsByName(AuthScreen);
    } // setupUi

    void retranslateUi(QMainWindow *AuthScreen)
    {
        AuthScreen->setWindowTitle(QCoreApplication::translate("AuthScreen", "AuthScreen", nullptr));
        AuthScreen1->setText(QString());
        SignIn_text->setText(QCoreApplication::translate("AuthScreen", "<html><head/><body><p><span style=\" font-size:26pt;\">Sign In</span></p></body></html>", nullptr));
        UsernameLineEdit->setText(QCoreApplication::translate("AuthScreen", "  Username", nullptr));
        Username_text->setText(QCoreApplication::translate("AuthScreen", "USERNAME:", nullptr));
        PasswordLineEdit->setText(QCoreApplication::translate("AuthScreen", "  Password", nullptr));
        Password_text->setText(QCoreApplication::translate("AuthScreen", "PASSWORD:", nullptr));
        signinButton->setText(QCoreApplication::translate("AuthScreen", "Sign in", nullptr));
        LibManager_logo->setText(QString());
        welcome_text->setText(QCoreApplication::translate("AuthScreen", "Welcome to LibManager!", nullptr));
        label->setText(QCoreApplication::translate("AuthScreen", "abalblalbablabalbalalbalblalballabalba", nullptr));
        label_2->setText(QCoreApplication::translate("AuthScreen", "blablablablablabaalblaal", nullptr));
        label_3->setText(QCoreApplication::translate("AuthScreen", "blablallba", nullptr));
        AuthScreen1_2->setText(QString());
        signupButton->setText(QCoreApplication::translate("AuthScreen", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthScreen: public Ui_AuthScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHSCREEN_H
