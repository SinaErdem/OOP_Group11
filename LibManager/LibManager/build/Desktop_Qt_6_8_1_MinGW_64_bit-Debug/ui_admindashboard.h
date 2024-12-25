/********************************************************************************
** Form generated from reading UI file 'admindashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDASHBOARD_H
#define UI_ADMINDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminDashboard
{
public:
    QLineEdit *bookNameInput;
    QLineEdit *authorNameInput;
    QLineEdit *genreInput;
    QLineEdit *isbnInput;
    QLineEdit *numberInput;
    QPushButton *addBooksButton;
    QPushButton *removeBooksButton;
    QLineEdit *removeBookInput;
    QPushButton *addUserButton;
    QPushButton *RemoveUserButton;
    QLineEdit *removeUserInput;
    QLineEdit *UsernameInput;
    QLineEdit *UserPasswordInput;
    QLabel *title;
    QComboBox *UserComboBox;
    QLineEdit *EmailInput;

    void setupUi(QDialog *AdminDashboard)
    {
        if (AdminDashboard->objectName().isEmpty())
            AdminDashboard->setObjectName("AdminDashboard");
        AdminDashboard->resize(550, 310);
        AdminDashboard->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(90, 191, 47, 255), stop:1 rgba(13, 134, 0, 255));"));
        bookNameInput = new QLineEdit(AdminDashboard);
        bookNameInput->setObjectName("bookNameInput");
        bookNameInput->setGeometry(QRect(10, 100, 111, 22));
        bookNameInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        authorNameInput = new QLineEdit(AdminDashboard);
        authorNameInput->setObjectName("authorNameInput");
        authorNameInput->setGeometry(QRect(10, 130, 111, 22));
        authorNameInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        genreInput = new QLineEdit(AdminDashboard);
        genreInput->setObjectName("genreInput");
        genreInput->setGeometry(QRect(10, 160, 111, 22));
        genreInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        isbnInput = new QLineEdit(AdminDashboard);
        isbnInput->setObjectName("isbnInput");
        isbnInput->setGeometry(QRect(10, 190, 111, 22));
        isbnInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        numberInput = new QLineEdit(AdminDashboard);
        numberInput->setObjectName("numberInput");
        numberInput->setGeometry(QRect(10, 220, 111, 22));
        numberInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        addBooksButton = new QPushButton(AdminDashboard);
        addBooksButton->setObjectName("addBooksButton");
        addBooksButton->setGeometry(QRect(10, 250, 111, 31));
        addBooksButton->setStyleSheet(QString::fromUtf8("color: white;"));
        removeBooksButton = new QPushButton(AdminDashboard);
        removeBooksButton->setObjectName("removeBooksButton");
        removeBooksButton->setGeometry(QRect(150, 250, 111, 31));
        removeBooksButton->setStyleSheet(QString::fromUtf8("color: white;"));
        removeBookInput = new QLineEdit(AdminDashboard);
        removeBookInput->setObjectName("removeBookInput");
        removeBookInput->setGeometry(QRect(150, 220, 111, 22));
        removeBookInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        addUserButton = new QPushButton(AdminDashboard);
        addUserButton->setObjectName("addUserButton");
        addUserButton->setGeometry(QRect(290, 250, 111, 31));
        addUserButton->setStyleSheet(QString::fromUtf8("color:white;"));
        RemoveUserButton = new QPushButton(AdminDashboard);
        RemoveUserButton->setObjectName("RemoveUserButton");
        RemoveUserButton->setGeometry(QRect(430, 250, 111, 31));
        RemoveUserButton->setStyleSheet(QString::fromUtf8("color: white;"));
        removeUserInput = new QLineEdit(AdminDashboard);
        removeUserInput->setObjectName("removeUserInput");
        removeUserInput->setGeometry(QRect(430, 220, 111, 22));
        removeUserInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        UsernameInput = new QLineEdit(AdminDashboard);
        UsernameInput->setObjectName("UsernameInput");
        UsernameInput->setGeometry(QRect(290, 190, 111, 22));
        UsernameInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        UserPasswordInput = new QLineEdit(AdminDashboard);
        UserPasswordInput->setObjectName("UserPasswordInput");
        UserPasswordInput->setGeometry(QRect(290, 220, 111, 22));
        UserPasswordInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        title = new QLabel(AdminDashboard);
        title->setObjectName("title");
        title->setGeometry(QRect(10, 20, 301, 51));
        title->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: 22pt \"Calibri\";\n"
"background-color:transparent;"));
        UserComboBox = new QComboBox(AdminDashboard);
        UserComboBox->addItem(QString());
        UserComboBox->addItem(QString());
        UserComboBox->setObjectName("UserComboBox");
        UserComboBox->setGeometry(QRect(290, 123, 111, 28));
        UserComboBox->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));
        EmailInput = new QLineEdit(AdminDashboard);
        EmailInput->setObjectName("EmailInput");
        EmailInput->setGeometry(QRect(290, 160, 111, 22));
        EmailInput->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));

        retranslateUi(AdminDashboard);

        QMetaObject::connectSlotsByName(AdminDashboard);
    } // setupUi

    void retranslateUi(QDialog *AdminDashboard)
    {
        AdminDashboard->setWindowTitle(QCoreApplication::translate("AdminDashboard", "Dialog", nullptr));
        bookNameInput->setText(QString());
        bookNameInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Name", nullptr));
        authorNameInput->setText(QString());
        authorNameInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Author", nullptr));
        genreInput->setText(QString());
        genreInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Genre", nullptr));
        isbnInput->setText(QString());
        isbnInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "ISBN", nullptr));
        numberInput->setText(QString());
        numberInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Number of Books", nullptr));
        addBooksButton->setText(QCoreApplication::translate("AdminDashboard", "Add book", nullptr));
        removeBooksButton->setText(QCoreApplication::translate("AdminDashboard", "Remove book", nullptr));
        removeBookInput->setText(QString());
        removeBookInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Name", nullptr));
        addUserButton->setText(QCoreApplication::translate("AdminDashboard", "Add User", nullptr));
        RemoveUserButton->setText(QCoreApplication::translate("AdminDashboard", "Remove User", nullptr));
        removeUserInput->setText(QString());
        removeUserInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Username", nullptr));
        UsernameInput->setText(QString());
        UsernameInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Username", nullptr));
        UserPasswordInput->setText(QString());
        UserPasswordInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "Password", nullptr));
        title->setText(QCoreApplication::translate("AdminDashboard", "Admin Panel", nullptr));
        UserComboBox->setItemText(0, QCoreApplication::translate("AdminDashboard", "User", nullptr));
        UserComboBox->setItemText(1, QCoreApplication::translate("AdminDashboard", "Admin", nullptr));

        UserComboBox->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "User Type", nullptr));
        EmailInput->setText(QString());
        EmailInput->setPlaceholderText(QCoreApplication::translate("AdminDashboard", "E-mail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDashboard: public Ui_AdminDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDASHBOARD_H
