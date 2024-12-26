/**
 * @file authscreen.cpp
 * @brief Implementation of the AuthScreen class for user authentication.
 */

#include "authscreen.h"
#include "ui_authscreen.h"
#include "signup.h"
#include "admindashboard.h"
#include "userdashboard.h"
#include <QFile>
#include <QString>
#include <QMessageBox>

/**
 * @brief Constructor for AuthScreen.
 * @param parent The parent widget.
 */
AuthScreen::AuthScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AuthScreen)
    , bookManager()
    , currentUser("", "", "", gbookManager)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
    userDashboard = new UserDashboard(currentUser, bookManager, this);
    userDashboard->hide();
}

/**
 * @brief Destructor for AuthScreen.
 */
AuthScreen::~AuthScreen()
{
    delete ui;
}

/**
 * @brief Event handler for the signup button click event.
 */
void AuthScreen::on_signupButton_clicked()
{
    SignUp *signupWindow = new SignUp(this, bookManager);
    signupWindow->show();
}

/**
 * @brief Verifies user credentials against a stored user database.
 * @param username The username provided by the user.
 * @param password The password provided by the user.
 * @return The user type if credentials are valid, otherwise an empty string.
 */
QString AuthScreen::checkCredentials(const QString &username, const QString &password)
{
    QFile file("C:/LibManager/LibManager/LBResources/users.txt");

    if (!file.exists()) {
        qDebug() << "File not found!";
        return "";
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file!";
        return "";
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        if (parts.size() == 4) {
            QString fileUsername = parts[1].trimmed();
            QString filePassword = parts[2].trimmed();
            QString userType = parts[3].trimmed();

            if (fileUsername == username && filePassword == password) {
                file.close();
                return userType;
            }
        }
    }

    file.close();
    return "";
}

/**
 * @brief Event handler for the sign-in button click event.
 */
void AuthScreen::on_signinButton_clicked()
{
    QString username = ui->UsernameLineEdit->text();
    QString password = ui->PasswordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Please enter username and password");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }");
        msgBox.exec();
        return;
    }

    QString userType = checkCredentials(username, password);

    if (userType.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Authentication Error");
        msgBox.setText("Username or password is wrong.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }");
        msgBox.exec();
        return;
    }

    currentUser.setm_username(username);
    currentUser.setm_password(password);
    currentUser.setm_userType(userType);

    if (userType == "Admin") {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Authentication Successful");
        msgBox.setText("Redirecting to Admin Dashboard...");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }");
        msgBox.exec();

        AdminDashboard *adminDashboard = new AdminDashboard(this);
        adminDashboard->show();

    } else if (userType == "User") {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Authentication Successful");
        msgBox.setText("Redirecting to User Dashboard...");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }");
        msgBox.exec();

        if (!userDashboard) {
            userDashboard = new UserDashboard(currentUser, bookManager, this);
        }

        userDashboard->show();

    } else {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon("C:/LibManager/LibManager/LBResources/LB_favicon.png"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Invalid User Type");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { background-color: black; color: white; font-size: 14px; }"
                             "QPushButton { background-color: #555; color: white; font-size: 12px; }"
                             "QPushButton:hover { background-color: #888; }");
        msgBox.exec();
    }
}





