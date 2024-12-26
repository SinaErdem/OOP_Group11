#include "library_database.h"

/**
 * @brief Constructs a Library_Database object with specified attributes.
 * @param name The name of the book.
 * @param author The author of the book.
 * @param genre The genre of the book.
 * @param isbn The ISBN of the book.
 * @param number The number of copies available.
 */
Library_Database::Library_Database(const std::string& name, const std::string& author, const std::string& genre, const std::string& isbn, int number)
    : name(name), author(author), genre(genre), isbn(isbn), number(number) {}

/**
 * @brief Retrieves the number of available copies.
 * @return The number of available copies.
 */
int Library_Database::getNumber() const {
    return number;
}

/**
 * @brief Sets the number of available copies.
 * @param num The new number of copies.
 */
void Library_Database::setNumber(int num) {
    number = num;
}

/**
 * @brief Compares two Library_Database objects for equality.
 * @param other The other Library_Database object to compare with.
 * @return True if the objects are equal; otherwise, false.
 */
bool Library_Database::operator==(const Library_Database& other) {
    return this->name == other.name &&
           this->author == other.author &&
           this->genre == other.genre &&
           this->isbn == other.isbn;
}

/**
 * @brief Retrieves the name of the book.
 * @return The name of the book.
 */
std::string Library_Database::getName() const {
    return name;
}

/**
 * @brief Sets the name of the book.
 * @param n The new name of the book.
 */
void Library_Database::setName(std::string& n) {
    name = n;
}

/**
 * @brief Retrieves the author of the book.
 * @return The author of the book.
 */
std::string Library_Database::getAuthor() const {
    return author;
}

/**
 * @brief Sets the author of the book.
 * @param a The new author of the book.
 */
void Library_Database::setAuthor(std::string& a) {
    author = a;
}

/**
 * @brief Retrieves the genre of the book.
 * @return The genre of the book.
 */
std::string Library_Database::getGenre() const {
    return genre;
}

/**
 * @brief Sets the genre of the book.
 * @param g The new genre of the book.
 */
void Library_Database::setGenre(std::string& g) {
    genre = g;
}

/**
 * @brief Retrieves the ISBN of the book.
 * @return The ISBN of the book.
 */
std::string Library_Database::getIsbn() const {
    return isbn;
}

/**
 * @brief Sets the ISBN of the book.
 * @param i The new ISBN of the book.
 */
void Library_Database::setIsbn(std::string& i) {
    isbn = i;
}
