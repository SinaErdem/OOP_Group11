#include "User.h"
#include "book_management_fuser.h"
#include "library_database.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QMessageBox>

/**
 * @class User
 * @brief Represents a user in the library management system.
 *
 * This class provides functionalities for managing user information and saving it to a file.
 */

/**
 * @brief Constructor for the User class.
 *
 * Initializes a user with email, username, password, and a reference to the book manager.
 *
 * @param email Email of the user.
 * @param username Username of the user.
 * @param password Password of the user.
 * @param bookManager Reference to the book management system for the user.
 */
User::User(const QString& email, const QString& username, const QString& password, Book_Management_fUser& bookManager)
    : bookManager(bookManager), m_email(email), m_username(username), m_password(password), m_userType("User") {}

/**
 * @brief Destructor for the User class.
 */
User::~User() {}

/**
 * @brief Sets the user type.
 *
 * Updates the user type with the provided value.
 *
 * @param userType The new user type to be set.
 */
void User::setm_userType(const QString& userType) {
    m_userType = userType;  // Assign the parameter to the class member
}

/**
 * @brief Saves the user information to a file.
 *
 * This method writes the user's email, username, password, and user type to a designated file.
 * If the directory doesn't exist, it creates it before saving the file.
 */
void User::saveUserInfo() const {
    QString filePath = "C:/LibManager/LibManager/LBResources/users.txt";

    /**
     * @brief Check and create the directory if it doesn't exist.
     */
    QDir dir;
    if (!dir.exists("C:/LibManager/LibManager/LBResources")) {
        qDebug() << "Directory doesn't exist, creating...";
        dir.mkpath("C:/LibManager/LibManager/LBResources");
    }

    /**
     * @brief Open the file in append mode and write user information.
     */
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

/**
 * @brief Gets the user's email.
 *
 * @return The email of the user.
 */
QString User::getm_email() const {
    return m_email;
}

/**
 * @brief Gets the user's username.
 *
 * @return The username of the user.
 */
QString User::getm_username() const {
    return m_username;
}

/**
 * @brief Gets the user's password.
 *
 * @return The password of the user.
 */
QString User::getm_password() const {
    return m_password;
}

