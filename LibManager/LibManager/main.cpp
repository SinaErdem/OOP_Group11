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

/**
 * @brief Main entry point for the application.
 *
 * This function initializes the application, loads the books from a file,
 * sets up the translation system, and launches the authentication screen.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return Exit status of the application.
 */
int main(int argc, char *argv[])
{
    /**
     * @brief File path to the books data file.
     */
    std::string data = "C:\\LibManager\\LibManager\\books.txt";

    /**
     * @brief Input file stream for reading the books data.
     */
    std::ifstream dosya(data);

    if (!dosya.is_open()) {
        /**
         * @brief Error message when the file cannot be opened.
         */
        std::cerr << "The doc cannot open: " << data << '\n';
        return 1;
    }

    /**
     * @brief Temporary variable to store each line of the file.
     */
    std::string line;

    while (std::getline(dosya, line)) {
        std::istringstream ss(line);
        std::string name, author, genre, isbn, number;
        int num;

        /**
         * @brief Parse the line into individual fields separated by commas.
         */
        if (std::getline(ss, name, ',') &&
            std::getline(ss, author, ',') &&
            std::getline(ss, genre, ',') &&
            std::getline(ss, isbn, ',') &&
            std::getline(ss, number)) {

            try {
                /**
                 * @brief Convert the string representation of the book count to an integer.
                 */
                num = std::stoi(number);
            } catch (std::invalid_argument &e) {
                std::cerr << "Invalid number format: " << number << "\n";
                continue;
            } catch (std::out_of_range &e) {
                std::cerr << "Number too large: " << number << "\n";
                continue;
            }

            /**
             * @brief Create a new book entry in the library database.
             */
            Library_Database library_database(name, author, genre, isbn, num);

            /**
             * @brief Add the book to the global book manager library.
             */
            gbookManager.library.addBook(library_database);
        }
    }

    /**
     * @brief Initialize the QApplication instance.
     */
    QApplication a(argc, argv);

    /**
     * @brief Translator object for managing application localization.
     */
    QTranslator translator;

    /**
     * @brief Retrieve system UI languages for localization.
     */
    const QStringList uiLanguages = QLocale::system().uiLanguages();

    for (const QString &locale : uiLanguages) {
        const QString baseName = "LibManager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            /**
             * @brief Install the translator for the application if a valid translation is found.
             */
            a.installTranslator(&translator);
            break;
        }
    }

    /**
     * @brief Launch the authentication screen.
     *
     * The authentication screen is initialized with a fixed size and title.
     */
    AuthScreen w;
    w.setFixedSize(854, 480);
    w.setWindowTitle("LibManager");

    w.show();
    return a.exec();
}
