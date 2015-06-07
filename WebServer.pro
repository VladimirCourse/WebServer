#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T17:10:54
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    listener.cpp \
    reader.cpp \
    requestprocessor.cpp \
    datastorage.cpp \
    htmlparser.cpp

HEADERS  += mainwindow.h \
    listener.h \
    reader.h \
    requestprocessor.h \
    datastorage.h \
    htmlparser.h

FORMS    += mainwindow.ui
