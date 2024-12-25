#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H


#include <QDialog>

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();

private slots:
    void addBooks();  // Kitap ekleme fonksiyonu
    void removeBooks();  // Kitap kaldırma fonksiyonu
    void addUsers();
    void removeUsers();


private:
    Ui::AdminDashboard *ui;
};


#endif // ADMINDASHBOARD_H
