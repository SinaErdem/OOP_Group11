#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H

#include <string>
class Library_Database
{
private:
    std::string name;
    std::string author;
    std::string genre;
    std::string isbn;
    int number;
public:

    // Constructor
    Library_Database(const std::string& name, const std::string& author, const std::string& genre, const std::string& isbn, int number);
    int getNumber();
    void setNumber(int num);
    bool operator==(const Library_Database& other) ;
    void setName( std::string& n) ;
    void setAuthor( std::string& a) ;
    void setIsbn( std::string& i) ;
    void setGenre( std::string& g) ;
    std::string getName() ;
    std::string getIsbn() ;
    std::string getAuthor() ;
    std::string getGenre() ;


};

#endif // LIBRARY_DATABASE_H
