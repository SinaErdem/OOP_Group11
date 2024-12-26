#include "admin.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

/**
 * @brief Constructs an Admin object.
 * @param email The email of the admin.
 * @param username The username of the admin.
 * @param password The password of the admin.
 */
Admin::Admin(const QString& email, const QString& username, const QString& password)
    : m_email(email), m_username(username), m_password(password), m_userType("Admin") {}

/**
 * @brief Saves the admin's information to a file.
 *
 * This function writes the admin's email, username, password, and user type to
 * a file located at "C:/LibManager/LibManager/LBResources/users.txt". It ensures
 * the directory exists before attempting to write the file.
 */
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
