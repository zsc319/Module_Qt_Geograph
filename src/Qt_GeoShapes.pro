QT += core gui positioning
CONFIG += c++11

TARGET = Qt_GeoShapes
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Module_Qt_GeoShapes/MyQtGeoShapeBase.cpp \
    Module_Qt_GeoShapes/MyQtGeoPolygon.cpp \
    Module_Qt_GeoShapes/MyQtGeoCircle.cpp \
    Module_Qt_GeoShapes/MyQtGeoRectangle.cpp

HEADERS += \
    Module_Qt_GeoShapes/MyQtGeoShapeBase.h \
    Module_Qt_GeoShapes/MyQtGeoPolygon.h \
    Module_Qt_GeoShapes/MyQtGeoCircle.h \
    Module_Qt_GeoShapes/MyQtGeoRectangle.h
