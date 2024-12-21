#include "userdashboard.h"
#include "ui_userdashboard.h"
#include<QList>
#include<QFile>
#include<QMessageBox>
UserDashboard::UserDashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDashboard)
{
    ui->setupUi(this);
}

UserDashboard::~UserDashboard()
{
    delete ui;
}

QList<QStringList> UserDashboard::searchBooks(const QString &query, const QString &genreFilter)
{
    QList<QStringList> results; // Sonuçları saklamak için

    QFile file("books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Hata", "Kitap dosyası açılamadı!");
        return results;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() < 4) continue;

        QString title = fields[1];
        QString genre = fields[3];

        // Arama ve filtreleme
        if ((query.isEmpty() || title.contains(query, Qt::CaseInsensitive)) &&
            (genreFilter.isEmpty() || genre == genreFilter)) {
            results.append(fields); // Uygun kitapları sonuçlara ekle
        }
    }

    file.close();
    return results;
}

void UserDashboard::on_searchButton_clicked()
{
    QString query = ui->searchLineEdit->text();
    QString genreFilter = ui->genreComboBox->currentText();

    QList<QStringList> results = searchBooks(query, genreFilter);

    // Arama sonuçlarını tabloda gösterme
    ui->resultsTableWidget->setRowCount(0);
    for (int i = 0; i < results.size(); ++i) {
        const QStringList &book = results[i];
        ui->resultsTableWidget->insertRow(i);
        for (int j = 0; j < book.size(); ++j) {
            ui->resultsTableWidget->setItem(i, j, new QTableWidgetItem(book[j]));
        }
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "Bilgi", "Hiçbir sonuç bulunamadı.");
    }
}

