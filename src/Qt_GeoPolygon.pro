QT += core gui
CONFIG += c++11

TARGET = Qt_GeoPolygon
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Module_Qt_GeoPolygon/myqtgeopolygon.cpp

HEADERS += \
    Module_Qt_GeoPolygon/myqtgeopolygon.h
