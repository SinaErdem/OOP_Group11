#include "User.h"
#include "book_management_fuser.h"
#include "library_database.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QMessageBox>

User::User(const QString& email, const QString& username, const QString& password, Book_Management_fUser& bookManager)
    : bookManager(bookManager), m_email(email), m_username(username), m_password(password) {}

User::~User(){}
void User::setm_userType(const QString& userType) {
    m_userType = userType;  // Parametreyi sınıf üyesine atama
}





void User::saveUserInfo() const {
    QString filePath = "C:/LibManager/LibManager/LBResources/users.txt";

    // Check and create the directory if it doesn't exist
    QDir dir;
    if (!dir.exists("C:/LibManager/LibManager/LBResources")) {
        qDebug() << "Directory doesn't exist, creating...";
        dir.mkpath("C:/LibManager/LibManager/LBResources");
    }

    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << m_email << "," << m_username << "," << m_password << "," << m_userType << "\n";
        file.close();
        qDebug() << "User data saved.";
    } else {
        qDebug() << "Failed to open file!" << file.errorString();
    }
}


QString User::getm_email() const {
        return m_email;
    }

QString User::getm_username() const {
    return m_username;
}

QString User::getm_password() const {
    return m_password;
}

