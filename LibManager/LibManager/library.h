#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include "library_database.h"

/**
 * @class Library
 * @brief Manages a collection of books in the library.
 */
class Library
{
private:
    std::list<Library_Database> books; ///< List of books in the library.

public:
    /**
     * @brief Adds a book to the library's collection.
     * @param book The book to be added.
     */
    void addBook(const Library_Database& book);

    /**
     * @brief Retrieves all books in the library.
     * @return A reference to the list of books.
     */
    std::list<Library_Database>& allBooks();
};

#endif // LIBRARY_H
