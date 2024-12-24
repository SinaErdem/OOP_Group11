#ifndef ADMIN_H
#define ADMIN_H
class Book_Management_fAdmin;

#include <QString>

class Admin {
public:
    Book_Management_fAdmin* book_management_fAdmin;
    Admin(const QString& email, const QString& username, const QString& password);
    void saveUserInfo() const;

private:
    QString m_email;
    QString m_username;
    QString m_password;
    QString m_userType;
};

#endif // ADMIN_H
