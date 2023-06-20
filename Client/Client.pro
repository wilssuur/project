QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += lrelease
CONFIG += embed_translations
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    funcforclient.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationwindow.cpp \
    singletonclient.cpp \
    statistics.cpp \
    task.cpp

HEADERS += \
    funcforclient.h \
    mainwindow.h \
    registrationwindow.h \
    singletonclient.h \
    statistics.h \
    task.h

FORMS += \
    mainwindow.ui \
    registrationwindow.ui \
    statistics.ui \
    task.ui

TRANSLATIONS += \
    Client_ru_RU.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
