QT += core network
QT -= gui

CONFIG += c++11

TARGET = web
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    webmanager.cpp \
    asd.cpp

HEADERS += \
    webmanager.h \
    asd.h
