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
    void on_Back_Button_clicked();

private:
    Ui::SignUp *ui;
    void saveToFile(const QString &username,const QString &email ,const QString &password,const QString &role);
    bool isUserExist(const QString &username, const QString &email);
    void showSuccessPopup(QWidget *parent);
};

#endif // SIGNUP_H
