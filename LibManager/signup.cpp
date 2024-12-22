#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QFileInfo>
#include<QVBoxLayout>
#include <QTextStream>
#include <QDir>


SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);

}



SignUp::~SignUp()
{
    delete ui;
}


int selectedUserType = -1;  // -1: No selection, 0: Admin, 1: User

// Admin butonuna tıklanınca
void SignUp::on_user_Button_clicked()
{
    selectedUserType = 0;
}

void SignUp::on_admin_Button_clicked()
{
    selectedUserType = 1;
}




// Email kontrol fonksiyonu
bool isValidEmail(const QString &email) {
    // Basit bir @ kontrolü
    return email.contains("@");
}

// Şifre kontrol fonksiyonu
bool isValidPassword(const QString &password) {
    // Şifre en az bir harf ve bir rakam içermelidir
    bool hasLetter = false;
    bool hasDigit = false;
    for (int i = 0; i < password.length(); ++i) {
        if (password[i].isLetter()) {
            hasLetter = true;
        } else if (password[i].isDigit()) {
            hasDigit = true;
        }
        if (hasLetter && hasDigit) {
            return true;
        }
    }
    return false;
}


void SignUp::on_signupButton_clicked() {
    if (selectedUserType == -1) {
        qDebug() << "Kullanıcı türü seçilmedi!";
        return;  // Kullanıcı türü seçilmediyse işlem yapma
    }

    QString email = ui->Mail_Line_Edit->text();
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->Password_Line_Edit->text();

    // Email kontrolü
    if (!isValidEmail(email)) {
        qDebug() << "Geçersiz email adresi!";
        return;  // Geçersiz email
    }

    // Şifre kontrolü
    if (!isValidPassword(password)) {
        qDebug() << "Şifre en az bir harf ve bir rakam içermelidir!";
        return;  // Geçersiz şifre
    }

    qDebug() << "Email: " << email;
    qDebug() << "Username: " << username;
    qDebug() << "Password: " << password;

    QString filePath;
    if (selectedUserType == 1) {
        // Admin dosyasına kaydet
        filePath = "C:/LibManager/LibManager/LBResources/admins.txt";
    } else if(selectedUserType == 0) {
        // User dosyasına kaydet
        filePath = "C:/LibManager/LibManager/LBResources/users.txt";
    }

    // Dizin kontrolü ve oluşturulması
    QDir dir;
    if (!dir.exists("C:/LibManager/LibManager/LBResources")) {
        qDebug() << "Dizin mevcut değil, oluşturuluyor...";
        dir.mkpath("C:/LibManager/LibManager/LBResources");  // Eğer dizin yoksa oluştur
    }

    QFile file(filePath);  // Seçilen türdeki dosyayı aç

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << email << "," << username << "," << password << "\n";
        file.close();
        qDebug() << "Veriler dosyaya kaydedildi.";
    } else {
        qDebug() << "Dosya açılamadı!" << file.errorString();
    }
}















