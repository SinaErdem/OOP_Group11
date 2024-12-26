#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QDialog>

namespace Ui {
class AdminDashboard;
}

/**
 * @class AdminDashboard
 * @brief The AdminDashboard class provides the interface for administrative actions.
 *
 * This class allows administrators to manage users and books in the library system.
 */
class AdminDashboard : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs an AdminDashboard object.
     * @param parent The parent widget.
     */
    explicit AdminDashboard(QWidget *parent = nullptr);

    /**
     * @brief Destroys the AdminDashboard object.
     */
    ~AdminDashboard();

private slots:
    /**
     * @brief Adds a new book to the system.
     */
    void addBooks();

    /**
     * @brief Removes a book from the system.
     */
    void removeBooks();

    /**
     * @brief Adds a new user to the system.
     */
    void addUsers();

    /**
     * @brief Removes a user from the system.
     */
    void removeUsers();

private:
    Ui::AdminDashboard *ui; ///< UI pointer for the AdminDashboard.
};

#endif // ADMINDASHBOARD_H
