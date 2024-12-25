#ifndef USER_H
#define USER_H
#include "library.h"
#include "library_database.h"
#include <memory>
#include <vector>
#include "admin.h"
class Book_Management_fUser;
#include <QString>

class User {
public:
    Library library;
    std::vector<Library_Database> borrowedBooks;

    User(const QString& email, const QString& username, const QString& password,Book_Management_fUser& bookManager);
    void saveUserInfo() const;
    ~User();
    QString getm_email() const;
    QString getm_username() const;
    QString getm_password() const;
    Book_Management_fUser &bookManager;
    void setm_userType(const QString& userType);
    void setm_username(const QString& username) { m_username = username; }
    void setm_password(const QString& password) { m_password = password; }

private:
    QString m_username;
    QString m_email;

    QString m_password;
    QString m_userType;

};

#endif // USER_H
