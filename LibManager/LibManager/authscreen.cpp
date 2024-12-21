#include "authscreen.h"
#include "ui_authscreen.h"
#include "signup.h"
#include "admindashboard.h"
#include "userdashboard.h"
#include<QFile>
#include<QString>
#include<QMessageBox>
AuthScreen::AuthScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AuthScreen)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
}

AuthScreen::~AuthScreen()
{
    delete ui;
}

void AuthScreen::on_signupButton_clicked() //event listener mantığı
{
    SignUp *signUpWindow = new SignUp(this);//tıklandığında yeni pencere oluşturma
    signUpWindow->show();


}
QString AuthScreen::getUserRole(const QString &username, const QString &password) //Sign in'e basılınca Dosyadan okunan kullanıcının role'ünü(Admin,User)alma
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Hata", "Dosya açılamadı!");
        return QString();
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 4) {
            QString fileUsername = fields[0];
            QString filePassword = fields[2];
            QString fileRole = fields[3];

            if (fileUsername == username && filePassword == password) {
                return fileRole.trimmed(); // Kullanıcının rolünü döndür
            }
        }
    }

    file.close();
    return QString(); // Kullanıcı bulunamazsa boş döndür
}


void AuthScreen::on_signinButton_clicked()
{
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->PasswordLineEdit->text();

    QString role = getUserRole(username, password);

    if (role.isEmpty()) {
        QMessageBox::warning(this, "Hata", "Geçersiz kullanıcı adı veya şifre!");
        return;
    }

    if (role == "admin") {
        // Admin arayüzünü aç
        AdminDashboard *adminWindow = new AdminDashboard(this);
        adminWindow->show();
        this->close();
    } else if (role == "user") {
        // Kullanıcı arayüzünü aç
        UserDashboard *userWindow = new UserDashboard(this);
        userWindow->show();
        this->close();
    }
}

