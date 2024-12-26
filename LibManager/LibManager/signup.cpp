#include "signup.h"
#include "book_management_fuser.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QTextStream>
#include <QDir>
#include "admin.h"
#include "user.h"

/**
 * @brief Constructor for the SignUp class.
 *
 * @param parent The parent widget.
 * @param bookManager Reference to the Book_Management_fUser object.
 */
SignUp::SignUp(QWidget *parent, Book_Management_fUser &bookManager)
    : QDialog(parent)
    , ui(new Ui::SignUp)
    , bookManager(bookManager)
{
    ui->setupUi(this);

    // Create and style the Admin button
    adminButton = new QPushButton("Admin", this);
    adminButton->setGeometry(170, 100, 101, 41);
    adminButton->setFocusPolicy(Qt::StrongFocus);
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );

    // Create and style the User button
    userButton = new QPushButton("User", this);
    userButton->setGeometry(40, 100, 101, 41);
    userButton->setFocusPolicy(Qt::StrongFocus);
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );

    connect(adminButton, &QPushButton::clicked, this, &SignUp::on_admin_Button_clicked);
    connect(userButton, &QPushButton::clicked, this, &SignUp::on_user_Button_clicked);
}

/**
 * @brief Destructor for the SignUp class.
 */
SignUp::~SignUp()
{
    delete ui;
}

// Global variable to store the selected user type (-1: none, 0: User, 1: Admin)
int selectedUserType = -1;

/**
 * @brief Event handler for the User button click.
 */
void SignUp::on_user_Button_clicked()
{
    selectedUserType = 0;
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(70, 149, 37, 255), stop:1 rgba(10, 101, 0, 255));"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "}"
        "QPushButton:hover {"
        "    background-color: rgb(0, 100, 0);"
        "}"
        );

    // Reset Admin button to default style
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );
}

/**
 * @brief Event handler for the Admin button click.
 */
void SignUp::on_admin_Button_clicked()
{
    selectedUserType = 1;
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(70, 149, 37, 255), stop:1 rgba(10, 101, 0, 255));"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "}"
        "QPushButton:hover {"
        "    background-color: rgb(0, 100, 0);"
        "}"
        );

    // Reset User button to default style
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );
}

/**
 * @brief Validates the format of an email address.
 *
 * @param email The email address to validate.
 * @return true if the email is valid, false otherwise.
 */
bool isValidEmail(const QString &email)
{
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return emailRegex.match(email).hasMatch();
}

/**
 * @brief Validates the password complexity.
 *
 * @param password The password to validate.
 * @return true if the password meets the requirements, false otherwise.
 */
bool isValidPassword(const QString &password)
{
    bool hasLetter = false;
    bool hasDigit = false;

    for (const QChar &ch : password) {
        if (ch.isLetter()) hasLetter = true;
        if (ch.isDigit()) hasDigit = true;

        if (hasLetter && hasDigit) return true;
    }
    return false;
}

/**
 * @brief Event handler for the sign-up button click.
 */
void SignUp::on_signupButton_clicked()
{
    if (selectedUserType == -1) {
        QMessageBox::warning(this, "Registration Error", "Please select a user type.");
        return;
    }

    QString email = ui->Mail_Line_Edit->text();
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->Password_Line_Edit->text();

    if (!isValidEmail(email)) {
        QMessageBox::warning(this, "Registration Error", "Invalid email address.");
        return;
    }

    if (!isValidPassword(password)) {
        QMessageBox::warning(this, "Registration Error", "Password must contain at least one letter and one digit.");
        return;
    }

    if (selectedUserType == 0) {
        User user(email, username, password, bookManager);
        user.saveUserInfo();
        QMessageBox::information(this, "Registration", "User registered successfully!");
    } else if (selectedUserType == 1) {
        Admin admin(email, username, password);
        admin.saveUserInfo();
        QMessageBox::information(this, "Registration", "Admin registered successfully!");
    }
}

/**
 * @brief Event handler for the back button click.
 */
void SignUp::on_Back_Button_clicked()
{
    close();
}








