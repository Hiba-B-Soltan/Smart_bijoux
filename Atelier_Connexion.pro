#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT       += charts
QT       += printsupport
QT       +=serialport



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    chart.cpp \
    dialog.cpp \
    employee.cpp \
    forgotpassworddialog.cpp \
    gestions.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

HEADERS += \
    arduino.h \
    chart.h \
    dialog.h \
    employee.h \
    forgotpassworddialog.h \
    gestions.h \
    mainwindow.h \
    connection.h



FORMS += \
    dialog.ui \
    gestions.ui \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
<<<<<<< HEAD
    back.qrc \
    back.qrc \
    backkckckc.qrc \
    cap.qrc \
    diamand.qrc \
    login.qrc
=======
    backkckckc.qrc \
    boutton.qrc \
    diamand.qrc \
    imaaage.qrc
>>>>>>> 1b7f71e09592fa301e382e3d84185b747bfe5580
