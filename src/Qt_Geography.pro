QT += core gui positioning
CONFIG += c++11

TARGET = Qt_GeoShapes
CONFIG += console
CONFIG -= app_bundle
INCLUDEPATH += $$PWD/Module_Qt_Geography

TEMPLATE = app

SOURCES += main.cpp \
    Module_Qt_Geography/MyQtGeoCircle.cpp \
    Module_Qt_Geography/MyQtGeoPolygon.cpp \
    Module_Qt_Geography/MyQtGeoRectangle.cpp \
    Module_Qt_Geography/MyQtGeoShapeBase.cpp \
    Module_Qt_Geography/MyGeography.cpp \
    Module_Qt_Geography/MyQtGeoCircularSector.cpp \
    Module_Qt_Geography/MyQtGeoAnnularSector.cpp \
    Module_Qt_Geography/MyQtGeoLineSegment.cpp \
    Module_Qt_Geography/MyQtGeoPolyLineSegment.cpp

HEADERS += \
    Module_Qt_Geography/MyQtGeoCircle.h \
    Module_Qt_Geography/MyQtGeoPolygon.h \
    Module_Qt_Geography/MyQtGeoRectangle.h \
    Module_Qt_Geography/MyQtGeoShapeBase.h \
    Module_Qt_Geography/MyGeography.h \
    Module_Qt_Geography/MyQtGeoCircularSector.h \
    Module_Qt_Geography/MyQtGeoAnnularSector.h \
    Module_Qt_Geography/MyQtGeoLineSegment.h \
    Module_Qt_Geography/MyQtGeoPolyLineSegment.h
