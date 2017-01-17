#ifndef MYQTGEORECTANGLE_H
#define MYQTGEORECTANGLE_H

#include <QGeoRectangle>
#include <QObject>
#include <Module_Qt_GeoShapes/MyQtGeoShapeBase.h>

class MyQtGeoRectangle: public MyQtGeoShapeBase
{
public:
    explicit MyQtGeoRectangle(const QGeoCoordinate &bottomLeft, const QGeoCoordinate &topRight, bool *ok, QObject *parent = 0);
     virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;

    QGeoRectangle getGeoRectangle() const;
    void setGeoRectangle(const QGeoRectangle &value);

protected:
    QGeoRectangle geoRectangle;
};

#endif // MYQTGEORECTANGLE_H
