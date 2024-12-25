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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDashboard
{
public:
    QLabel *logo_searchScreen;
    QLineEdit *searchLineEdit;
    QWidget *navBar;
    QLabel *LibManager_logo_navBar;
    QPushButton *showBooksButton;
    QPushButton *profile_button;
    QPushButton *showBorrowedBooksButton;
    QLabel *allBackground;
    QListWidget *bookListWidget;
    QComboBox *filterComboBox;
    QTableWidget *resultsTableWidget;
    QPushButton *findButton;
    QListWidget *borrowedBookListWidget;

    void setupUi(QDialog *UserDashboard)
    {
        if (UserDashboard->objectName().isEmpty())
            UserDashboard->setObjectName("UserDashboard");
        UserDashboard->resize(1024, 576);
        UserDashboard->setStyleSheet(QString::fromUtf8("background-color:white;"));
        logo_searchScreen = new QLabel(UserDashboard);
        logo_searchScreen->setObjectName("logo_searchScreen");
        logo_searchScreen->setGeometry(QRect(280, 60, 479, 109));
        logo_searchScreen->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/LibManager_searchScreen.png);\n"
"background-color:transparent;"));
        searchLineEdit = new QLineEdit(UserDashboard);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(200, 180, 630, 44));
        searchLineEdit->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: green;\n"
"border-radius: 15px;\n"
"color: black; \n"
"font-size: 16px;\n"
"padding-left: 10px; \n"
"padding-bottom: 2px;"));
        navBar = new QWidget(UserDashboard);
        navBar->setObjectName("navBar");
        navBar->setGeometry(QRect(0, 0, 1024, 50));
        navBar->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(90, 191, 47, 255), stop:1 rgba(13, 134, 0, 255));"));
        LibManager_logo_navBar = new QLabel(navBar);
        LibManager_logo_navBar->setObjectName("LibManager_logo_navBar");
        LibManager_logo_navBar->setGeometry(QRect(20, 12, 130, 29));
        LibManager_logo_navBar->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/LibManager_navBar.png);\n"
"background-color: transparent;"));
        showBooksButton = new QPushButton(navBar);
        showBooksButton->setObjectName("showBooksButton");
        showBooksButton->setGeometry(QRect(170, 0, 111, 50));
        showBooksButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    padding: 5px;\n"
"	border-color: transparent;\n"
"	border-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(136, 202, 129);\n"
"	border-radius: 0px;\n"
"}"));
        showBooksButton->setIconSize(QSize(18, 18));
        profile_button = new QPushButton(navBar);
        profile_button->setObjectName("profile_button");
        profile_button->setGeometry(QRect(913, 0, 111, 50));
        profile_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    padding: 5px;\n"
"	border-color: transparent;\n"
"	border-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(136, 202, 129);\n"
"	border-radius: 0px;\n"
"}"));
        showBorrowedBooksButton = new QPushButton(navBar);
        showBorrowedBooksButton->setObjectName("showBorrowedBooksButton");
        showBorrowedBooksButton->setGeometry(QRect(280, 0, 131, 50));
        showBorrowedBooksButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: white;\n"
"    padding: 5px;\n"
"	border-color: transparent;\n"
"	border-radius: 0px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(136, 202, 129);\n"
"	border-radius: 0px;\n"
"}"));
        allBackground = new QLabel(UserDashboard);
        allBackground->setObjectName("allBackground");
        allBackground->setGeometry(QRect(0, 0, 1024, 576));
        allBackground->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 231, 231);"));
        bookListWidget = new QListWidget(UserDashboard);
        bookListWidget->setObjectName("bookListWidget");
        bookListWidget->setEnabled(true);
        bookListWidget->setGeometry(QRect(0, 50, 441, 531));
        bookListWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(90, 191, 47, 255), stop:1 rgba(13, 134, 0, 255));"));
        bookListWidget->setAutoScroll(true);
        filterComboBox = new QComboBox(UserDashboard);
        filterComboBox->setObjectName("filterComboBox");
        filterComboBox->setGeometry(QRect(90, 160, 111, 61));
        QFont font;
        font.setPointSize(16);
        filterComboBox->setFont(font);
        filterComboBox->setStyleSheet(QString::fromUtf8("color:red;"));
        resultsTableWidget = new QTableWidget(UserDashboard);
        resultsTableWidget->setObjectName("resultsTableWidget");
        resultsTableWidget->setGeometry(QRect(200, 220, 521, 361));
        findButton = new QPushButton(UserDashboard);
        findButton->setObjectName("findButton");
        findButton->setGeometry(QRect(810, 170, 111, 51));
        findButton->setStyleSheet(QString::fromUtf8("\n"
"color: red;\n"
""));
        borrowedBookListWidget = new QListWidget(UserDashboard);
        borrowedBookListWidget->setObjectName("borrowedBookListWidget");
        borrowedBookListWidget->setGeometry(QRect(230, 50, 256, 211));
        allBackground->raise();
        logo_searchScreen->raise();
        searchLineEdit->raise();
        navBar->raise();
        bookListWidget->raise();
        filterComboBox->raise();
        resultsTableWidget->raise();
        findButton->raise();
        borrowedBookListWidget->raise();

        retranslateUi(UserDashboard);

        QMetaObject::connectSlotsByName(UserDashboard);
    } // setupUi

    void retranslateUi(QDialog *UserDashboard)
    {
        UserDashboard->setWindowTitle(QCoreApplication::translate("UserDashboard", "LibManager", nullptr));
        logo_searchScreen->setText(QString());
        searchLineEdit->setText(QString());
        LibManager_logo_navBar->setText(QString());
        showBooksButton->setText(QCoreApplication::translate("UserDashboard", "All Books", nullptr));
        profile_button->setText(QCoreApplication::translate("UserDashboard", "Profile", nullptr));
        showBorrowedBooksButton->setText(QCoreApplication::translate("UserDashboard", "Borrowed Books", nullptr));
        allBackground->setText(QString());
        findButton->setText(QCoreApplication::translate("UserDashboard", "Borrow Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDashboard: public Ui_UserDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDASHBOARD_H
