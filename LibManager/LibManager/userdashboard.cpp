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
#include "user.h"

#include <QTimer>  // Burada da QTimer'ı dahil edin
#include <QMessageBox>
 // bookManager başlatılıyor

UserDashboard::UserDashboard(User& currentUser,Book_Management_fUser& bookManager ,QWidget *parent)
    : QDialog(parent), ui(new Ui::UserDashboard), currentUser(currentUser),bookManager(bookManager) // bookManager başlatılıyor

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
        // Kitap bulunamadığında uyarı ver
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Book not found in library.");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        msgBox.exec();
        return;
    }

    // Aynı kitabın kullanıcı tarafından zaten ödünç alınmış olup olmadığını kontrol et
    for (auto& borrowedBook : currentUser.borrowedBooks) {
        if (borrowedBook.getName() == bookName &&
            borrowedBook.getAuthor() == bookAuthor &&
            borrowedBook.getIsbn() == bookISBN) {
            // Kitap daha önce ödünç alınmışsa uyarı göster
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
            msgBox.setWindowTitle("Info");        // Başlık
            msgBox.setText("You can not borrow the same book more than once by our policy.");  // Mesaj metni
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");
            msgBox.exec();
            return;
        }
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
            // Dosya açılamadıysa hata mesajı ver
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Critical);  // Uyarı simgesi
            msgBox.setWindowTitle("Error");        // Başlık
            msgBox.setText("Cannot open user file for saving borrowed books.");  // Mesaj metni
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");
            msgBox.exec();
            return;
        }

        QTextStream out(&userFile);
        out << QString::fromStdString(book->getName())
            << "," << QString::fromStdString(book->getAuthor())
            << "," << QString::fromStdString(book->getGenre())
            << "," << QString::fromStdString(book->getIsbn()) << "\n";

        userFile.close();

        // Kullanıcıya başarılı olduğunu bildirin
        QMessageBox info1;
        info1.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        info1.setIcon(QMessageBox::Information);  // Uyarı simgesi
        info1.setWindowTitle("Success");        // Başlık
        info1.setText("Book added to borrowed list and saved to file.");  // Mesaj metni
        info1.setStandardButtons(QMessageBox::Ok);    // Ok butonu
        info1.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        info1.exec();

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
        borrowTimer = new QTimer(this);
        borrowTimer->setSingleShot(true);
        connect(borrowTimer, &QTimer::timeout, this, &UserDashboard::on_bookReturnTimeout);
        borrowTimer->start(bookBorrowDuration * 1000);
    } else {
        // Kitap sayısı 0 ise, ödünç alınamaz
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("This book is out of stock.");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");
        msgBox.exec();
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
        //QMessageBox::warning(this, "Error", "Please enter a search query.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("Error");        // Başlık
        msgBox.setText("Please enter a search query.");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
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
        //QMessageBox::information(this, "Info", "No books found.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
        msgBox.setWindowTitle("Info");        // Başlık
        msgBox.setText("No books found.");  // Mesaj metni
        msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

        // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }"
                             "QMessageBox { color: white; background-color: transparent; }");

        // Mesaj kutusunu göster
        msgBox.exec();
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
    // Butona tıklanan kitabın adı bilgisini al
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString bookName = button->property("bookName").toString();
    qDebug() << "Book returned: " << bookName;

    // Kitap bilgilerini içeren dosyayı güncelle
    QString filename = "C:/LibManager/LibManager/usersTXT/" + currentUser.getm_username() + ".txt"; // Dosya yolu (username.txt)

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        //QMessageBox::warning(this, "Dosya Hatası", "Kitap bilgileri dosyası açılamadı.");
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
        msgBox.setWindowTitle("File Error");        // Başlık
        msgBox.setText("The book data file could not be opened.");  // Mesaj metni
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
    QStringList lines;
    bool bookFound = false;

    // Dosyadaki tüm satırları oku ve satırı silmek için yeniden yaz
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        // Kitap adını virgüle kadar al
        QString currentBookName = parts[0].trimmed();

        // Eğer kitap adı ile eşleşen satır varsa, bu satırı atla (sil)
        if (currentBookName.compare(bookName.trimmed(), Qt::CaseInsensitive) == 0) {
            bookFound = true;
            qDebug() << "Book removed from file: " << bookName;
            continue;  // Bu satırı geç (sil)
        }

        lines.append(line);  // Diğer satırları sakla
    }

    if (!bookFound) {
        qDebug() << "Book not found in file.";
        return;
    }

    // Dosyanın başına geri dön ve içeriği temizle
    file.resize(0);
    QTextStream out(&file);

    // Geriye kalan satırları dosyaya tekrar yaz
    for (const QString& line : lines) {
        out << line << "\n";
    }
    file.close();

    // Kullanıcıya geri bildirim yap
    //QMessageBox::information(this, "Success", "The book has been successfully returned.");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
    msgBox.setWindowTitle("Success");        // Başlık
    msgBox.setText("The book has been successfully returned.");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();

    // Tabloyu güncelle
    ui->barrowedbooks->clearContents();
    ui->barrowedbooks->setRowCount(0); // Mevcut satırları temizle

    QFile userFile(filename);

    if (!userFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open user file.";
        ui->barrowedbooks->setRowCount(1);
        ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("Error reading borrowed books."));
        return;
    }

    QTextStream updatedIn(&userFile);
    QString updatedLine;
    bool foundBooks = false;

    // Dosyadaki her bir satırı işle
    while (!updatedIn.atEnd()) {
        updatedLine = updatedIn.readLine().trimmed();
        QStringList bookDetails = updatedLine.split(",");

        if (bookDetails.size() == 4) {
            QString updatedBookName = bookDetails[0].trimmed();
            QString bookAuthor = bookDetails[1].trimmed();
            QString bookGenre = bookDetails[2].trimmed();
            QString bookIsbn = bookDetails[3].trimmed();

            int row = ui->barrowedbooks->rowCount();
            ui->barrowedbooks->insertRow(row);

            // Tabloya kitap bilgilerini ekle
            ui->barrowedbooks->setItem(row, 0, new QTableWidgetItem(updatedBookName));
            ui->barrowedbooks->setItem(row, 1, new QTableWidgetItem(bookAuthor));
            ui->barrowedbooks->setItem(row, 2, new QTableWidgetItem(bookGenre));
            ui->barrowedbooks->setItem(row, 3, new QTableWidgetItem(bookIsbn));

            // "Return Book" butonunu ekle
            QPushButton* returnButton = new QPushButton("Return Book");
            returnButton->setProperty("bookName", updatedBookName);
            connect(returnButton, &QPushButton::clicked, this, &UserDashboard::on_returnBookClicked);
            ui->barrowedbooks->setCellWidget(row, 4, returnButton);

            foundBooks = true;
        }
    }

    if (!foundBooks) {
        ui->barrowedbooks->setRowCount(1);
        ui->barrowedbooks->setItem(0, 0, new QTableWidgetItem("No borrowed books found."));
    }

    userFile.close();
    if (borrowTimer && borrowTimer->isActive()) {
        borrowTimer->stop();
        qDebug() << "Borrow timer stopped.";
    }
}


void UserDashboard::on_bookReturnTimeout() {
    // Zaman aşımı olursa uyarı mesajı göster
    //QMessageBox::warning(this, "Time expired", "You did not return the book within the allotted time. Please return the book as soon as possible.");
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    msgBox.setIcon(QMessageBox::Warning);  // Uyarı simgesi
    msgBox.setWindowTitle("Time Expired!");        // Başlık
    msgBox.setText("You did not return the book within the allotted time.\nPlease return the book as soon as possible.");  // Mesaj metni
    msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

    // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
    msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                         "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                         "QPushButton:hover { background-color: #888; }"
                         "QMessageBox { color: white; background-color: transparent; }");

    // Mesaj kutusunu göster
    msgBox.exec();
    // bookIsbn değişkeninin doğru şekilde tanımlandığından emin olun
    QString bookIsbn = "some_isbn_value";  // Burada gerçek ISBN değeri olmalı

    auto it = std::find_if(currentUser.borrowedBooks.begin(), currentUser.borrowedBooks.end(),
                           [bookIsbn](const Library_Database& book) {
                               return QString::fromStdString(book.getIsbn()).trimmed() == bookIsbn;
                           });

    if (it != currentUser.borrowedBooks.end()) {
        qDebug() << "Book found:" << QString::fromStdString(it->getName());
        try {
            // bookManager nesnesinin doğru şekilde tanımlandığından emin olun
            bookManager.returnBook(*it); // Kitabı iade et
            qDebug() << "Book successfully returned.";
            //QMessageBox::information(this, "Success", "Book returned successfully.");
            QMessageBox msgBox;
            msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
            msgBox.setIcon(QMessageBox::Information);  // Uyarı simgesi
            msgBox.setWindowTitle("Success!");        // Başlık
            msgBox.setText("Just in time!\nThanks for returning the book.");  // Mesaj metni
            msgBox.setStandardButtons(QMessageBox::Ok);    // Ok butonu

            // Stil sayfası ile arka plan siyah, yazılar beyaz yapılır
            msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                                 "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                                 "QPushButton:hover { background-color: #888; }"
                                 "QMessageBox { color: white; background-color: transparent; }");

            // Mesaj kutusunu göster
            msgBox.exec();
            on_showBorrowedBooksButton_clicked(); // Listeyi güncelle
        } catch (std::runtime_error& e) {
            QMessageBox::critical(this,"Error",e.what());
            qDebug() << "Error during returnBook:" << e.what();
        }
    }
}








