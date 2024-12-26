# OOP_Group11
## Project short promotional video:
https://www.youtube.com/watch?v=Onoa3sGt6g0
## Our Team<br>

Enes Geldi

Cüneyt Şahin

Öykü Karaduman

Mustafa Sefa Soysal

Sina Erdem Özdemir

## Project

This is the Library Management System Project.

There are two types of accounts: Admin and User

Admin is the librarian who controls and updates the book database and user
database.

User is the reader who can borrow and return books and search them...

The project was made with QT Creator and Designer.

# Library Management System

This project is a **Library Management System**, designed to manage books, users, and administrative actions through an interactive graphical user interface (GUI). It allows users to borrow and return books, search for books, and perform various administrative functions.

---

## Features

### For Users:

- View all books in the library.
- Search for books by name, author, or ISBN.
- Borrow books (with restrictions to prevent borrowing the same book multiple times).
- Return borrowed books.
- View the list of books currently borrowed.

### For Administrators:

- Add or remove books from the library.
- Add or remove users.
- View and manage user data.

---

## How to Compile, Execute & Run the Project

### Prerequisites

Ensure you have the following installed on your system:

- **Qt Framework** (version 5 or later)
- A C++ compiler such as GCC or MSVC
- A modern C++ IDE, such as Qt Creator (recommended for GUI projects)

### Project Setup

1. Clone the repository or download the project files to your local system.
2. Open the project folder in Qt Creator.
3. Ensure all required `.cpp`, `.h`, and `.ui` files are included in the project:
   - `admin.cpp`, `admin.h`
   - `admindashboard.cpp`, `admindashboard.h`, `admindashboard.ui`
   - `authscreen.cpp`, `authscreen.h`, `authscreen.ui`
   - `book_management_fadmin.cpp`, `book_management_fadmin.h`
   - `book_management_fuser.cpp`, `book_management_fuser.h`
   - `library.cpp`, `library.h`
   - `library_database.cpp`, `library_database.h`
   - `librarymanagement.cpp`, `librarymanagement.h`
   - `signup.cpp`, `signup.h`, `signup.ui`
   - `user.cpp`, `user.h`
   - `userdashboard.cpp`, `userdashboard.h`, `userdashboard.ui`
   - `main.cpp`

### Compilation Steps

1. In Qt Creator, click on **File** -> **Open File or Project**, and select the project `.pro` file (if available). If there is no `.pro` file, create a new project and include all source files.
2. Set the build configuration to `Debug` or `Release` as needed.
3. Click **Build** -> **Build Project** or press `Ctrl+B`.

### Execution Steps

1. After successfully building the project, click on **Run** or press `Ctrl+R`.
2. The main application window (authentication screen) will open.

---

## Using the Program

### Authentication

- **Sign Up**: Register as a user or admin by clicking the **Sign Up** button.
  - Fill in your email, username, and password.
  - Select your user type (Admin/User).
- **Sign In**: Log in with your username and password.
  - Admins will be redirected to the Admin Dashboard.
  - Users will be redirected to the User Dashboard.

### User Dashboard Controls

- **View Books**: Click the "Show Books" button to view all available books in the library.
- **Search Books**: Use the search bar and select the filter (Name, Author, ISBN) to find specific books.
- **Borrow Books**: Click the "Borrow" button next to a book in the results to borrow it.
- **View Borrowed Books**: Click the "View Borrowed Books" button to see your current borrowed list.
- **Return Books**: Click the "Return" button next to a borrowed book to return it.

### Admin Dashboard Controls

- **Add Books**: Fill in the book details and click the "Add Books" button.
- **Remove Books**: Enter the name of the book to be removed and click "Remove Books".
- **Add Users**: Fill in the user details and click "Add User".
- **Remove Users**: Enter the username of the user to be removed and click "Remove User".

---

## File Structure

- **Source Files (`.cpp`)**: Contains the implementation of all classes and logic.
- **Header Files (`.h`)**: Defines the classes, methods, and variables used.
- **UI Files (`.ui`)**: Defines the GUI layout and components using Qt Designer.
- **Resource Files**: Includes icons, images, and other assets required by the application.

---

## Troubleshooting

### Common Issues

1. **Missing Qt Libraries**: Ensure Qt libraries are correctly installed and included in your system's PATH.
2. **File Access Errors**: Verify the existence and accessibility of required directories (`C:/LibManager/LibManager/` and its subdirectories).
3. **Compilation Errors**: Ensure all `.cpp`, `.h`, and `.ui` files are added to the project.

### Log Files

Application logs are printed in the console during execution. Review these logs for detailed debugging information.

---

## License

This project is licensed under the MIT License. See `LICENSE` for details.

---

## Acknowledgements

Special thanks to the contributors and libraries that made this project possible.
KATKI

Enes Geldi : Kodlama kısmında önemli katkılarda bulundu.SıgnIn,SıgnUp tasarımı ve arkaplan kodlamasını yaptı,UserDashboard Kısmını yaptı.Kod yazmaya kadarki Proje aşamalarında aktif bulundu. Use Case hazırladı. Inheritance belirleyen ilk aşamalarda aktif rol aldı.

Mustafa Sefa Soysal : Tasarımın büyük çoğunluğunu yaptı. Kodlama kısmında önemli katkılarda bulundu. Kod yazmaya kadarki Proje aşamalarında aktif bulundu. Screen sayfalarının tasarımını yaptı. Proje aşamalarında rol haritasını belirledi.

Cüneyt Şahin : Kodlama kısmında önemli katkılarda bulundu. Veri tabanı kısmıyla ilgilendi.Classları OOP yapısını yaptı ve çoğu işlevi yaptı. Kod yazmaya kadarki Proje aşamalarında aktif bulundu. Inheritance belirleyen ilk aşamalarda aktif rol aldı.

Öykü Karaduman : Doxygen dökümantasyonunu hazırladı. Doxygen'den UML Diyagramı yaptı.Admin Dashboard'unun tasarımı ve işlevlerini yaptı. Kod yazmaya kadarki Proje aşamalarında aktif bulundu. Inheritance belirleyen ilk aşamalarda aktif rol aldı.

Sina Erdem Özdemir : Kod yazmaya kadarki Proje aşamalarında aktif bulundu. Git kurulumunu ve ana sahipliğini yaptı.
Please place the project in C:\\LibManager, if there is no file called
LibManager create it first in C:
