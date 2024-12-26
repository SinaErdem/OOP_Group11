#include "library.h"

/**
 * @brief Adds a book to the library's collection.
 * @param book The book to be added.
 */
void Library::addBook(const Library_Database& book) {
    books.push_back(book);
}

/**
 * @brief Retrieves all books in the library.
 * @return A reference to the list of books.
 */
std::list<Library_Database>& Library::allBooks() {
    return books;
}
