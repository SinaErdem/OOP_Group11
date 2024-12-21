#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include <QDialog>

namespace Ui {
class UserDashboard;
}

class UserDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit UserDashboard(QWidget *parent = nullptr);
    ~UserDashboard();

private slots:
    void on_searchButton_clicked();

private:
    Ui::UserDashboard *ui;
    QList<QStringList> searchBooks(const QString &query, const QString &genreFilter);
};

#endif // USERDASHBOARD_H
