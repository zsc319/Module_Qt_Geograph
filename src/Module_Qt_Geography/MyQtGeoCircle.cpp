#include <QDebug>
#include "MyQtGeoCircle.h"

MyQtGeoCircle::MyQtGeoCircle(const QGeoCoordinate &center, qreal radiusInMeters, bool *ok, QObject *parent)
    : MyQtGeoShapeBase(parent)
{
    geoCircle.setCenter(center);
    geoCircle.setRadius(radiusInMeters);
    *ok=geoCircle.isValid();
}

bool  MyQtGeoCircle::containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule)
{
    if(!geoCoordinate.isValid())
        qDebug()<<"Error: invalid geoCooridinate:"<<geoCoordinate;
    return geoCircle.contains(geoCoordinate);
}

QGeoCircle MyQtGeoCircle::getGeoCircle() const
{
    return geoCircle;
}

void MyQtGeoCircle::setGeoCircle(const QGeoCircle &value)
{
    geoCircle = value;
}
