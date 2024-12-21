#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>
#include <QString>
#include <QRegularExpression>
#include<QVBoxLayout>

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


void showSuccessPopup(QWidget *parent) {
    QDialog *dialog = new QDialog(parent);
    dialog->setWindowTitle("Başarılı");
    dialog->resize(300, 150);

    // QVBoxLayout ile düzen
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    // Başarı mesajı için QLabel
    QLabel *label = new QLabel("Kayıt işlemi başarıyla tamamlandı!", dialog);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 16px; color: green;"); // CSS tarzı
    layout->addWidget(label);

    // Kapat butonu
    QPushButton *closeButton = new QPushButton("Kapat", dialog);
    closeButton->setStyleSheet("background-color: green; color: white; font-weight: bold; padding: 5px;");
    layout->addWidget(closeButton);

    QAbstractButton::connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setStyleSheet("background-color: #f0f0f0; border: 1px solid green; border-radius: 10px;"); // Popup genel stili
    dialog->exec();
}

void SignUp::on_Back_Button_clicked()
{
    this->close();

}
void SignUp::on_signupButton_clicked()
{
    QString name = ui->Name_Line_Edit->text();
    QString surname = ui->Surname_Line_Edit->text();
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->Password_Line_Edit->text();
    QString email = ui->Mail_Line_Edit->text();
    QString role =ui->roleComboBox->currentText();



    if (username.isEmpty() || password.isEmpty() || email.isEmpty()|| name.isEmpty()|| surname.isEmpty() ||role.isEmpty() ) {
        QMessageBox::warning(this, "Hata", "Tüm alanlar doldurulmalıdır!");
        return;

}
    if(isUserExist(username,email)){
    QMessageBox::warning(this,"Hata","Bu kullanıcı adı veya e-posta zaten kayıtlı!");
        return;
    }
    if (password.length() < 8) {
        QMessageBox::warning(this, "Hata", "Şifre en az 8 karakter uzunluğunda olmalıdır!");
        return;
    }
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Hata", "Geçerli bir e-posta adresi giriniz!");
        return;
    }


    saveToFile(username,email,password,role);
    showSuccessPopup(this);
}
void SignUp::saveToFile(const QString &username,const QString &email,const QString &password,const QString &role)
{
    QFile file("users.txt");

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Hata", "Dosya açılamadı!");
        return;
    }

    QTextStream out(&file);
    //yazma out ile
    out << username << "," << email << "," << password << "," << role<< "\n";
    file.close();

    QMessageBox::information(this, "Başarılı", "Kayıt başarıyla tamamlandı!");
}
bool SignUp::isUserExist(const QString &username, const QString &email)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Hata", "Dosya açılamadı!");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 2) {
            QString existingUsername = fields[0];
            QString existingEmail = fields[1];
            if (username == existingUsername || email == existingEmail) {
                return true;
            }
        }
    }

    file.close();
    return false;
}

