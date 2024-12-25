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
#include <QtWidgets/QDialog>
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

    void setupUi(QDialog *AdminDashboard)
    {
        if (AdminDashboard->objectName().isEmpty())
            AdminDashboard->setObjectName("AdminDashboard");
        AdminDashboard->resize(640, 344);
        bookNameInput = new QLineEdit(AdminDashboard);
        bookNameInput->setObjectName("bookNameInput");
        bookNameInput->setGeometry(QRect(10, 40, 113, 22));
        authorNameInput = new QLineEdit(AdminDashboard);
        authorNameInput->setObjectName("authorNameInput");
        authorNameInput->setGeometry(QRect(130, 40, 113, 22));
        genreInput = new QLineEdit(AdminDashboard);
        genreInput->setObjectName("genreInput");
        genreInput->setGeometry(QRect(250, 40, 113, 22));
        isbnInput = new QLineEdit(AdminDashboard);
        isbnInput->setObjectName("isbnInput");
        isbnInput->setGeometry(QRect(380, 40, 113, 22));
        numberInput = new QLineEdit(AdminDashboard);
        numberInput->setObjectName("numberInput");
        numberInput->setGeometry(QRect(510, 40, 113, 22));
        addBooksButton = new QPushButton(AdminDashboard);
        addBooksButton->setObjectName("addBooksButton");
        addBooksButton->setGeometry(QRect(10, 110, 111, 31));
        removeBooksButton = new QPushButton(AdminDashboard);
        removeBooksButton->setObjectName("removeBooksButton");
        removeBooksButton->setGeometry(QRect(510, 110, 111, 31));

        retranslateUi(AdminDashboard);

        QMetaObject::connectSlotsByName(AdminDashboard);
    } // setupUi

    void retranslateUi(QDialog *AdminDashboard)
    {
        AdminDashboard->setWindowTitle(QCoreApplication::translate("AdminDashboard", "Dialog", nullptr));
        bookNameInput->setText(QCoreApplication::translate("AdminDashboard", "Name", nullptr));
        authorNameInput->setText(QCoreApplication::translate("AdminDashboard", "Author", nullptr));
        genreInput->setText(QCoreApplication::translate("AdminDashboard", "Genre", nullptr));
        isbnInput->setText(QCoreApplication::translate("AdminDashboard", "ISBN", nullptr));
        numberInput->setText(QCoreApplication::translate("AdminDashboard", "Number of books", nullptr));
        addBooksButton->setText(QCoreApplication::translate("AdminDashboard", "Add boook", nullptr));
        removeBooksButton->setText(QCoreApplication::translate("AdminDashboard", "Remove book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDashboard: public Ui_AdminDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDASHBOARD_H
