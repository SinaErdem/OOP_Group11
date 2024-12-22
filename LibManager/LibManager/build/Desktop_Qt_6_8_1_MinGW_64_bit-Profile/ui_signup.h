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
#include <QtWidgets/QComboBox>
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
    QLabel *welcome_text;
    QLabel *SignUpScreen_1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Back_Button;
    QPushButton *signupButton;
    QLabel *Name_text;
    QLineEdit *Name_Line_Edit;
    QLabel *Surname_text;
    QLineEdit *Surname_Line_Edit;
    QLabel *Password_text;
    QLineEdit *Password_Line_Edit;
    QLabel *Mail_text;
    QLineEdit *Mail_Line_Edit;
    QLabel *SignUpScreen_2;
    QComboBox *roleComboBox;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(646, 467);
        SignUp->setStyleSheet(QString::fromUtf8("background-color:white"));
        SignUp_text = new QLabel(SignUp);
        SignUp_text->setObjectName("SignUp_text");
        SignUp_text->setGeometry(QRect(20, 10, 171, 51));
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
        Username_text->setGeometry(QRect(10, 260, 111, 20));
        Username_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        UsernameLineEdit = new QLineEdit(SignUp);
        UsernameLineEdit->setObjectName("UsernameLineEdit");
        UsernameLineEdit->setGeometry(QRect(0, 290, 341, 41));
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
        welcome_text = new QLabel(SignUp);
        welcome_text->setObjectName("welcome_text");
        welcome_text->setGeometry(QRect(380, 120, 311, 41));
        welcome_text->setStyleSheet(QString::fromUtf8("font: 18pt \"Calibri\";\n"
"background-color:transparent;"));
        SignUpScreen_1 = new QLabel(SignUp);
        SignUpScreen_1->setObjectName("SignUpScreen_1");
        SignUpScreen_1->setGeometry(QRect(360, -30, 451, 531));
        SignUpScreen_1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));"));
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 200, 341, 21));
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(SignUp);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 250, 391, 21));
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(SignUp);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(390, 290, 241, 21));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Back_Button = new QPushButton(SignUp);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(250, 10, 101, 41));
        Back_Button->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        Back_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"	background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));\n"
"}"));
        signupButton = new QPushButton(SignUp);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(10, 420, 341, 41));
        signupButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	color: black;\n"
"	\n"
"	font: 300 10pt \"Calibri\";\n"
"	background-color: qlineargradient(spread:pad, x1:0.23, y1:0.477273, x2:0.915, y2:0.0800455, stop:0 rgba(165, 34, 36, 255), stop:1 rgba(255, 224, 174, 255));\n"
"}"));
        Name_text = new QLabel(SignUp);
        Name_text->setObjectName("Name_text");
        Name_text->setGeometry(QRect(10, 60, 111, 20));
        Name_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Name_Line_Edit = new QLineEdit(SignUp);
        Name_Line_Edit->setObjectName("Name_Line_Edit");
        Name_Line_Edit->setGeometry(QRect(10, 80, 341, 41));
        Name_Line_Edit->setFont(font1);
        Name_Line_Edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Surname_text = new QLabel(SignUp);
        Surname_text->setObjectName("Surname_text");
        Surname_text->setGeometry(QRect(20, 130, 111, 20));
        Surname_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Surname_Line_Edit = new QLineEdit(SignUp);
        Surname_Line_Edit->setObjectName("Surname_Line_Edit");
        Surname_Line_Edit->setGeometry(QRect(10, 150, 341, 41));
        Surname_Line_Edit->setFont(font1);
        Surname_Line_Edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Password_text = new QLabel(SignUp);
        Password_text->setObjectName("Password_text");
        Password_text->setGeometry(QRect(10, 340, 111, 20));
        Password_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Password_Line_Edit = new QLineEdit(SignUp);
        Password_Line_Edit->setObjectName("Password_Line_Edit");
        Password_Line_Edit->setGeometry(QRect(10, 370, 341, 41));
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
        Mail_text = new QLabel(SignUp);
        Mail_text->setObjectName("Mail_text");
        Mail_text->setGeometry(QRect(10, 200, 111, 20));
        Mail_text->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: transparent;"));
        Mail_Line_Edit = new QLineEdit(SignUp);
        Mail_Line_Edit->setObjectName("Mail_Line_Edit");
        Mail_Line_Edit->setGeometry(QRect(0, 220, 341, 41));
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
        SignUpScreen_2->setGeometry(QRect(0, -10, 411, 480));
        SignUpScreen_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        roleComboBox = new QComboBox(SignUp);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");
        roleComboBox->setGeometry(QRect(470, 330, 82, 28));
        SignUpScreen_2->raise();
        SignUpScreen_1->raise();
        SignUp_text->raise();
        Username_text->raise();
        UsernameLineEdit->raise();
        welcome_text->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        Back_Button->raise();
        signupButton->raise();
        Name_text->raise();
        Name_Line_Edit->raise();
        Surname_text->raise();
        Surname_Line_Edit->raise();
        Password_text->raise();
        Password_Line_Edit->raise();
        Mail_text->raise();
        Mail_Line_Edit->raise();
        roleComboBox->raise();

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Dialog", nullptr));
        SignUp_text->setText(QCoreApplication::translate("SignUp", "<html><head/><body><p><span style=\" font-size:26pt;\">Sign Up</span></p></body></html>", nullptr));
        Username_text->setText(QCoreApplication::translate("SignUp", "Username:", nullptr));
        UsernameLineEdit->setText(QCoreApplication::translate("SignUp", "Username", nullptr));
        welcome_text->setText(QCoreApplication::translate("SignUp", "Welcome to LibManager!", nullptr));
        SignUpScreen_1->setText(QString());
        label->setText(QCoreApplication::translate("SignUp", "abalblalbablabalbalalbalblalballabalba", nullptr));
        label_2->setText(QCoreApplication::translate("SignUp", "blablablablablabaalblaal", nullptr));
        label_3->setText(QCoreApplication::translate("SignUp", "blablallba", nullptr));
        Back_Button->setText(QCoreApplication::translate("SignUp", "Back", nullptr));
        signupButton->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        Name_text->setText(QCoreApplication::translate("SignUp", "Name:", nullptr));
        Name_Line_Edit->setText(QCoreApplication::translate("SignUp", "Name", nullptr));
        Surname_text->setText(QCoreApplication::translate("SignUp", "Surname:", nullptr));
        Surname_Line_Edit->setText(QCoreApplication::translate("SignUp", "Surname", nullptr));
        Password_text->setText(QCoreApplication::translate("SignUp", "Password", nullptr));
        Password_Line_Edit->setText(QCoreApplication::translate("SignUp", "Please enter a password of at least 8 characters.", nullptr));
        Mail_text->setText(QCoreApplication::translate("SignUp", "Mail:", nullptr));
        Mail_Line_Edit->setText(QCoreApplication::translate("SignUp", "Mail", nullptr));
        SignUpScreen_2->setText(QString());
        roleComboBox->setItemText(0, QCoreApplication::translate("SignUp", "User", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("SignUp", "Admin", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
