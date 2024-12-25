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
        QMessageBox::warning(this, "Error", "All fields must be filled!");
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open books file!");
        return;
    }

    QTextStream out(&file);
    out << bookName << "," << authorName << "," << genre << "," << isbn << "," << number << "\n";
    file.close();

    QMessageBox::information(this, "Success", "Book added successfully!");

    // Giriş alanlarını temizle
    ui->bookNameInput->clear();
    ui->authorNameInput->clear();
    ui->genreInput->clear();
    ui->isbnInput->clear();
    ui->numberInput->clear();
}

// Kitap kaldırma fonksiyonu
void AdminDashboard::removeBooks()
{
    QString bookName = ui->bookNameInput->text();
    if (bookName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter the name of the book to remove!");
        return;
    }

    QFile file("C:/LibManager/LibManager/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open books file!");
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
        QMessageBox::critical(this, "Error", "Cannot write to books file!");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Success", "Book removed successfully!");

    // Giriş alanını temizle
    ui->bookNameInput->clear();
}
