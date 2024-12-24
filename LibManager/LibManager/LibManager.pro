QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admindashboard.cpp \
    book_management_fadmin.cpp \
    book_management_fuser.cpp \
    library.cpp \
    library_database.cpp \
    librarymanagement.cpp \
    main.cpp \
    authscreen.cpp \
    signup.cpp \
    user.cpp \
    userdashboard.cpp

HEADERS += \
    admin.h \
    admindashboard.h \
    authscreen.h \
    book_management_fadmin.h \
    book_management_fuser.h \
    library.h \
    library_database.h \
    librarymanagement.h \
    signup.h \
    user.h \
    userdashboard.h

FORMS += \
    admindashboard.ui \
    authscreen.ui \
    signup.ui \
    userdashboard.ui

TRANSLATIONS += \
    LibManager_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    books.txt
