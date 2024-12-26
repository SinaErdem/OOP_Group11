#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include "user.h"
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QTimer>
#include "library_database.h"
#include "book_management_fuser.h"

/**
 * @namespace Ui
 * @brief The Ui namespace contains the generated user interface classes.
 */
namespace Ui {
class UserDashboard;
}

/**
 * @class UserDashboard
 * @brief Provides functionality for the user's dashboard, including viewing, borrowing, and returning books.
 */
class UserDashboard : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the UserDashboard object.
     * @param currentUser Reference to the current user.
     * @param bookManager Reference to the Book_Management_fUser instance.
     * @param parent The parent widget (default is nullptr).
     */
    explicit UserDashboard(User& currentUser, Book_Management_fUser& bookManager, QWidget *parent = nullptr);

    /**
     * @brief Destroys the UserDashboard object.
     */
    ~UserDashboard();

    /**
     * @brief Displays all books in the library.
     */
    void displayBooks();

public slots:
    /**
     * @brief Toggles the visibility of the book list.
     */
    void on_showBooksButton_clicked();

private slots:
    /**
     * @brief Handles the display of the book list.
     */
    void on_BookList_button_clicked();

    /**
     * @brief Handles the borrowing of a book.
     */
    void borrowBook();

    /**
     * @brief Toggles the search functionality for books.
     * @param checked Whether the search functionality is enabled or disabled.
     */
    void on_findButton_toggled(bool checked);

    /**
     * @brief Handles the timeout event for borrowed books.
     */
    void on_bookReturnTimeout();

    /**
     * @brief Displays the list of books borrowed by the user.
     */
    void on_showBorrowedBooksButton_clicked();

    /**
     * @brief Handles the return of a borrowed book.
     */
    void on_returnBookClicked();

private:
    QTimer* borrowTimer; ///< Timer for managing book return deadlines.
    int bookBorrowDuration = 30; ///< Default duration (in seconds) for borrowing a book.
    Ui::UserDashboard *ui; ///< Pointer to the user interface.
    User& currentUser; ///< Reference to the currently logged-in user.
    Book_Management_fUser& bookManager; ///< Reference to book management for the user.

    /**
     * @brief Populates the results table with books matching the search criteria.
     * @param results A vector of books matching the search query.
     */
    void populateResults(std::vector<Library_Database>& results);
};

#endif // USERDASHBOARD_H
