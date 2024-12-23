#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QString>
#include <QRegularExpression>


namespace Ui {
class SignUp;
}

class SignUp : public QDialog {
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
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

};

#endif // SIGNUP_H
