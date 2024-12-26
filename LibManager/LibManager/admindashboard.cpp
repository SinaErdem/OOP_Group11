#include "admindashboard.h"
#include "ui_admindashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

/**
 * @brief Constructs the AdminDashboard class.
 *
 * Initializes the Admin Dashboard, connects button actions to their corresponding slots.
 *
 * @param parent Parent widget for this dashboard.
 */
AdminDashboard::AdminDashboard(QWidget *parent) :
    QDialog(parent),  ///< QDialog as the base class.
    ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->addBooksButton, &QPushButton::clicked, this, &AdminDashboard::addBooks);
    connect(ui->removeBooksButton, &QPushButton::clicked, this, &AdminDashboard::removeBooks);
    connect(ui->addUserButton, &QPushButton::clicked, this, &AdminDashboard::addUsers);
    connect(ui->RemoveUserButton, &QPushButton::clicked, this, &AdminDashboard::removeUsers);
}

/**
 * @brief Destructor for AdminDashboard.
 */
AdminDashboard::~AdminDashboard()
{
    delete ui;
}

/**
 * @brief Adds a book to the library system.
 *
 * Gathers book details from input fields and appends them to the `books.txt` file.
 * Ensures all fields are filled before adding.
 */
void AdminDashboard::addBooks()
{
    QString bookName = ui->bookNameInput->text();
    QString authorName = ui->authorNameInput->text();
    QString genre = ui->genreInput->text();
    QString isbn = ui->isbnInput->text();
    QString number = ui->numberInput->text();

    if (bookName.isEmpty() || authorName.isEmpty() || genre.isEmpty() || isbn.isEmpty() || number.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled!");
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open books file!");
        return;
    }

    QTextStream out(&file);
    out << bookName << ", " << authorName << ", " << genre << ", " << isbn << ", " << number << "\n";
    file.close();

    QMessageBox::information(this, "Success", "Book added successfully!");

    // Clear input fields
    ui->bookNameInput->clear();
    ui->authorNameInput->clear();
    ui->genreInput->clear();
    ui->isbnInput->clear();
    ui->numberInput->clear();
}

/**
 * @brief Adds a new user to the system.
 *
 * Validates user input, checks if the email or username already exists, and then writes
 * the new user's details into the `users.txt` file.
 */
void AdminDashboard::addUsers()
{
    QString email = ui->EmailInput->text();
    QString username = ui->UsernameInput->text();
    QString password = ui->UserPasswordInput->text();
    QString role = ui->UserComboBox->currentText();

    if (email.isEmpty() || username.isEmpty() || password.isEmpty() || role.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled!");
        return;
    }

    QFile file("C:/LibManager/LibManager/LBResources/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open users file!");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");

        if (userDetails.size() >= 2 &&
            (userDetails[0] == email || userDetails[1] == username)) {
            QMessageBox::warning(this, "Error", "Email or username already exists!");
            file.close();
            return;
        }
    }
    file.close();

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open users file for writing!");
        return;
    }

    QTextStream out(&file);
    out << email << "," << username << "," << password << "," << role << "\n";
    file.close();

    QMessageBox::information(this, "Success", "User added successfully!");

    // Clear input fields
    ui->EmailInput->clear();
    ui->UsernameInput->clear();
    ui->UserPasswordInput->clear();
    ui->UserComboBox->setCurrentIndex(0);
}

/**
 * @brief Removes a book from the library system.
 *
 * Searches for the book in the `books.txt` file by name and removes it if found.
 */
void AdminDashboard::removeBooks()
{
    QString bookName = ui->removeBookInput->text();
    if (bookName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter the name of the book to remove!");
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open books file!");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.startsWith(bookName + ",")) {
            lines.append(line);
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Cannot write to books file!");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Success", "Book removed successfully!");

    // Clear input field
    ui->removeBookInput->clear();
}

/**
 * @brief Removes a user from the system.
 *
 * Searches for the user by username in the `users.txt` file and removes the entry if found.
 */
void AdminDashboard::removeUsers()
{
    QString usernameToRemove = ui->removeUserInput->text().trimmed();
    if (usernameToRemove.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter the username to remove!");
        return;
    }

    QFile file("C:/LibManager/LibManager/LBResources/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open users file!");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    bool userFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");

        if (userDetails.size() >= 2 && userDetails[1] == usernameToRemove) {
            userFound = true;
            continue;
        }
        lines.append(line);
    }
    file.close();

    if (!userFound) {
        QMessageBox::warning(this, "Error", "User not found!");
        return;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Cannot write to users file!");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Success", "User removed successfully!");

    // Clear input field
    ui->removeUserInput->clear();
}

