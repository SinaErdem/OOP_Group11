#ifndef BOOK_MANAGEMENT_FUSER_H
#define BOOK_MANAGEMENT_FUSER_H

#include "library.h"
#include "user.h"
#include "librarymanagement.h"
#include <algorithm>
#include <cctype>

/**
 * @class Book_Management_fUser
 * @brief Provides book management functionalities for regular users.
 */
class Book_Management_fUser
{
private:
    int barrowingTime = 15; ///< The default borrowing time in days.
    long code;              ///< Unique code for borrowed books.
    User* user;             ///< Pointer to the user managing the books.

public:
    Library library; ///< Library instance for managing books.

    /**
     * @brief Default constructor.
     */
    Book_Management_fUser();

    /**
     * @brief Constructs a Book_Management_fUser object with a user.
     * @param user Pointer to the user managing books.
     */
    Book_Management_fUser(User* user);

    /**
     * @brief Allows a user to see all available books in the library.
     */
    void seeAllBooks();

    /**
     * @brief Searches for a book by its name.
     * @param name The name of the book to search for.
     */
    void searchBookByName(const std::string& name);

    /**
     * @brief Searches for books by their author.
     * @param author The author's name.
     */
    void searchBookByAuthor(const std::string& author);

    /**
     * @brief Searches for a book by its ISBN.
     * @param isbn The ISBN of the book.
     */
    void searchBookByISBN(const std::string& isbn);

    /**
     * @brief Borrows a book from the library.
     * @param book The book to be borrowed.
     * @return A unique code for the borrowed book.
     * @throws std::runtime_error If the book is out of stock.
     */
    long barrowBook(Library_Database& book);

    /**
     * @brief Returns a borrowed book to the library.
     * @param book The book to be returned.
     * @throws std::runtime_error If the book is not found in the user's borrowed list.
     */
    void returnBook(Library_Database& book);

    /**
     * @brief Lists all books borrowed by the user.
     */
    void listBorrowedBooks() const;
};

extern Book_Management_fUser gbookManager; ///< Global instance of Book_Management_fUser.

#endif // BOOK_MANAGEMENT_FUSER_H
