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






void AuthScreen::on_signinButton_clicked()
{
    QString username = ui->UsernameLineEdit->text(); // Kullanıcı adı
    QString password = ui->PasswordLineEdit->text(); // Şifre

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Hata", "Lütfen kullanıcı adı ve şifreyi doldurun!");
        return;
    }

    // Dosyadan okuma işlemi
    if (checkCredentials(username, password)) {
        QMessageBox::information(this, "Giriş Başarılı", "Başarıyla giriş yaptınız.");
        // Başarılı giriş sonrası yapılacak işlemler
        UserDashboard *userDashboard = new UserDashboard(this);
        userDashboard->show();
    } else {
        QMessageBox::warning(this, "Giriş Hatası", "Kullanıcı adı veya şifre yanlış.");
    }
}

bool AuthScreen::checkCredentials(const QString &username, const QString &password) {
    QFile file("C:/LibManager/LibManager/LBResources/admins.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Dosya açılamadı!";
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        // Eğer satırdaki kullanıcı adı ve şifre eşleşiyorsa
        if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
            file.close();
            return true;
        }
    }

    file.close();

    // Eğer admin.txt dosyasında bulunmazsa, users.txt dosyasını kontrol et
    file.setFileName("C:/LibManager/LibManager/LBResources/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Dosya açılamadı!";
        return false;
    }

    QTextStream inUser(&file);
    while (!inUser.atEnd()) {
        QString line = inUser.readLine();
        QStringList parts = line.split(",");

        // Eğer satırdaki kullanıcı adı ve şifre eşleşiyorsa
        if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


