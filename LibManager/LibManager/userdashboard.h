#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H
#include "user.h"
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QDialog>
#include "library_database.h"

namespace Ui {
class UserDashboard;
}

class UserDashboard : public QDialog
{
    Q_OBJECT

public:
     UserDashboard(User& currentUser, QWidget *parent = nullptr);
    ~UserDashboard();
    void displayBooks();
public slots:
    void on_showBooksButton_clicked();



private slots:
    // Butonlar ve girişler için slotlar
    void on_BookList_button_clicked();  // Kitap listesine tıklama
    void borrowBook();
    void on_findButton_toggled(bool checked);


private:
    Ui::UserDashboard *ui;
    User& currentUser;
    void populateResults(std::vector<Library_Database> &results);

};

#endif // USERDASHBOARD_H
