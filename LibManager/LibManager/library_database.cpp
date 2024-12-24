#include "library_database.h"

Library_Database::Library_Database(const std::string& name, const std::string& author, const std::string& genre, const std::string& isbn, int number)
    : name(name), author(author), genre(genre), isbn(isbn), number(number) {}

int Library_Database::getNumber()   {
    return number;
}

void Library_Database::setNumber(int num) {
    number=num;
}

bool Library_Database::operator==(const Library_Database& other)  {
    // Kitapları name, author, genre ve isbn alanlarına göre karşılaştırıyoruz
    return this->name == other.name &&
           this->author == other.author &&
           this->genre == other.genre &&
           this->isbn == other.isbn;
}
std::string Library_Database::getName()  {
    return name;
}
void Library_Database::setName( std::string& n)  {
    name = n;
}

// Author getter ve setter
std::string Library_Database::getAuthor()  {
    return author;
}
void Library_Database::setAuthor( std::string& a)  {
    author = a;
}

// Genre getter ve setter
std::string Library_Database::getGenre()  {
    return genre;
}
void Library_Database::setGenre( std::string& g)  {
    genre = g;
}

// ISBN getter ve setter
std::string Library_Database::getIsbn()  {
    return isbn;
}
void Library_Database::setIsbn( std::string& i)  {
    isbn = i;
}
