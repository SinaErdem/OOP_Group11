#ifndef BOOK_MANAGEMENT_FADMIN_H
#define BOOK_MANAGEMENT_FADMIN_H
#include <fstream>
#include <string>
#include "user.h"
#include <list>

class Book_Management_fAdmin
{
private:
    static std::list<User> users;
public:
    Book_Management_fAdmin();
    static void addUser(User user);
    void removeUser();
    void addBook(const std::string& bookInfo);
    void displayUsers();
};

#endif // BOOK_MANAGEMENT_FADMIN_H
