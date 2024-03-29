QT -= gui #отключаем графический интерфейс(сервер консольный)
QT = core

QT += network #для работы с сетью
QT += sql

CONFIG += c++17 cmdline #консольное приложение, версия с++
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        DataBase.cpp \
        funcForServer.cpp \
        main.cpp \
        mytcpserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    DateBase.h \
    funcForServer.h \
    mytcpserver.h
