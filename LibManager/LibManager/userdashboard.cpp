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


