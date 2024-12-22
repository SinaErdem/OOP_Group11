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



private:
    Ui::UserDashboard *ui;

};

#endif // USERDASHBOARD_H
