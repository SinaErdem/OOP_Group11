#include "signup.h"
#include "book_management_fuser.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QTextStream>
#include <QDir>
#include "admin.h"
#include "user.h"



SignUp::SignUp(QWidget *parent, Book_Management_fUser& bookManager)
    : QDialog(parent)
    , ui(new Ui::SignUp)
    , bookManager(bookManager)
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

    // Kullanıcı türü seçilip seçilmediğini kontrol et
    if (selectedUserType == -1) {
        qDebug() << "User type not selected!";
        QMessageBox::warning(this, "Registration error", "Please select a user type.");
        return;
    }

    QString email = ui->Mail_Line_Edit->text();
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->Password_Line_Edit->text();

    // Email doğrulama
    if (!isValidEmail(email)) {
        qDebug() << "Invalid email!";
        QMessageBox::warning(this, "Registration error", "Invalid email address.");
        return;
    }

    // Şifre doğrulama
    if (!isValidPassword(password)) {
        qDebug() << "Password must contain at least one letter and one digit!";
        QMessageBox::warning(this, "Registration error", "Password must contain at least one letter and one digit.");
        return;
    }

    qDebug() << "Email: " << email;
    qDebug() << "Username: " << username;
    qDebug() << "Password: " << password;

    // Uygun kullanıcı nesnesini oluştur
    if (selectedUserType == 0) {  // User
        User user(email, username, password, bookManager);  // *bookManager kullanılıyor çünkü işaretçi
        user.saveUserInfo();
        QMessageBox::information(this, "Registration", "User registered successfully!");
    } else if (selectedUserType == 1) {  // Admin
        Admin admin(email, username, password);
        admin.saveUserInfo();
        QMessageBox::information(this, "Registration", "Admin registered successfully!");
    }
}
void SignUp::on_Back_Button_clicked()
{
    window()->close();
}















