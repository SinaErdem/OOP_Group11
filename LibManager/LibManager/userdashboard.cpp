#include "userdashboard.h"
#include "qboxlayout.h"
#include "qdir.h"
#include "signup.h"
#include "ui_userdashboard.h"
#include<QList>
#include<QFile>
#include <QListWidget>
#include<QMessageBox>
#include "book_management_fuser.h"
#include "QString"
#include "user.h"

#include <QTimer>   // Include QTimer here as well
#include <QMessageBox>
// Initializing bookManager


UserDashboard::UserDashboard(User& currentUser,Book_Management_fUser& bookManager ,QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDashboard), currentUser(currentUser),bookManager(bookManager) // initializing bookManager

{
    ui->setupUi(this);
    ui->bookListWidget->hide();
    ui->filterComboBox->addItems({"Name", "Author", "ISBN"});
    ui->bookListWidget->hide();
    ui->resultsTableWidget->hide();
    ui->findButton->setCheckable(true);


    ui->barrowedbooks->hide();
}

UserDashboard::~UserDashboard()
{

    delete ui;
    if (borrowTimer) {
        delete borrowTimer;
    }
}



void UserDashboard::on_BookList_button_clicked()
{
    displayBooks();

}
void UserDashboard::displayBooks()
{

    ui->bookListWidget->clear();  // Clear the list

    // Retrieve books from the currentUser object
    for ( auto& book : currentUser.bookManager.library.allBooks()) {
        // Format and add book details
        QString bookInfo = "Name: " + QString::fromStdString(book.getName()) + "\n"
                           + "Author: " + QString::fromStdString(book.getAuthor()) + "\n"
                           + "Genre: " + QString::fromStdString(book.getGenre()) + "\n"
                           + "ISBN: " + QString::fromStdString(book.getIsbn()) + "\n"
                           + "Number of books: " + QString::number(book.getNumber())+"\n";


        ui->bookListWidget->addItem(bookInfo);  // Add books to the list
    }
    ui->bookListWidget->setVisible(true);
}


void UserDashboard::on_showBooksButton_clicked() {
    if (ui->bookListWidget->isVisible()) {
        ui->bookListWidget->hide();  // Hide the book list if visible
    } else {
        ui->bookListWidget->show();  // Show the book list if hidden
        displayBooks();
    }
}


void UserDashboard::populateResults(std::vector<Library_Database>& results) {
    ui->resultsTableWidget->clearContents();  // Clear previous content
    ui->resultsTableWidget->setRowCount(0);   // Reset row count
    ui->resultsTableWidget->setColumnCount(4); // 4 columns: Name, Author, ISBN, Borrow Button
    ui->resultsTableWidget->setHorizontalHeaderLabels({"Name", "Author", "ISBN", "Borrow Button"});

    // Always reset and reload the table
    for (auto& book : results) {
        int row = ui->resultsTableWidget->rowCount();
        ui->resultsTableWidget->insertRow(row);  // Add a new line
        // Add book information to the table
        ui->resultsTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(book.getName())));
        ui->resultsTableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(book.getAuthor())));
        ui->resultsTableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(book.getIsbn())));

        //Add "Borrow Book" button
        QPushButton* borrowButton = new QPushButton("Borrow Book");
        connect(borrowButton, &QPushButton::clicked, this, &UserDashboard::borrowBook);

        // Insert a new cell in QTableWidget to add the QPushButton
        ui->resultsTableWidget->setCellWidget(row, 3, borrowButton);
    }

    // Adjust column widths
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);  // Name column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);  // Author column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);  // ISBN column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);  // Borrow button column
}

void UserDashboard::borrowBook() {

    // Use the pointer from the Sender() function immediately
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;  // Buton geçerli değilse çık


    int row = -1;
    for (int i = 0; i < ui->resultsTableWidget->rowCount(); ++i) {
        if (ui->resultsTableWidget->cellWidget(i, 3) == button) {  // 3. column "Borrow Button"
            row = i;
            break;
        }
    }

    if (row == -1) return;  // Exit if line not found

    // Get book information in the table
    QString bookName = ui->resultsTableWidget->item(row, 0)->text();
    QString bookAuthor = ui->resultsTableWidget->item(row, 1)->text();
    QString bookISBN = ui->resultsTableWidget->item(row, 2)->text();

    // Match book data to library
    Library_Database* book = nullptr;
    for (auto& b : currentUser.bookManager.library.allBooks()) {
        if (QString::fromStdString(b.getName()) == bookName &&
            QString::fromStdString(b.getAuthor()) == bookAuthor &&
            QString::fromStdString(b.getIsbn()) == bookISBN) {
            book = &b;
            break;
        }
    }

    if (!book) {
        // Alert when the book is not found
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Book not found in library.");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        msgBox.exec();
        return;
    }

    // Check if the same book has already been borrowed by the user
    for (auto& borrowedBook : currentUser.borrowedBooks) {
        if (borrowedBook.getName() == bookName &&
            borrowedBook.getAuthor() == bookAuthor &&
            borrowedBook.getIsbn() == bookISBN) {
            // Show warning if the book has been borrowed before
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Information);  // Warning Sign
            msgBox.setWindowTitle("Info");
            msgBox.setText("You can not borrow the same book more than once by our policy.");  // Message Text
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok button
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");
            msgBox.exec();
            return;
        }
    }

    // Reduce the number of books by one
    if (book->getNumber() > 0) {
        book->setNumber(book->getNumber() - 1); //Reduce the number of books

        // Add books to the loan list
        currentUser.borrowedBooks.push_back(*book);

        // Create file for user and save book
        QDir dir("C:/LibManager/LibManager/usersTXT");
        if (!dir.exists()) {
            dir.mkpath(".");  // Create if folder does not exist
        }

        QString userFileName = dir.filePath(currentUser.getm_username() + ".txt");
        QFile userFile(userFileName);

        if (!userFile.open(QIODevice::Append | QIODevice::Text)) {
            // Give an error message if the file cannot be opened
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setWindowTitle("Error");
            msgBox.setText("Cannot open user file for saving borrowed books.");
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok button
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");
            msgBox.exec();
            return;
        }

        QTextStream out(&userFile);
        out << QString::fromStdString(book->getName())
            << "," << QString::fromStdString(book->getAuthor())
            << "," << QString::fromStdString(book->getGenre())
            << "," << QString::fromStdString(book->getIsbn()) << "\n";

        userFile.close();

        // Notify the user of success
        QMessageBox info1;
        info1.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        info1.setIcon(QMessageBox::Information);  // Warning
        info1.setWindowTitle("Success");
        info1.setText("Book added to borrowed list and saved to file.");  // Mesagge
        info1.setStandardButtons(QMessageBox::Ok);    // Ok button
        info1.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        info1.exec();

        // Update the table again
        QString searchQuery = ui->searchLineEdit->text().trimmed();
        QString filterOption = ui->filterComboBox->currentText();

        std::vector<Library_Database> results;
        for (auto& book : currentUser.bookManager.library.allBooks()) {
            bool match = false;

            // Searching
            if (searchQuery.isEmpty()) {
                results.push_back(book);
            } else {
                std::string searchStr = searchQuery.toStdString();
                if (filterOption == "Name") {
                    std::string nameLower = book.getName();
                    std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
                    std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
                    match = nameLower.find(searchStr) != std::string::npos;
                } else if (filterOption == "Author") {
                    std::string authorLower = book.getAuthor();
                    std::transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
                    std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
                    match = authorLower.find(searchStr) != std::string::npos;
                } else if (filterOption == "ISBN") {
                    match = book.getIsbn().find(searchStr) != std::string::npos;
                }

                if (match) {
                    results.push_back(book);
                }
            }
        }

        populateResults(results);  // Fill in the results again
        borrowTimer = new QTimer(this);
        borrowTimer->setSingleShot(true);
        connect(borrowTimer, &QTimer::timeout, this, &UserDashboard::on_bookReturnTimeout);
        borrowTimer->start(bookBorrowDuration * 1000);
    } else {
        // If the number of books is 0, it cannot be borrowed
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("This book is out of stock.");  // Mesage
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok button
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        msgBox.exec();
    }
}

void UserDashboard::on_findButton_toggled(bool checked) {
    if (!checked) {
        // Button released, hide results
        ui->resultsTableWidget->hide();
        return;
    }

    // Button pressed, search and show results
    QString searchQuery = ui->searchLineEdit->text().trimmed();
    QString filterOption = ui->filterComboBox->currentText();

    if (searchQuery.isEmpty()) {
        //QMessageBox::warning(this, "Error", "Please enter a search query.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Please enter a search query.");
        msgBox.setStandardButtons(QMessageBox::Ok);

        // Style sheet with black background and white text
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");


        msgBox.exec();
        ui->findButton->setChecked(false);  // Make the button normal
        return;
    }

    // Clear search results
    ui->resultsTableWidget->clearContents();  // Clean the Table
    ui->resultsTableWidget->setRowCount(0);   // Reset number of rows

    //Searching
    std::vector<Library_Database> results;
    for (auto& book : currentUser.bookManager.library.allBooks()) {
        bool match = false;

        // Check and match filtering options
        std::string searchStr = searchQuery.toStdString();
        if (filterOption == "Name") {
            std::string nameLower = book.getName();
            std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
            match = nameLower.find(searchStr) != std::string::npos;
        } else if (filterOption == "Author") {
            std::string authorLower = book.getAuthor();
            std::transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
            std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
            match = authorLower.find(searchStr) != std::string::npos;
        } else if (filterOption == "ISBN") {
            match = book.getIsbn().find(searchStr) != std::string::npos;
        }

        if (match) {
            results.push_back(book);
        }
    }

    // Processing results
    if (results.empty()) {
        //QMessageBox::information(this, "Info", "No books found.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Info");
        msgBox.setText("No books found.");  // Message
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok button

        // Style sheet with black background and white text
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");


        msgBox.exec();
        ui->findButton->setChecked(false);  // Make the button normal
        ui->resultsTableWidget->hide();  // Hide list if no result
        return;
    }

    populateResults(results);  // Fill in the results
    ui->resultsTableWidget->show();  // Show Results
}


void UserDashboard::on_showBorrowedBooksButton_clicked()
{
    qDebug() << "Displaying borrowed books...";

    // Check the table, hide if visible, show if not visible
    if (ui->barrowedbooks->isVisible()) {
        // If the table is visible, hide it
        ui->barrowedbooks->setVisible(false);
        qDebug() << "Table hidden.";
    } else {
        // If the table is not visible, show
        ui->barrowedbooks->setVisible(true);
        qDebug() << "Table shown.";

        // Clean Table
        ui->barrowedbooks->clearContents();
        ui->barrowedbooks->setRowCount(0); // Clear existing rows

        // Set the number of columns (Book Title, Author, Genre, ISBN, Button)
        ui->barrowedbooks->setColumnCount(5);
        ui->barrowedbooks->setHorizontalHeaderLabels({"Book Name", "Author", "Genre", "ISBN", "Action"});

        // Get user file
        QString userFileName = "C:/LibManager/LibManager/usersTXT/" + currentUser.getm_username() + ".txt";
        QFile userFile(userFileName);

        // Check the existence of the file
        if (!userFile.exists()) {
            qDebug() << "User file not found.";
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
            return;
        }

        // Open File
        if (!userFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Cannot open user file.";
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("Error reading borrowed books."));
            return;
        }

        QTextStream in(&userFile);
        QString line;
        bool foundBooks = false;

        // Process each line in the file
        while (!in.atEnd()) {
            line = in.readLine().trimmed();
            QStringList bookDetails = line.split(",");

            // Check book information
            if (bookDetails.size() == 4) {
                QString bookName = bookDetails[0].trimmed();
                QString bookAuthor = bookDetails[1].trimmed();
                QString bookGenre = bookDetails[2].trimmed();
                QString bookIsbn = bookDetails[3].trimmed();

                // Add New Line
                int row = ui->barrowedbooks->rowCount();
                ui->barrowedbooks->insertRow(row);

                // Add book information to the table
                ui->barrowedbooks->setItem(row, 0, new QTableWidgetItem(bookName));
                ui->barrowedbooks->setItem(row, 1, new QTableWidgetItem(bookAuthor));
                ui->barrowedbooks->setItem(row, 2, new QTableWidgetItem(bookGenre));
                ui->barrowedbooks->setItem(row, 3, new QTableWidgetItem(bookIsbn));

                // Create "Return Book" Button
                QPushButton* returnButton = new QPushButton("Return Book");
                returnButton->setProperty("bookName", bookName); // Add your book name to the button

                // Connect button signal to slot
                connect(returnButton, &QPushButton::clicked, this, &UserDashboard::on_returnBookClicked);

                // Add button to table
                ui->barrowedbooks->setCellWidget(row, 4, returnButton);

                qDebug() << "Book added to the list:" << bookName;
                foundBooks = true;
            }
        }

        if (!foundBooks) {
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
        }

        userFile.close();


    }
}
void UserDashboard::on_returnBookClicked() {
    // Get the name of the book clicked on the button
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString bookName = button->property("bookName").toString();
    qDebug() << "Book returned: " << bookName;

    // Update file with book information
    QString filename = "C:/LibManager/LibManager/usersTXT/" + currentUser.getm_username() + ".txt"; // Path (username.txt)

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        //QMessageBox::warning(this, "Dosya Hatası", "Kitap bilgileri dosyası açılamadı.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("File Error");
        msgBox.setText("The book data file could not be opened.");
        msgBox.setStandardButtons(QMessageBox::Ok);

        // Style sheet with black background and white text
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Show Message Box
        msgBox.exec();
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    bool bookFound = false;

    // Read all lines in the file and rewrite to delete the line
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        // Take the book name up to the comma
        QString currentBookName = parts[0].trimmed();

        // If there is a line matching the book name, skip (delete) this line
        if (currentBookName.compare(bookName.trimmed(), Qt::CaseInsensitive) == 0) {
            bookFound = true;
            qDebug() << "Book removed from file: " << bookName;
            continue;
        }

        lines.append(line);  // Keep other lines
    }

    if (!bookFound) {
        qDebug() << "Book not found in file.";
        return;
    }

    // Go back to the beginning of the file and clear the contents
    file.resize(0);
    QTextStream out(&file);

    // Rewrite the remaining lines to the file
    for (const QString& line : lines) {
        out << line << "\n";
    }
    file.close();

    // Give feedback to the user
    //QMessageBox::information(this, "Success", "The book has been successfully returned.");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("The book has been successfully returned.");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Style sheet with black background and white text
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Show Message Box
    msgBox.exec();

    // Update Table
    ui->barrowedbooks->clearContents();
    ui->barrowedbooks->setRowCount(0); // Clear existing rows

    QFile userFile(filename);

    if (!userFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open user file.";
        ui->barrowedbooks->setRowCount(1);
        ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("Error reading borrowed books."));
        return;
    }

    QTextStream updatedIn(&userFile);
    QString updatedLine;
    bool foundBooks = false;

    // Process each line in the file
    while (!updatedIn.atEnd()) {
        updatedLine = updatedIn.readLine().trimmed();
        QStringList bookDetails = updatedLine.split(",");

        if (bookDetails.size() == 4) {
            QString updatedBookName = bookDetails[0].trimmed();
            QString bookAuthor = bookDetails[1].trimmed();
            QString bookGenre = bookDetails[2].trimmed();
            QString bookIsbn = bookDetails[3].trimmed();

            int row = ui->barrowedbooks->rowCount();
            ui->barrowedbooks->insertRow(row);

            // Add book information to the table
            ui->barrowedbooks->setItem(row, 0, new QTableWidgetItem(updatedBookName));
            ui->barrowedbooks->setItem(row, 1, new QTableWidgetItem(bookAuthor));
            ui->barrowedbooks->setItem(row, 2, new QTableWidgetItem(bookGenre));
            ui->barrowedbooks->setItem(row, 3, new QTableWidgetItem(bookIsbn));

            //Add "Return Book" button
            QPushButton* returnButton = new QPushButton("Return Book");
            returnButton->setProperty("bookName", updatedBookName);
            connect(returnButton, &QPushButton::clicked, this, &UserDashboard::on_returnBookClicked);
            ui->barrowedbooks->setCellWidget(row, 4, returnButton);

            foundBooks = true;
        }
    }

    if (!foundBooks) {
        ui->barrowedbooks->setRowCount(1);
        ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
    }

    userFile.close();
    if (borrowTimer && borrowTimer->isActive()) {
        borrowTimer->stop();
        qDebug() << "Borrow timer stopped.";
    }
}


void UserDashboard::on_bookReturnTimeout() {
    // Show warning message if timeout occurs
    //QMessageBox::warning(this, "Time expired", "You did not return the book within the allotted time. Please return the book as soon as possible.");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Time Expired!");
    msgBox.setText("You did not return the book within the allotted time.\nPlease return the book as soon as possible.");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);


    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Show message box
    msgBox.exec();
    // make sure the bookIsbn variable is defined correctly
    QString bookIsbn = "some_isbn_value";  // There must be a real ISBN value here

    auto it = std::find_if(currentUser.borrowedBooks.begin(), currentUser.borrowedBooks.end(),
                           [bookIsbn](const Library_Database& book) {
                               return QString::fromStdString(book.getIsbn()).trimmed() == bookIsbn;
                           });

    if (it != currentUser.borrowedBooks.end()) {
        qDebug() << "Book found:" << QString::fromStdString(it->getName());
        try {

            bookManager.returnBook(*it); // Borrow the Book
            qDebug() << "Book successfully returned.";
            //QMessageBox::information(this, "Success", "Book returned successfully.");
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
            msgBox.setWindowTitle("Success!");        // Başlık
            msgBox.setText("Just in time!\nThanks for returning the book.");  // Mesaj metni
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

            // Style sheet with black background and white text
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");

            // Show message box
            msgBox.exec();
            on_showBorrowedBooksButton_clicked(); // Update the List
        } catch (std::runtime_error& e) {
            QMessageBox::critical(this,"Error",e.what());
            qDebug() << "Error during returnBook:" << e.what();
        }
    }
}








