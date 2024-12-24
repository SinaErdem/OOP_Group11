#include "book_management_fadmin.h"
#include <iostream>
#include <sstream>
std::list<User> Book_Management_fAdmin::users;
Book_Management_fAdmin::Book_Management_fAdmin() {}
 void Book_Management_fAdmin::addUser(User user){
    users.push_back(user);
}

void Book_Management_fAdmin::removeUser(){

}

void Book_Management_fAdmin::addBook(const std::string& bookInfo) {

    std::istringstream stream(bookInfo);
    std::string name, author, genre, isbn;
    int quantity;


    std::getline(stream, name, ',');
    std::getline(stream, author, ',');
    std::getline(stream, genre, ',');
    std::getline(stream, isbn, ',');
    stream >> quantity;


    std::ofstream outFile("books.txt", std::ios::app);

    if (outFile.is_open()) {

        outFile << name << ","
                << author << ","
                << genre << ","
                << isbn << ","
                << quantity << "\n";

        std::cout << "Book added successfully!" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

void Book_Management_fAdmin::displayUsers() {


    }

