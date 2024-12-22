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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDashboard
{
public:
    QLabel *logo_searchScreen;
    QLineEdit *searchBar;
    QWidget *navBar;
    QLabel *LibManager_logo_navBar;
    QPushButton *BookList_button;
    QPushButton *Magazines_button;
    QPushButton *cd_button;
    QPushButton *profile_button;
    QLabel *allBackground;

    void setupUi(QDialog *UserDashboard)
    {
        if (UserDashboard->objectName().isEmpty())
            UserDashboard->setObjectName("UserDashboard");
        UserDashboard->resize(1024, 576);
        UserDashboard->setStyleSheet(QString::fromUtf8("background-color:white;"));
        logo_searchScreen = new QLabel(UserDashboard);
        logo_searchScreen->setObjectName("logo_searchScreen");
        logo_searchScreen->setGeometry(QRect(272, 190, 479, 109));
        logo_searchScreen->setStyleSheet(QString::fromUtf8("background-image: url(C:/LibManager/LibManager/LBResources/LibManager_searchScreen.png);\n"
"background-color:transparent;"));
        searchBar = new QLineEdit(UserDashboard);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(197, 340, 630, 44));
        searchBar->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
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
        BookList_button = new QPushButton(navBar);
        BookList_button->setObjectName("BookList_button");
        BookList_button->setGeometry(QRect(170, 0, 111, 50));
        BookList_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Magazines_button = new QPushButton(navBar);
        Magazines_button->setObjectName("Magazines_button");
        Magazines_button->setGeometry(QRect(280, 0, 111, 50));
        Magazines_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        cd_button = new QPushButton(navBar);
        cd_button->setObjectName("cd_button");
        cd_button->setGeometry(QRect(390, 0, 111, 50));
        cd_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        allBackground = new QLabel(UserDashboard);
        allBackground->setObjectName("allBackground");
        allBackground->setGeometry(QRect(0, 0, 1024, 576));
        allBackground->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 231, 231);"));
        allBackground->raise();
        logo_searchScreen->raise();
        searchBar->raise();
        navBar->raise();

        retranslateUi(UserDashboard);

        QMetaObject::connectSlotsByName(UserDashboard);
    } // setupUi

    void retranslateUi(QDialog *UserDashboard)
    {
        UserDashboard->setWindowTitle(QCoreApplication::translate("UserDashboard", "LibManager", nullptr));
        logo_searchScreen->setText(QString());
        searchBar->setText(QCoreApplication::translate("UserDashboard", "allah allah neymi\305\237 ki bu", nullptr));
        LibManager_logo_navBar->setText(QString());
        BookList_button->setText(QCoreApplication::translate("UserDashboard", "Book List", nullptr));
        Magazines_button->setText(QCoreApplication::translate("UserDashboard", "Magazine", nullptr));
        cd_button->setText(QCoreApplication::translate("UserDashboard", "CDs", nullptr));
        profile_button->setText(QCoreApplication::translate("UserDashboard", "Profile", nullptr));
        allBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserDashboard: public Ui_UserDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDASHBOARD_H
