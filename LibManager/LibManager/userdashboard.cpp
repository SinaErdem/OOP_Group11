#include "userdashboard.h"
#include "qboxlayout.h"
#include "qdir.h"
#include "signup.h"
#include "ui_userdashboard.h"
#include<QList>
#include<QFile>
#include <QListWidget>
#include<QMessageBox>
#include "book_management_fuser.h"
#include "QString"
#include <QTimer>  // Burada da QTimer'ı dahil edin
#include <QMessageBox>
UserDashboard::UserDashboard(User& currentUser,Book_Management_fUser& bookManager ,QWidget *parent)
    : QDialog(parent), borrowTimer(nullptr), ui(new Ui::UserDashboard),currentUser(currentUser),bookManager(bookManager) // bookManager başlatılıyor
{
    ui->setupUi(this);
    ui->bookListWidget->hide();
    ui->filterComboBox->addItems({"Name", "Author", "ISBN"});
    ui->bookListWidget->hide();
    ui->resultsTableWidget->hide();
    ui->findButton->setCheckable(true);
    ui->barrowedbooks->hide();



}

UserDashboard::~UserDashboard()
{

    delete ui;
    if (borrowTimer) {
        delete borrowTimer;
    }
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
    borrowTimer = new QTimer(this);
    borrowTimer->setSingleShot(true);
    connect(borrowTimer, &QTimer::timeout, this, &UserDashboard::on_bookReturnTimeout);
    borrowTimer->start(bookBorrowDuration * 1000);
    // Sender() fonksiyonundan gelen işaretçiyi hemen kullanın
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;  // Buton geçerli değilse çık

    // Butonun bulunduğu satırı al
    int row = -1;
    for (int i = 0; i < ui->resultsTableWidget->rowCount(); ++i) {
        if (ui->resultsTableWidget->cellWidget(i, 3) == button) {  // 3. sütun "Borrow Button"
            row = i;
            break;
        }
    }

    if (row == -1) return;  // Satır bulunamadıysa çık

    // Tablodaki kitap bilgilerini al
    QString bookName = ui->resultsTableWidget->item(row, 0)->text();
    QString bookAuthor = ui->resultsTableWidget->item(row, 1)->text();
    QString bookISBN = ui->resultsTableWidget->item(row, 2)->text();

    // Kitap verisini kitaplıkta eşleştir
    Library_Database* book = nullptr;
    for (auto& b : currentUser.bookManager.library.allBooks()) {
        if (QString::fromStdString(b.getName()) == bookName &&
            QString::fromStdString(b.getAuthor()) == bookAuthor &&
            QString::fromStdString(b.getIsbn()) == bookISBN) {
            book = &b;
            break;
        }
    }

    if (!book) {
        QMessageBox::warning(this, "Error", "Book not found in library.");
        return;
    }

    // Kitap sayısını bir azalt
    if (book->getNumber() > 0) {
        book->setNumber(book->getNumber() - 1); // Kitap sayısını azalt

        // Kitapları ödünç listesine ekle
        currentUser.borrowedBooks.push_back(*book);

        // Kullanıcı için dosya oluştur ve kitabı kaydet
        QDir dir("C:/LibManager/LibManager/usersTXT");
        if (!dir.exists()) {
            dir.mkpath(".");  // Klasör yoksa oluştur
        }

        QString userFileName = dir.filePath(currentUser.getm_username() + ".txt");
        QFile userFile(userFileName);

        if (!userFile.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Cannot open user file for saving borrowed books.");
            return;
        }

        QTextStream out(&userFile);
        // Burada boşluksuz yazma işlemi yapılacak
        out << QString::fromStdString(book->getName())
            << "," << QString::fromStdString(book->getAuthor())
            << "," << QString::fromStdString(book->getGenre())
            << "," << QString::fromStdString(book->getIsbn()) << "\n";

        userFile.close();

        // Kullanıcıya başarılı olduğunu bildirin
        QMessageBox::information(this, "Success", "Book added to borrowed list and saved to file.");

        // Tabloyu yeniden güncelle
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


void UserDashboard::on_showBorrowedBooksButton_clicked()
{
    qDebug() << "Displaying borrowed books...";

    // Tabloyu kontrol et, görünürse gizle, görünür değilse göster
    if (ui->barrowedbooks->isVisible()) {
        // Eğer tablo görünüyorsa, gizle
        ui->barrowedbooks->setVisible(false);
        qDebug() << "Table hidden.";
    } else {
        // Eğer tablo görünmüyorsa, göster
        ui->barrowedbooks->setVisible(true);
        qDebug() << "Table shown.";

        // Tabloyu temizle
        ui->barrowedbooks->clearContents();
        ui->barrowedbooks->setRowCount(0); // Mevcut satırları temizle

        // Sütun sayısını ayarlayın (Kitap Adı, Yazar, Tür, ISBN, Buton)
        ui->barrowedbooks->setColumnCount(5);  // 4 kitap bilgisi + 1 buton
        ui->barrowedbooks->setHorizontalHeaderLabels({"Book Name", "Author", "Genre", "ISBN", "Action"});

        // Kullanıcı dosyasını al
        QString userFileName = "C:/LibManager/LibManager/usersTXT/" + currentUser.getm_username() + ".txt";
        QFile userFile(userFileName);

        // Dosyanın varlığını kontrol et
        if (!userFile.exists()) {
            qDebug() << "User file not found.";
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
            return;
        }

        // Dosyayı aç
        if (!userFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Cannot open user file.";
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("Error reading borrowed books."));
            return;
        }

        QTextStream in(&userFile);
        QString line;
        bool foundBooks = false;

        // Dosyadaki her bir satırı işle
        while (!in.atEnd()) {
            line = in.readLine().trimmed();
            QStringList bookDetails = line.split(",");

            // Kitap bilgilerini kontrol et
            if (bookDetails.size() == 4) {
                QString bookName = bookDetails[0].trimmed();
                QString bookAuthor = bookDetails[1].trimmed();
                QString bookGenre = bookDetails[2].trimmed();
                QString bookIsbn = bookDetails[3].trimmed();

                // Yeni satır ekle
                int row = ui->barrowedbooks->rowCount();
                ui->barrowedbooks->insertRow(row);

                // Kitap bilgilerini tabloya ekle
                ui->barrowedbooks->setItem(row, 0, new QTableWidgetItem(bookName));
                ui->barrowedbooks->setItem(row, 1, new QTableWidgetItem(bookAuthor));
                ui->barrowedbooks->setItem(row, 2, new QTableWidgetItem(bookGenre));
                ui->barrowedbooks->setItem(row, 3, new QTableWidgetItem(bookIsbn));

                // "Return Book" butonu oluştur
                QPushButton* returnButton = new QPushButton("Return Book");
                returnButton->setProperty("bookName", bookName); // Kitap ismini butona ekle

                // Buton sinyalini slota bağla
                connect(returnButton, &QPushButton::clicked, this, &UserDashboard::on_returnBookClicked);

                // Tabloya butonu ekle
                ui->barrowedbooks->setCellWidget(row, 4, returnButton);

                qDebug() << "Book added to the list:" << bookName;
                foundBooks = true;
            }
        }

        if (!foundBooks) {
            ui->barrowedbooks->setRowCount(1);
            ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
        }

        userFile.close();
    }
}

void UserDashboard::on_returnBookClicked() {
    // Kitap geri verildiğinde zamanlayıcıyı durdur
    if (borrowTimer) {
        borrowTimer->stop();
    }
    qDebug() << "Book returned successfully.";
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) {
        qDebug() << "Error: Button is invalid!";
        return;
    }

    QString bookName = button->property("bookName").toString().simplified();  // Kitap adını al ve boşlukları temizle
    qDebug() << "Retrieved book name from button: '" << bookName << "'";  // Butondan alınan kitap adı debug'da yazdır

    auto& borrowedBooks = currentUser.borrowedBooks;
    qDebug() << "Number of borrowed books before return:" << borrowedBooks.size();

    // Kullanıcı dosyasının yolunu oluştur
    QString userFileName = "C:/LibManager/LibManager/usersTXT/" + currentUser.getm_username() + ".txt";
    QFile userFile(userFileName);
    if (!userFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open user file.");
        return;
    }

    QTextStream in(&userFile);
    QStringList lines;
    bool bookFound = false;

    // Dosyadaki her satırı oku ve kitap adı eşleşen satırı hariç tut
    while (!in.atEnd()) {
        QString line = in.readLine().simplified();  // Ekstra boşlukları kaldır
        QStringList bookDetails = line.split(",");

        // Kitap adı eşleştiğinde satırı hariç tut
        if (bookDetails.size() >= 4 && bookDetails[0].simplified() == bookName) {
            bookFound = true;  // Kitap bulundu
            qDebug() << "Found matching book in user file: " << bookDetails[0];
        } else {
            lines.append(line); // Diğer kitapları tut
        }
    }

    // Eğer kitap bulunduysa dosyayı güncelle
    if (bookFound) {
        // Dosyayı temizle
        userFile.resize(0);
        QTextStream out(&userFile);
        for (const QString& line : lines) {
            out << line << "\n"; // Kalan kitapları tekrar dosyaya yaz
        }
        QMessageBox::information(this, "Success", "Book returned successfully and removed from your list.");
        qDebug() << "Book removed from user file.";
    } else {
        QMessageBox::warning(this, "Error", "Book not found in user file.");
    }

    // Listeyi güncelle
    on_showBorrowedBooksButton_clicked();
}
void UserDashboard::on_bookReturnTimeout() {
    // Zaman aşımı olursa uyarı mesajı göster
    QMessageBox::warning(this, "Time expired", "You did not return the book within the allotted time. Please return the book as soon as possible.");
}



