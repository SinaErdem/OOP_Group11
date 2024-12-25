#include "book_management_fuser.h"
#include "qdebug.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>

Book_Management_fUser gbookManager;
Book_Management_fUser::Book_Management_fUser(User* user) {
    this->user = user;
}
Book_Management_fUser::Book_Management_fUser() {
}


long Book_Management_fUser::barrowBook( Library_Database &book) {
    if (book.getNumber() == 0) {
        throw std::runtime_error("The book cannot barrow now!");
    }


    user->borrowedBooks.push_back(book);


    book.setNumber(book.getNumber() - 1);


    std::srand(std::time(nullptr));
    code = 1000000 + std::rand() % 90000000;

    return code;
}


void Book_Management_fUser::returnBook(Library_Database& book) {
    auto it = std::find(user->borrowedBooks.begin(), user->borrowedBooks.end(), book);
    if (it == user->borrowedBooks.end()) {
        qDebug() << "Error: Book not found in borrowedBooks list.";
        throw std::runtime_error("This book has not been borrowed by the user!");
    }

    // Kitap bilgilerini geçici değişkene taşı
    Library_Database tempBook = *it;
    qDebug() << "Book found: " << QString::fromStdString(tempBook.getName());

    // Kitabı listeden çıkar
    user->borrowedBooks.erase(it);
    qDebug() << "Book removed from borrowedBooks list.";

    // Stok miktarını artır
    tempBook.setNumber(tempBook.getNumber() + 1);
    qDebug() << "Stock updated for the book. Current stock:" << tempBook.getNumber();
}



// List borrowed books
void Book_Management_fUser::listBorrowedBooks() const {
    if (user->borrowedBooks.empty()) {
        qDebug() << "No borrowed books.";
        return;
    }

    for (const auto& book : user->borrowedBooks) {
        qDebug() << "Book Name:" << book.getName()
        << ", Author:" << book.getAuthor()
        << ", Genre:" << book.getGenre()
        << ", ISBN:" << book.getIsbn();
    }

}





void Book_Management_fUser::seeAllBooks() {
    auto books = library.allBooks();
    for ( auto& book : books) {
        std::cout << "Book: " << book.getName()
        << ", Author: " << book.getAuthor()
        << ", Genre: " << book.getGenre()
        << ", ISBN: " << book.getIsbn()
        << ", Number of books: " << book.getNumber() << '\n';
    }
    std::cout<<"\n";
}

void Book_Management_fUser::searchBookByName(const std::string& name)  {
    bool found = false;
    auto books = library.allBooks();
    std::string lowerName = name;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    for ( auto& book : books) {

        std::string lowerBookName = book.getName();
        std::transform(lowerBookName.begin(), lowerBookName.end(), lowerBookName.begin(), ::tolower);

        if (lowerBookName == lowerName) {
            found = true;
            std::cout << "The Book found:\n";
            std::cout << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
            break;
        }

    }

    if (!found) {
        std::cout << "The Book didn't found: " << name << "\n";
    }
    std::cout<<"\n";
}

void Book_Management_fUser::searchBookByAuthor(const std::string& author)  {
    bool found = false;
    auto books = library.allBooks();


    std::string lowerAuthor = author;
    std::transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(), ::tolower);

    for ( auto& book : books) {

        std::string lowerBookAuthor = book.getAuthor();
        std::transform(lowerBookAuthor.begin(), lowerBookAuthor.end(), lowerBookAuthor.begin(), ::tolower);

        if (lowerBookAuthor == lowerAuthor) {
            found = true;
            std::cout << "The Book found:\n";
            std::cout << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
        }
    }

    if (!found) {
        std::cout << "No books found by author: " << author << "\n"<<"\n";
    }
    std::cout<<"\n";
}

void Book_Management_fUser::searchBookByISBN(const std::string& isbn)  {
    bool found = false;
    auto books=library.allBooks();

    for ( auto& book : books) {
        if (book.getIsbn() == isbn) {
            found = true;
            std::cout << "The Book found:\n";
            std::cout << "Name: " << book.getName() << "\n"
                      << "Author: " << book.getAuthor() << "\n"
                      << "Genre: " << book.getGenre() << "\n"
                      << "ISBN: " << book.getIsbn() << "\n"
                      << "Number of books: " << book.getNumber() << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "The Book didn't found: " << isbn << "\n";
    }
    std::cout<<"\n";
}

