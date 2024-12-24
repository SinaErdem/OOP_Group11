#ifndef SIGNUP_H
#define SIGNUP_H
#include "user.h"
#include <QDialog>
#include <QString>
#include <QRegularExpression>
#include "book_management_fuser.h"


namespace Ui {
class SignUp;
}

class SignUp : public QDialog {
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent, Book_Management_fUser& bookManager);
    ~SignUp();


private slots:
    void on_signupButton_clicked();
    void on_user_Button_clicked();
    void on_admin_Button_clicked();

    void on_Back_Button_clicked();

private:
    Ui::SignUp *ui;
    QPushButton *adminButton;
    QPushButton *userButton;
    Book_Management_fUser& bookManager;

};


#endif // SIGNUP_H
