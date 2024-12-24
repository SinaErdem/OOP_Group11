#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H
#include "user.h"

#include <QDialog>

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
    void on_BookList_button_clicked();

private:
    Ui::UserDashboard *ui;
    User& currentUser;

};

#endif // USERDASHBOARD_H
