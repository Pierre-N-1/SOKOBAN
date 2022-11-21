QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aidewindow.cpp \
    caisse.cpp \
    configuration.cpp \
    main.cpp \
    mainwindow.cpp \
    objet.cpp \
    objetimmobile.cpp \
    objetmobile.cpp \
    optionswindow.cpp \
    partie.cpp \
    personnage.cpp \
    plateau.cpp

HEADERS += \
    aidewindow.h \
    caisse.h \
    configuration.h \
    mainwindow.h \
    objet.h \
    objetimmobile.h \
    objetmobile.h \
    optionswindow.h \
    partie.h \
    personnage.h \
    plateau.h

FORMS += \
    aidewindow.ui \
    mainwindow.ui \
    optionswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
