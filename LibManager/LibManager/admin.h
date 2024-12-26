#ifndef ADMIN_H
#define ADMIN_H
class Book_Management_fAdmin;

#include <QString>

/**
 * @class Admin
 * @brief Represents an administrator user in the library management system.
 */
class Admin {
public:
    Book_Management_fAdmin* book_management_fAdmin;

    /**
     * @brief Constructs an Admin object.
     * @param email The email of the admin.
     * @param username The username of the admin.
     * @param password The password of the admin.
     */
    Admin(const QString& email, const QString& username, const QString& password);

    /**
     * @brief Saves the admin's information to a file.
     */
    void saveUserInfo() const;

private:
    QString m_email;     ///< The admin's email address.
    QString m_username;  ///< The admin's username.
    QString m_password;  ///< The admin's password.
    QString m_userType;  ///< The user type, default is "Admin".
};

#endif // ADMIN_H
