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
    adminButton = new QPushButton("Admin", this);
    adminButton->setGeometry(170, 100, 101, 41);

    // Odak politikası
    adminButton->setFocusPolicy(Qt::StrongFocus);

    // Stil sayfası
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );

    userButton = new QPushButton("User", this);

    userButton->setGeometry(40, 100, 101, 41);

    // Odak politikası
    userButton->setFocusPolicy(Qt::StrongFocus);

    // Stil sayfası
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );

    connect(adminButton, &QPushButton::clicked, this, &SignUp::on_admin_Button_clicked);
    connect(userButton, &QPushButton::clicked, this, &SignUp::on_user_Button_clicked);



}



SignUp::~SignUp()
{
    delete ui;
}


int selectedUserType = -1;  // -1: No selection, 0: user, 1: admin

// Admin butonuna tıklanınca
void SignUp::on_user_Button_clicked()
{
    selectedUserType = 0;
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    	background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(70, 149, 37, 255), stop:1 rgba(10, 101, 0, 255));"
        "       color:black;"
        "    font: 300 10pt 'Calibri';"
        "}"
        "QPushButton:hover {"
        "    background-color: rgb(0, 100, 0);"
        "}"
        );
    userButton->setGeometry(userButton->x() + 2,userButton->y() + 2, userButton->width() - 2, userButton->height() - 2);

    // Admin butonunu varsayılan stile döndür
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );
    adminButton->setGeometry(170, 100, 101, 41);

}

void SignUp::on_admin_Button_clicked()
{
    selectedUserType = 1;
    adminButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    	background-color: qlineargradient(spread:reflect, x1:0.484, y1:0.534091, x2:0.479, y2:1, stop:0 rgba(70, 149, 37, 255), stop:1 rgba(10, 101, 0, 255));"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "}"
        "QPushButton:hover {"
        "    background-color: rgb(0, 100, 0);"
        "}"
        );
    adminButton->setGeometry(adminButton->x() + 2, adminButton->y() + 2, adminButton->width() - 2, adminButton->height() - 2);

    // User butonunu varsayılan stile döndür
    userButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"
        "    color: black;"
        "    font: 300 10pt 'Calibri';"
        "    background-color: qlineargradient("
        "        spread: reflect, x1: 0.484, y1: 0.534091, x2: 0.479, y2: 1,"
        "        stop: 0 rgba(90, 191, 47, 255),"
        "        stop: 1 rgba(13, 134, 0, 255)"
        "    );"
        "}"
        );
    userButton->setGeometry(40,100,101,41);
}




// Email kontrol fonksiyonu
bool isValidEmail(const QString &email) {
    // Regex tanımlaması
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    // E-posta doğrulaması
    QRegularExpressionMatch match = emailRegex.match(email);
    return match.hasMatch();
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
    QString userType;
    if (selectedUserType == -1) {
        qDebug() << "Kullanıcı türü seçilmedi!";
        QMessageBox::warning(this, "Kayıt olma hatası", "Lütfen Kullanıcı türü seçiniz.");

        return;  // kullanıcı işlemi yapmadıysa işlem yapma
    }else if(selectedUserType==0){//user
         userType ="User";


    }else if(selectedUserType==1){//Admin
         userType ="Admin";
    }

    QString email = ui->Mail_Line_Edit->text();
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->Password_Line_Edit->text();


    // Email kontrolü
    if (!isValidEmail(email)) {
        qDebug() << "Geçersiz email adresi!";
        QMessageBox::warning(this, "Kayıt olma hatası", "Geçersiz e-mail Adresi Girdiniz!");
        return;  // Geçersiz email
    }

    // Şifre kontrolü
    if (!isValidPassword(password)) {
        QMessageBox::warning(this, "Kayıt olma hatası", "Şifre en az bir harf ve bir rakam içermelidir!");
        qDebug() << "Şifre en az bir harf ve bir rakam içermelidir!";
        return;  // Geçersiz şifre
    }

    qDebug() << "Email: " << email;
    qDebug() << "Username: " << username;
    qDebug() << "Password: " << password;
    qDebug() <<"UserType:"<< userType;
    QString  filePath = "C:/LibManager/LibManager/LBResources/users.txt";


    // Dizin kontrolü ve oluşturulması
    QDir dir;
    if (!dir.exists("C:/LibManager/LibManager/LBResources")) {
        qDebug() << "Dizin mevcut değil, oluşturuluyor...";
        dir.mkpath("C:/LibManager/LibManager/LBResources");  // Eğer dizin yoksa oluştur
    }

    QFile file(filePath);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << email << "," << username << "," << password << "," << userType <<"\n"; //format
        file.close();
        qDebug() << "Veriler dosyaya kaydedildi.";
    } else {
        qDebug() << "Dosya açılamadı!" << file.errorString();
    }
}
















void SignUp::on_Back_Button_clicked()
{
    window()->close();
}

