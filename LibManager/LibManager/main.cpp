#include "authscreen.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "book_management_fuser.h"
#include "library.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "signup.h"
#include "user.h"
#include "admin.h"
#include "library_database.h"
#include "book_management_fadmin.h"
int main(int argc, char *argv[])
{


    const std::string data = "C:\\LibManager\\LibManager\\books.txt";
    std::ifstream dosya(data);

    if (!dosya.is_open()) {
        std::cerr << "The doc cannot open: " << data << '\n';
        return 1;
    }

    std::string line;
    while (std::getline(dosya, line)) {
        std::istringstream ss(line);
        std::string name, author, genre, isbn, number;
        int num;


        if (std::getline(ss, name, ',') &&
            std::getline(ss, author, ',') &&
            std::getline(ss, genre, ',') &&
            std::getline(ss, isbn, ',') &&
            std::getline(ss, number)) {

            try {
                num = std::stoi(number);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Geçersiz sayı formatı: " << number << "\n";
                continue;
            } catch (const std::out_of_range& e) {
                std::cerr << "Sayı çok büyük: " << number << "\n";
                continue;
            }


            Library_Database library_database(name, author, genre, isbn, num);


            gbookManager.library.addBook(library_database);
        }
    }
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LibManager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }


    // SignUp penceresini başlatıyoruz ve bookManager'ı parametre olarak veriyoruz

    AuthScreen w;
    w.setFixedSize(854,480);
    w.setWindowTitle("LibManager");


    w.show();
    return a.exec();
}
