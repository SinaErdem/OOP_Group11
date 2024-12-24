#include "userdashboard.h"
#include "signup.h"
#include "ui_userdashboard.h"
#include<QList>
#include<QFile>
#include <QListWidget>
#include<QMessageBox>
#include "book_management_fuser.h"
UserDashboard::UserDashboard(User& currentUser, QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDashboard), currentUser(currentUser)
{
    ui->setupUi(this);
    ui->bookListWidget->hide();
}

UserDashboard::~UserDashboard()
{

    delete ui;
}



void UserDashboard::on_BookList_button_clicked()
{
    displayBooks();

}
void UserDashboard::displayBooks()
{

    ui->bookListWidget->clear();  // Listeyi temizliyoruz

    // currentUser objesindeki kitapları alıyoruz
    for ( auto& book : currentUser.bookManager.library.allBooks()) {
        // Kitap bilgilerini formatlıyoruz ve ekliyoruz
        QString bookInfo = "Name: " + QString::fromStdString(book.getName()) + "\n"
                           + "Author: " + QString::fromStdString(book.getAuthor()) + "\n"
                           + "Genre: " + QString::fromStdString(book.getGenre()) + "\n"
                           + "ISBN: " + QString::fromStdString(book.getIsbn()) + "\n"
                           + "Number of books: " + QString::number(book.getNumber())+"\n";


        ui->bookListWidget->addItem(bookInfo);  // Kitapları Listeye Ekliyoruz
    }
    ui->bookListWidget->setVisible(true);
}


void UserDashboard::on_showBooksButton_clicked() {
    if (ui->bookListWidget->isVisible()) {
        ui->bookListWidget->hide();  // Kitap listesi görünüyorsa gizle
    } else {
        ui->bookListWidget->show();  // Kitap listesi gizliyse göster
        displayBooks();
    }
}
