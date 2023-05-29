QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Atoms/Cars/business.cpp \
    Atoms/Cars/car.cpp \
    Atoms/Cars/electric.cpp \
    Atoms/Cars/offroad.cpp \
    Atoms/Cars/sport.cpp \
    Atoms/client.cpp \
    Atoms/rentcurrentstate.cpp \
    Builders/carbuilder.cpp \
    DataBase/clients.cpp \
    DataBase/database.cpp \
    DataBase/historybase.cpp \
    appstate.cpp \
    loginer.cpp \
    main.cpp \
    registrator.cpp \
    widget.cpp

HEADERS += \
    Atoms/Cars/business.h \
    Atoms/Cars/car.h \
    Atoms/Cars/electric.h \
    Atoms/Cars/offroad.h \
    Atoms/Cars/sport.h \
    Atoms/client.h \
    Atoms/rentcurrentstate.h \
    Builders/carbuilder.h \
    DataBase/clients.h \
    DataBase/database.h \
    DataBase/historybase.h \
    appstate.h \
    loginer.h \
    registrator.h \
    widget.h

FORMS += \
    login.ui \
    regist.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
