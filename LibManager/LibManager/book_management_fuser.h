#ifndef BOOK_MANAGEMENT_FUSER_H
#define BOOK_MANAGEMENT_FUSER_H
#include "library.h"
#include "user.h"
#include "librarymanagement.h"
#include "library.h"
#include <algorithm>
#include <cctype>

class Book_Management_fUser
{
    int barrowingTime=15;
    long code;
    User* user;

public:

    Library library;
    Book_Management_fUser();
    void seeAllBooks();
    void searchBookByName(const std::string& name) ;
    void searchBookByAuthor(const std::string& author) ;
    void searchBookByISBN(const std::string& isbn) ;
    Book_Management_fUser(User* user);
    long barrowBook( Library_Database &book);
    void returnBook(Library_Database& book);

};

extern Book_Management_fUser gbookManager;
#endif // BOOK_MANAGEMENT_FUSER_H
