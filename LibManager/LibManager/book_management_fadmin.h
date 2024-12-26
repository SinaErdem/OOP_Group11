#ifndef BOOK_MANAGEMENT_FADMIN_H
#define BOOK_MANAGEMENT_FADMIN_H

#include <fstream>
#include <string>
#include <list>
#include "user.h"

/**
 * @class Book_Management_fAdmin
 * @brief Provides book and user management functionalities for administrators.
 */
class Book_Management_fAdmin
{
private:
    static std::list<User> users; ///< List of users in the system.

public:
    /**
     * @brief Constructs a Book_Management_fAdmin object.
     */
    Book_Management_fAdmin();

    /**
     * @brief Adds a user to the system.
     * @param user The user to be added.
     */
    static void addUser(User user);

    /**
     * @brief Removes a user from the system.
     *
     * (Currently not implemented.)
     */
    void removeUser();

    /**
     * @brief Adds a book to the system.
     * @param bookInfo A string containing book details in the format:
     * "name,author,genre,isbn,quantity".
     */
    void addBook(const std::string& bookInfo);

    /**
     * @brief Displays all users in the system.
     *
     * (Currently not implemented.)
     */
    void displayUsers();
};

#endif // BOOK_MANAGEMENT_FADMIN_H
