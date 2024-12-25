#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H
#include "user.h"
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QDialog>
#include "library_database.h"
#include "book_management_fuser.h"


namespace Ui {
class UserDashboard;
}

class UserDashboard : public QDialog
{
    Q_OBJECT

public:
     UserDashboard(User& currentUser,Book_Management_fUser& bookManager ,QWidget *parent = nullptr);
    ~UserDashboard();
    void displayBooks();
public slots:
    void on_showBooksButton_clicked();



private slots:
    // Butonlar ve girişler için slotlar
    void on_BookList_button_clicked();  // Kitap listesine tıklama
    void borrowBook();
    void on_findButton_toggled(bool checked);
    void on_bookReturnTimeout();


<<<<<<< HEAD

=======
>>>>>>> c6c584033b7e038d0a4866a83fcb6e398ce0357d
    void on_showBorrowedBooksButton_clicked();
    void on_returnBookClicked();

private:
    QTimer* borrowTimer;
    int bookBorrowDuration = 30;
    Ui::UserDashboard *ui;
    User& currentUser;
    Book_Management_fUser& bookManager; // Kitap yönetimi referansı

    void populateResults(std::vector<Library_Database> &results);

};

#endif // USERDASHBOARD_H
