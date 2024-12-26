#include "admindashboard.h"
#include "ui_admindashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

// QDialog'a türetme
AdminDashboard::AdminDashboard(QWidget *parent) :
    QDialog(parent),  // QWidget yerine QDialog
    ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);

    // Butonlara fonksiyonları bağlayalım
    connect(ui->addBooksButton, &QPushButton::clicked, this, &AdminDashboard::addBooks);
    connect(ui->removeBooksButton, &QPushButton::clicked, this, &AdminDashboard::removeBooks);
    connect(ui->addUserButton, &QPushButton::clicked, this, &AdminDashboard::addUsers);
    connect(ui->RemoveUserButton, &QPushButton::clicked, this, &AdminDashboard::removeUsers);
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

// Kitap ekleme fonksiyonu
void AdminDashboard::addBooks()
{
    QString bookName = ui->bookNameInput->text();
    QString authorName = ui->authorNameInput->text();
    QString genre = ui->genreInput->text();
    QString isbn = ui->isbnInput->text();
    QString number = ui->numberInput->text();

    if (bookName.isEmpty() || authorName.isEmpty() || genre.isEmpty() || isbn.isEmpty() || number.isEmpty()) {
        //QMessageBox::warning(this, "Error", "All fields must be filled!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("All fields must be filled!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        //QMessageBox::critical(this, "Error", "Cannot open books file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot open books file!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QTextStream out(&file);
    out << bookName << ", " << authorName << ", " << genre << ", " << isbn << ", " << number << "\n";
    file.close();

    //QMessageBox::information(this, "Success", "Book added successfully!");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("Book added successfully!");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();

    // Giriş alanlarını temizle
    ui->bookNameInput->clear();
    ui->authorNameInput->clear();
    ui->genreInput->clear();
    ui->isbnInput->clear();
    ui->numberInput->clear();
}

void AdminDashboard::addUsers()
{
    QString email = ui->EmailInput->text();
    QString username = ui->UsernameInput->text();
    QString password = ui->UserPasswordInput->text();
    QString role = ui->UserComboBox->currentText(); // Role bilgisi comboBox'tan alınır

    // Tüm alanlar doldurulmuş mu kontrol et
    if (email.isEmpty() || username.isEmpty() || password.isEmpty() || role.isEmpty()) {
        //QMessageBox::warning(this, "Error", "All fields must be filled!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("All fields must be filled!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    // Dosyayı oku ve e-posta veya kullanıcı adı zaten var mı kontrol et
    QFile file("C:/LibManager/LibManager/LBResources/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //QMessageBox::critical(this, "Error", "Cannot open users file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot open users file!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");

        // E-posta veya kullanıcı adı zaten mevcutsa, hata mesajı göster
        if (userDetails.size() >= 2 &&
            (userDetails[0] == email || userDetails[1] == username)) {
            QMessageBox::warning(this, "Error", "Email or username already exists!");
            file.close();
            return;
        }
    }
    file.close();

    // Kullanıcıyı dosyaya eklemek için dosyayı yazma modunda aç
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        //QMessageBox::critical(this, "Error", "Cannot open users file for writing!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot open users file for writing!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QTextStream out(&file);
    // Kullanıcıyı email, username, password, role formatında dosyaya yaz
    out << email << "," << username << "," << password << "," << role << "\n";
    file.close();

    //QMessageBox::information(this, "Success", "User added successfully!");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("User added successfully!");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();

    // Giriş alanlarını temizle
    ui->EmailInput->clear();
    ui->UsernameInput->clear();
    ui->UserPasswordInput->clear();
    ui->UserComboBox->setCurrentIndex(0); // ComboBox'ı ilk seçeneğe döndür
}


// Kitap kaldırma fonksiyonu
void AdminDashboard::removeBooks()
{
    QString bookName = ui->removeBookInput->text();
    if (bookName.isEmpty()) {
        //QMessageBox::warning(this, "Error", "Please enter the name of the book to remove!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Please enter the name of the book to remove!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //QMessageBox::critical(this, "Error", "Cannot open books file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot open books file!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.startsWith(bookName + ",")) {
            lines.append(line);
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        //QMessageBox::critical(this, "Error", "Cannot write to books file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot write to books file!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    //QMessageBox::information(this, "Success", "Book removed successfully!");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("Book removed successfully!");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();

    // Giriş alanını temizle
    ui->bookNameInput->clear();
}
void AdminDashboard::removeUsers()
{
    QString usernameToRemove = ui->removeUserInput->text().trimmed();
    if (usernameToRemove.isEmpty()) {
        //QMessageBox::warning(this, "Error", "Please enter the username to remove!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Please enter the username to remove!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();

        return;
    }

    QFile file("C:/LibManager/LibManager/LBResources/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //QMessageBox::critical(this, "Error", "Cannot open users file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Cannot open users file!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    bool userFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");

        // Username, kayıt sisteminde ikinci sütunda (index 1)
        if (userDetails.size() >= 2 && userDetails[1] == usernameToRemove) {
            userFound = true; // Kullanıcı bulundu
            continue; // Bu satırı listeden çıkar
        }
        lines.append(line); // Kalan satırları ekle
    }
    file.close();

    if (!userFound) {
        //QMessageBox::warning(this, "Error", "User not found!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("User not found!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        //QMessageBox::critical(this, "Error", "Cannot write to users file!");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("User not found!");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    //QMessageBox::information(this, "Success", "User removed successfully!");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("User removed successfully!");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();
    // Giriş alanını temizle
    ui->removeUserInput->clear();
}

