/**
 * @file user.h
 * @brief Defines the User class, which represents a user in the library system.
 *
 * This file declares the User class, including its member variables and functions,
 * that handle user information and interaction with the library system.
 */

#ifndef USER_H
#define USER_H

#include "library.h"
#include "library_database.h"
#include <memory>
#include <vector>
#include "admin.h"
class Book_Management_fUser;
#include <QString>

/**
 * @class User
 * @brief Represents a library user with associated functionality.
 */
class User {
public:
    /**
     * @brief Reference to the library instance associated with the user.
     */
    Library library;

    /**
     * @brief List of books borrowed by the user.
     */
    std::vector<Library_Database> borrowedBooks;

    /**
     * @brief Constructor for the User class.
     * @param email The user's email address.
     * @param username The user's username.
     * @param password The user's password.
     * @param bookManager Reference to the book management system for the user.
     */
    User(const QString& email, const QString& username, const QString& password, Book_Management_fUser& bookManager);

    /**
     * @brief Saves the user's information to a persistent storage.
     */
    void saveUserInfo() const;

    /**
     * @brief Destructor for the User class.
     */
    ~User();

    /**
     * @brief Gets the email of the user.
     * @return The user's email address.
     */
    QString getm_email() const;

    /**
     * @brief Gets the username of the user.
     * @return The user's username.
     */
    QString getm_username() const;

    /**
     * @brief Gets the password of the user.
     * @return The user's password.
     */
    QString getm_password() const;

    /**
     * @brief Reference to the book management system for the user.
     */
    Book_Management_fUser &bookManager;

    /**
     * @brief Sets the user type.
     * @param userType The type of user (e.g., admin, member).
     */
    void setm_userType(const QString& userType);

    /**
     * @brief Sets the username of the user.
     * @param username The new username.
     */
    void setm_username(const QString& username) { m_username = username; }

    /**
     * @brief Sets the password of the user.
     * @param password The new password.
     */
    void setm_password(const QString& password) { m_password = password; }

private:

    /**
     * @brief The user's email address.
     */
    QString m_email;

    /**
     * @brief The user's username.
     */
    QString m_username;

    /**
     * @brief The user's password.
     */
    QString m_password;

    /**
     * @brief The user's type (e.g., admin, member).
     */
    QString m_userType;
};

#endif // USER_H
