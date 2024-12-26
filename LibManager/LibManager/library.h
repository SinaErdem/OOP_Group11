#ifndef LIBRARY_H
#define LIBRARY_H
#include <list>
#include "library_database.h"

class Library
{
private:
    std::list<Library_Database> books;

public:
    void addBook(const Library_Database& book);
    std::list<Library_Database>& allBooks();
};

#endif // LIBRARY_H
