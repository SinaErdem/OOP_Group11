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
    , bookManager()
    , currentUser("", "", "", gbookManager)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    userDashboard = new UserDashboard(currentUser, bookManager,this);
    userDashboard->hide();

}

AuthScreen::~AuthScreen()
{
    delete ui;
}

void AuthScreen::on_signupButton_clicked() //event listener mantığı
{
    SignUp *signupWindow = new SignUp(this, bookManager); // bookManager'ı doğru bir şekilde geçiriyorsunuz
    signupWindow->show();
}



QString AuthScreen::checkCredentials(const QString &username, const QString &password) { //userType döndürme amacıyla ve username& password kontrol amacıyla
    QFile file("C:/LibManager/LibManager/LBResources/users.txt");

    // Dosyanın varlığını kontrol et
    if (!file.exists()) {
        qDebug() << "Dosya bulunamadı!";
        return "";
    }

    // Dosyayı aç
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Dosya açılamadı!";
        return "";
    }

    QTextStream in(&file);

    // Dosya satırlarını kontrol et
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        // format: email,username,password,userType
        if (parts.size() == 4) {
            QString fileUsername = parts[1].trimmed(); // Username
            QString filePassword = parts[2].trimmed(); // Password
            QString userType = parts[3].trimmed();     // UserType

            qDebug() << "Kontrol edilen username:" << fileUsername;
            qDebug() << "Kontrol edilen password:" << filePassword;
            qDebug() << "Kontrol edilen userType:" << userType;

            // Kullanıcı adı ve şifre kontrolü
            if (fileUsername == username && filePassword == password) {
                file.close();
                return userType; // Kullanıcı doğrulandı
            }
        }
    }

    file.close();
    return ""; // Kullanıcı adı veya şifre yanlışsa
}





void AuthScreen::on_signinButton_clicked()
{
    QString username = ui->UsernameLineEdit->text(); // Kullanıcı adı
    QString password = ui->PasswordLineEdit->text(); // Şifre

    // Boş alan kontrolü
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Hata", "Lütfen kullanıcı adı ve şifreyi doldurun!");
        return;
    }

    // Kullanıcı doğrulama
    QString userType = checkCredentials(username, password);

    // Giriş başarısızsa
    if (userType.isEmpty()) {
        QMessageBox::warning(this, "Giriş Hatası", "Kullanıcı adı veya şifre yanlış.");
        return;
    }

    // `currentUser` bilgilerini güncelle  // Kullanıcı türünü güncelliyoruz
    currentUser.setm_username(username);
    currentUser.setm_password(password);
    currentUser.setm_userType(userType);  // Kullanıcı türünü ayarla

    // Kullanıcı türüne göre yönlendirme
    if (userType == "Admin") {
        QMessageBox::information(this, "Giriş Başarılı", "Admin paneline yönlendiriliyorsunuz.");
        AdminDashboard *adminDashboard = new AdminDashboard(this);
        adminDashboard->show();

    } else if (userType == "User") {
        QMessageBox::information(this, "Giriş Başarılı", "Kullanıcı paneline yönlendiriliyorsunuz.");
        userDashboard->show();

    } else {
        QMessageBox::warning(this, "Hata", "Geçersiz kullanıcı türü!");
    }
}






