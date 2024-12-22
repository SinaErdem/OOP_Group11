#ifndef AUTHSCREEN_H
#define AUTHSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuthScreen;
}
QT_END_NAMESPACE

class AuthScreen : public QMainWindow
{
    Q_OBJECT

public:
    AuthScreen(QWidget *parent = nullptr);
    ~AuthScreen();


private slots:
    void on_signupButton_clicked();

    void on_signinButton_clicked();
private:
    Ui::AuthScreen *ui;
    bool checkCredentials(const QString &username, const QString &password);

};
#endif // AUTHSCREEN_H
