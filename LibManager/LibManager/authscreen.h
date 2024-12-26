#ifndef AUTHSCREEN_H
#define AUTHSCREEN_H

#include "book_management_fuser.h"
#include <QMainWindow>
#include "userdashboard.h"

/**
 * @namespace Ui
 * @brief The Ui namespace contains the generated user interface classes.
 */
QT_BEGIN_NAMESPACE
namespace Ui {
class AuthScreen;
}
QT_END_NAMESPACE

/**
 * @class AuthScreen
 * @brief Handles user authentication for the library system.
 *
 * This class provides functionality for user login and navigation to respective dashboards.
 */
class AuthScreen : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the AuthScreen object.
     * @param parent The parent widget.
     */
    AuthScreen(QWidget *parent = nullptr);

    /**
     * @brief Destroys the AuthScreen object.
     */
    ~AuthScreen();

private slots:
    /**
     * @brief Opens the signup screen for new user registration.
     */
    void on_signupButton_clicked();

    /**
     * @brief Authenticates the user and navigates to the appropriate dashboard.
     */
    void on_signinButton_clicked();

private:
    /**
     * @brief Validates user credentials.
     * @param username The entered username.
     * @param password The entered password.
     * @return The user type if credentials are valid; otherwise, an empty string.
     */
    QString checkCredentials(const QString &username, const QString &password);

    Ui::AuthScreen *ui; ///< Pointer to the UI.
    Book_Management_fUser bookManager; ///< Book management functionality for users.
    User currentUser; ///< The currently logged-in user.
    UserDashboard *userDashboard; ///< Pointer to the user dashboard.
};

#endif // AUTHSCREEN_H
