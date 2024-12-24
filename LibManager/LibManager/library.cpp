#include "library.h"
void Library::addBook(const Library_Database& book) {
    books.push_back(book);

}
std::list<Library_Database>& Library::allBooks() {
    return books;  // Referans döndür
}

