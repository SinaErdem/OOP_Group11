/********************************************************************************
** Form generated from reading UI file 'userdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDASHBOARD_H
#define UI_USERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_UserDashboard
{
public:
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QTableWidget *resultsTableWidget;
    QComboBox *genreComboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *UserDashboard)
    {
        if (UserDashboard->objectName().isEmpty())
            UserDashboard->setObjectName("UserDashboard");
        UserDashboard->resize(676, 412);
        searchLineEdit = new QLineEdit(UserDashboard);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(240, 170, 113, 28));
        searchButton = new QPushButton(UserDashboard);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(390, 170, 83, 29));
        resultsTableWidget = new QTableWidget(UserDashboard);
        resultsTableWidget->setObjectName("resultsTableWidget");
        resultsTableWidget->setGeometry(QRect(180, 210, 256, 192));
        genreComboBox = new QComboBox(UserDashboard);
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->setObjectName("genreComboBox");
        genreComboBox->setGeometry(QRect(140, 170, 82, 28));
        pushButton = new QPushButton(UserDashboard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 10, 83, 29));
        pushButton_2 = new QPushButton(UserDashboard);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 10, 83, 29));
        textEdit = new QTextEdit(UserDashboard);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(270, 110, 104, 51));
        textEdit_2 = new QTextEdit(UserDashboard);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(540, 10, 104, 31));
        textEdit_3 = new QTextEdit(UserDashboard);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(30, 10, 104, 21));

        retranslateUi(UserDashboard);

        QMetaObject::connectSlotsByName(UserDashboard);
    } // setupUi

    void retranslateUi(QDialog *UserDashboard)
    {
        UserDashboard->setWindowTitle(QCoreApplication::translate("UserDashboard", "Dialog", nullptr));
        searchLineEdit->setText(QCoreApplication::translate("UserDashboard", "Kitap Ara", nullptr));
        searchButton->setText(QCoreApplication::translate("UserDashboard", "Ara", nullptr));
        genreComboBox->setItemText(0, QCoreApplication::translate("UserDashboard", "Roman ", nullptr));
        genreComboBox->setItemText(1, QCoreApplication::translate("UserDashboard", "Bilim ", nullptr));
        genreComboBox->setItemText(2, QCoreApplication::translate("UserDashboard", "Felsefe", nullptr));
        genreComboBox->setItemText(3, QCoreApplication::translate("UserDashboard", "Spor", nullptr));
        genreComboBox->setItemText(4, QCoreApplication::translate("UserDashboard", "Macera", nullptr));

        pushButton->setText(QCoreApplication::translate("UserDashboard", "\304\260ade Etme", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UserDashboard", "\303\226d\303\274n\303\247 Alma", nullptr));
        textEdit->setHtml(QCoreApplication::translate("UserDashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Buraya \304\260MG GElecek</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("UserDashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Log Out</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("UserDashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Profil</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDashboard: public Ui_UserDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDASHBOARD_H
