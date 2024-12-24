#include "userdashboard.h"
#include "qboxlayout.h"
#include "signup.h"
#include "ui_userdashboard.h"
#include<QList>
#include<QFile>
#include <QListWidget>
#include<QMessageBox>
#include "book_management_fuser.h"
#include "QString"
UserDashboard::UserDashboard(User& currentUser, QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDashboard), currentUser(currentUser)
{
    ui->setupUi(this);
    ui->bookListWidget->hide();
    ui->filterComboBox->addItems({"Name", "Author", "ISBN"});
    ui->bookListWidget->hide();
    ui->resultsTableWidget->hide();
    ui->findButton->setCheckable(true);
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


void UserDashboard::populateResults(std::vector<Library_Database>& results) {
    ui->resultsTableWidget->clearContents();  // Önceki içerikleri temizle
    ui->resultsTableWidget->setRowCount(0);   // Satır sayısını sıfırla
    ui->resultsTableWidget->setColumnCount(4); // 4 sütun: Name, Author, ISBN, Borrow Button
    ui->resultsTableWidget->setHorizontalHeaderLabels({"Name", "Author", "ISBN", "Borrow Button"});

    // Tabloyu her zaman sıfırlayın ve yeniden yükleyin
    for (auto& book : results) {
        int row = ui->resultsTableWidget->rowCount();
        ui->resultsTableWidget->insertRow(row);  // Yeni bir satır ekleyin

        // Kitap bilgilerini tabloya ekleyin
        ui->resultsTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(book.getName())));
        ui->resultsTableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(book.getAuthor())));
        ui->resultsTableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(book.getIsbn())));

        // "Borrow Book" butonunu ekleyin
        QPushButton* borrowButton = new QPushButton("Borrow Book");
        connect(borrowButton, &QPushButton::clicked, this, &UserDashboard::borrowBook);

        // QPushButton'ı eklemek için QTableWidget'a yeni bir hücre (cell) ekle
        ui->resultsTableWidget->setCellWidget(row, 3, borrowButton);  // 3. sütunda buton
    }

    // Sütun genişliklerini ayarlayın
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);  // Name column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);  // Author column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);  // ISBN column
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);  // Borrow button column
}

void UserDashboard::borrowBook() {
    // Sender() fonksiyonundan gelen işaretçiyi hemen kullanın
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;  // Buton geçerli değilse çık

    // Seçilen satırın index'ini alın
    int row = ui->resultsTableWidget->currentRow();
    if (row < 0) return;  // Geçersiz satırsa çık

    // Kitap verisini almak için iterator kullanın
    auto it = currentUser.bookManager.library.allBooks().begin();
    std::advance(it, row);  // Iterator'u belirtilen satıra ilerlet

    Library_Database& book = *it;  // Iterator ile kitap verisini alın

    // Kitap sayısını bir azalt
    if (book.getNumber() > 0) {
        book.setNumber(book.getNumber() - 1); // Kitap sayısını azalt

        // Kitapları ödünç listesine ekle
        currentUser.borrowedBooks.push_back(book);

        // Kullanıcıya başarılı olduğunu bildirin
        QMessageBox::information(this, "Success", "Book added to borrowed list.");

        // Kitapları dosyaya kaydet (kitap sayısını güncelle)

        // Tabloyu yeniden güncelle
        // Mevcut arama sonuçlarını geçici olarak saklayın
        QString searchQuery = ui->searchLineEdit->text().trimmed();
        QString filterOption = ui->filterComboBox->currentText();

        std::vector<Library_Database> results;
        for (auto& book : currentUser.bookManager.library.allBooks()) {
            bool match = false;

            // Arama işlemi
            if (searchQuery.isEmpty()) {
                results.push_back(book);
            } else {
                std::string searchStr = searchQuery.toStdString();
                if (filterOption == "Name") {
                    std::string nameLower = book.getName();
                    std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
                    std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
                    match = nameLower.find(searchStr) != std::string::npos;
                } else if (filterOption == "Author") {
                    std::string authorLower = book.getAuthor();
                    std::transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
                    std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
                    match = authorLower.find(searchStr) != std::string::npos;
                } else if (filterOption == "ISBN") {
                    match = book.getIsbn().find(searchStr) != std::string::npos;
                }

                if (match) {
                    results.push_back(book);
                }
            }
        }

        // Güncellenmiş sonuçları tablonun üst kısmında göster
        populateResults(results);  // Sonuçları tekrar doldur
    } else {
        // Eğer kitap sayısı 0 ise, ödünç alınamaz
        QMessageBox::warning(this, "Error", "This book is out of stock.");
    }
}
void UserDashboard::on_findButton_toggled(bool checked) {
    if (!checked) {
        // Buton bırakıldı, sonuçları gizle
        ui->resultsTableWidget->hide();
        return;
    }

    // Buton basılı, arama yap ve sonuçları göster
    QString searchQuery = ui->searchLineEdit->text().trimmed();
    QString filterOption = ui->filterComboBox->currentText();

    if (searchQuery.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a search query.");
        ui->findButton->setChecked(false);  // Butonu normal hale getir
        return;
    }

    // Arama sonuçlarını temizle
    ui->resultsTableWidget->clearContents();  // Tabloyu temizle
    ui->resultsTableWidget->setRowCount(0);   // Satır sayısını sıfırla

    // Arama işlemi
    std::vector<Library_Database> results;
    for (auto& book : currentUser.bookManager.library.allBooks()) {
        bool match = false;

        // Filtreleme seçeneklerini kontrol et ve eşleştir
        std::string searchStr = searchQuery.toStdString();
        if (filterOption == "Name") {
            std::string nameLower = book.getName();
            std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
            match = nameLower.find(searchStr) != std::string::npos;
        } else if (filterOption == "Author") {
            std::string authorLower = book.getAuthor();
            std::transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
            std::transform(searchStr.begin(), searchStr.end(), searchStr.begin(), ::tolower);
            match = authorLower.find(searchStr) != std::string::npos;
        } else if (filterOption == "ISBN") {
            match = book.getIsbn().find(searchStr) != std::string::npos;
        }

        if (match) {
            results.push_back(book);
        }
    }

    // Sonuçları işleme
    if (results.empty()) {
        QMessageBox::information(this, "Info", "No books found.");
        ui->findButton->setChecked(false);  // Butonu normal hale getir
        ui->resultsTableWidget->hide();  // Sonuç yoksa listeyi gizle
        return;
    }

    populateResults(results);  // Sonuçları doldur
    ui->resultsTableWidget->show();  // Sonuçları göster
}
