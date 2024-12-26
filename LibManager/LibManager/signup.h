#ifndef SIGNUP_H
#define SIGNUP_H

#include "user.h"
#include <QDialog>
#include <QString>
#include "book_management_fuser.h"

/**
 * @namespace Ui
 * @brief The Ui namespace contains the generated user interface classes.
 */
namespace Ui {
class SignUp;
}

/**
 * @class SignUp
 * @brief Provides functionality for user registration.
 */
class SignUp : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a SignUp dialog.
     * @param parent The parent widget.
     * @param bookManager Reference to the Book_Management_fUser instance.
     */
    explicit SignUp(QWidget *parent, Book_Management_fUser& bookManager);

    /**
     * @brief Destroys the SignUp dialog.
     */
    ~SignUp();

private slots:
    /**
     * @brief Handles the registration process for new users.
     */
    void on_signupButton_clicked();

    /**
     * @brief Sets the user type to regular user during registration.
     */
    void on_user_Button_clicked();

    /**
     * @brief Sets the user type to admin during registration.
     */
    void on_admin_Button_clicked();

    /**
     * @brief Closes the signup dialog and returns to the previous screen.
     */
    void on_Back_Button_clicked();

private:
    Ui::SignUp *ui; ///< Pointer to the UI.
    QPushButton *adminButton; ///< Button for selecting admin user type.
    QPushButton *userButton; ///< Button for selecting regular user type.
    Book_Management_fUser& bookManager; ///< Reference to book management for user operations.
};

#endif // SIGNUP_H
