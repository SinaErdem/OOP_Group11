#include "book_management_fadmin.h"
#include <iostream>
#include <sstream>

// Static member initialization
std::list<User> Book_Management_fAdmin::users;

/**
 * @brief Constructs a Book_Management_fAdmin object.
 */
Book_Management_fAdmin::Book_Management_fAdmin() {}

/**
 * @brief Adds a user to the system.
 * @param user The user to be added.
 */
void Book_Management_fAdmin::addUser(User user) {
    users.push_back(user);
}

/**
 * @brief Removes a user from the system.
 *
 * (Currently not implemented.)
 */
void Book_Management_fAdmin::removeUser() {
    // Implementation needed.
}

/**
 * @brief Adds a book to the system.
 * @param bookInfo A string containing book details in the format:
 * "name,author,genre,isbn,quantity".
 */
void Book_Management_fAdmin::addBook(const std::string& bookInfo) {
    std::istringstream stream(bookInfo);
    std::string name, author, genre, isbn;
    int quantity;

    std::getline(stream, name, ',');
    std::getline(stream, author, ',');
    std::getline(stream, genre, ',');
    std::getline(stream, isbn, ',');
    stream >> quantity;

    std::ofstream outFile("books.txt", std::ios::app);

    if (outFile.is_open()) {
        outFile << name << ","
                << author << ","
                << genre << ","
                << isbn << ","
                << quantity << "\n";

        std::cout << "Book added successfully!" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

/**
 * @brief Displays all users in the system.
 *
 * (Currently not implemented.)
 */
void Book_Management_fAdmin::displayUsers() {
    // Implementation needed.
}


