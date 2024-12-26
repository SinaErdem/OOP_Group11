#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H

#include <string>

/**
 * @class Library_Database
 * @brief Represents a book's data in the library database.
 */
class Library_Database
{
private:
    std::string name;    ///< The name of the book.
    std::string author;  ///< The author of the book.
    std::string genre;   ///< The genre of the book.
    std::string isbn;    ///< The ISBN of the book.
    int number;          ///< The number of copies available.

public:
    /**
     * @brief Constructs a Library_Database object with specified attributes.
     * @param name The name of the book.
     * @param author The author of the book.
     * @param genre The genre of the book.
     * @param isbn The ISBN of the book.
     * @param number The number of copies available.
     */
    Library_Database(const std::string& name, const std::string& author, const std::string& genre, const std::string& isbn, int number);

    /**
     * @brief Retrieves the number of available copies.
     * @return The number of available copies.
     */
    int getNumber() const;

    /**
     * @brief Sets the number of available copies.
     * @param num The new number of copies.
     */
    void setNumber(int num);

    /**
     * @brief Compares two Library_Database objects for equality.
     * @param other The other Library_Database object to compare with.
     * @return True if the objects are equal; otherwise, false.
     */
    bool operator==(const Library_Database& other);

    /**
     * @brief Retrieves the name of the book.
     * @return The name of the book.
     */
    std::string getName() const;

    /**
     * @brief Sets the name of the book.
     * @param n The new name of the book.
     */
    void setName(std::string& n);

    /**
     * @brief Retrieves the author of the book.
     * @return The author of the book.
     */
    std::string getAuthor() const;

    /**
     * @brief Sets the author of the book.
     * @param a The new author of the book.
     */
    void setAuthor(std::string& a);

    /**
     * @brief Retrieves the genre of the book.
     * @return The genre of the book.
     */
    std::string getGenre() const;

    /**
     * @brief Sets the genre of the book.
     * @param g The new genre of the book.
     */
    void setGenre(std::string& g);

    /**
     * @brief Retrieves the ISBN of the book.
     * @return The ISBN of the book.
     */
    std::string getIsbn() const;

    /**
     * @brief Sets the ISBN of the book.
     * @param i The new ISBN of the book.
     */
    void setIsbn(std::string& i);
};

#endif // LIBRARY_DATABASE_H
