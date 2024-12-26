#include "book_management_fuser.h"
#include "qdebug.h"
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

// Global instance of Book_Management_fUser
Book_Management_fUser gbookManager;

/**
 * @brief Default constructor.
 */
Book_Management_fUser::Book_Management_fUser() {}

/**
 * @brief Constructs a Book_Management_fUser object with a user.
 * @param user Pointer to the user managing books.
 */
Book_Management_fUser::Book_Management_fUser(User* user) {
    this->user = user;
}

/**
 * @brief Borrows a book from the library.
 * @param book The book to be borrowed.
 * @return A unique code for the borrowed book.
 * @throws std::runtime_error If the book is out of stock.
 */
long Book_Management_fUser::barrowBook(Library_Database& book) {
    if (book.getNumber() == 0) {
        throw std::runtime_error("The book cannot be borrowed now!");
    }

    user->borrowedBooks.push_back(book);
    book.setNumber(book.getNumber() - 1);

    std::srand(std::time(nullptr));
    code = 1000000 + std::rand() % 90000000;

    return code;
}

/**
 * @brief Returns a borrowed book to the library.
 * @param book The book to be returned.
 * @throws std::runtime_error If the book is not found in the user's borrowed list.
 */
void Book_Management_fUser::returnBook(Library_Database& book) {
    auto it = std::find(user->borrowedBooks.begin(), user->borrowedBooks.end(), book);
    if (it == user->borrowedBooks.end()) {
        qDebug() << "Error: Book not found in borrowedBooks list.";
        throw std::runtime_error("This book has not been borrowed by the user!");
    }

    Library_Database tempBook = *it;
    user->borrowedBooks.erase(it);
    tempBook.setNumber(tempBook.getNumber() + 1);
}

/**
 * @brief Lists all books borrowed by the user.
 */
void Book_Management_fUser::listBorrowedBooks() const {
    if (user->borrowedBooks.empty()) {
        qDebug() << "No borrowed books.";
        return;
    }

    for (const auto& book : user->borrowedBooks) {
        qDebug() << "Book Name:" << QString::fromStdString(book.getName())
        << ", Author:" << QString::fromStdString(book.getAuthor())
        << ", Genre:" << QString::fromStdString(book.getGenre())
        << ", ISBN:" << QString::fromStdString(book.getIsbn());
    }
}

/**
 * @brief Allows a user to see all available books in the library.
 */
void Book_Management_fUser::seeAllBooks() {
    auto books = library.allBooks();
    for (auto& book : books) {
        std::cout << "Book: " << book.getName()
        << ", Author: " << book.getAuthor()
        << ", Genre: " << book.getGenre()
        << ", ISBN: " << book.getIsbn()
        << ", Number of books: " << book.getNumber() << '\n';
    }
    std::cout << "\n";
}

/**
 * @brief Searches for a book by its name.
 * @param name The name of the book to search for.
 */
void Book_Management_fUser::searchBookByName(const std::string& name) {
    bool found = false;
    auto books = library.allBooks();

    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    for (auto& book : books) {
        std::string lowerBookName = book.getName();
        std::transform(lowerBookName.begin(), lowerBookName.end(), lowerBookName.begin(), ::tolower);

        if (lowerBookName == lowerName) {
            found = true;
            std::cout << "The Book found:\n"
                      << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "The Book didn't find: " << name << "\n";
    }
    std::cout << "\n";
}

/**
 * @brief Searches for books by their author.
 * @param author The author's name.
 */
void Book_Management_fUser::searchBookByAuthor(const std::string& author) {
    bool found = false;
    auto books = library.allBooks();

    std::string lowerAuthor = author;
    std::transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(), ::tolower);

    for (auto& book : books) {
        std::string lowerBookAuthor = book.getAuthor();
        std::transform(lowerBookAuthor.begin(), lowerBookAuthor.end(), lowerBookAuthor.begin(), ::tolower);

        if (lowerBookAuthor == lowerAuthor) {
            found = true;
            std::cout << "The Book found:\n"
                      << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
        }
    }

    if (!found) {
        std::cout << "No books found by author: " << author << "\n\n";
    }
    std::cout << "\n";
}

/**
 * @brief Searches for a book by its ISBN.
 * @param isbn The ISBN of the book.
 */
void Book_Management_fUser::searchBookByISBN(const std::string& isbn) {
    bool found = false;
    auto books = library.allBooks();

    for (auto& book : books) {
        if (book.getIsbn() == isbn) {
            found = true;
            std::cout << "The Book found:\n"
                      << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "The Book didn't find: " << isbn << "\n";
    }
    std::cout << "\n";
}

