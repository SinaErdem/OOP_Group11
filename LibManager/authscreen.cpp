#include "authscreen.h"
#include "ui_authscreen.h"

AuthScreen::AuthScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AuthScreen)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
}

AuthScreen::~AuthScreen()
{
    delete ui;
}

void AuthScreen::on_signinButton_clicked()
{

}

