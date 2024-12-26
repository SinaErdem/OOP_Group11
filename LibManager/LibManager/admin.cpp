#include "Admin.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

Admin::Admin(const QString& email, const QString& username, const QString& password)
    : m_email(email), m_username(username), m_password(password), m_userType("Admin") {}

void Admin::saveUserInfo() const {
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
        qDebug() << "Admin data saved.";
    } else {
        qDebug() << "Failed to open file!" << file.errorString();
    }
}
