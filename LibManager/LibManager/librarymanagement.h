#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include "library.h"

/**
 * @class LibraryManagement
 * @brief Extends the Library class to include additional management functionalities.
 */
class LibraryManagement : public Library
{
private:
    Library library; ///< Library instance for managing books.

public:
    /**
     * @brief Constructs a LibraryManagement object.
     */
    LibraryManagement();
};

#endif // LIBRARYMANAGEMENT_H
