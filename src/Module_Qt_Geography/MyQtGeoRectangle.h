#ifndef MYQTGEORECTANGLE_H
#define MYQTGEORECTANGLE_H

#include <QGeoRectangle>
#include <QObject>
#include "MyQtGeoShapeBase.h"

class MyQtGeoRectangle: public MyQtGeoShapeBase
{
public:
    explicit MyQtGeoRectangle(const QGeoCoordinate &bottomLeft, const QGeoCoordinate &topRight, bool *ok,
                            const  qint32 &geoShapeObjectID, const QString &name, QObject *parent = 0, const quint32 &utcTime=0);
    virtual ~MyQtGeoRectangle() {}
     virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented

    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    QGeoRectangle getGeoRectangle() const;
    void setGeoRectangle(const QGeoRectangle &value);

private:
    QGeoRectangle geoRectangle;
};

#endif // MYQTGEORECTANGLE_H
