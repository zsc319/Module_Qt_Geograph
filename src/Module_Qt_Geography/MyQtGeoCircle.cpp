#include <QDebug>
#include "MyQtGeoCircle.h"

MyQtGeoCircle::MyQtGeoCircle(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok, const qint32 &geoShapeObjectID,
                             const QString &name, QObject *parent)    : MyQtGeoShapeBase(geoShapeObjectID,name,parent)
{
    geoCircle.setCenter(center);
    geoCircle.setRadius(radiusInMeters);
    if(geoCircle.isValid())
        *ok=isValid=true;
    else
        *ok=isValid=false;
}



bool  MyQtGeoCircle::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    if(!geoCoordinate.isValid())
    {
        qDebug()<<"Error: invalid geoCooridinate:"<<geoCoordinate;
        return false;
    }
    return geoCircle.contains(geoCoordinate);
}

qreal MyQtGeoCircle::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{



    return -1;
}

Enum_MyQtGeoShapeType MyQtGeoCircle::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_Circle;
}

QGeoCircle MyQtGeoCircle::getGeoCircle() const
{
    return geoCircle;
}

void MyQtGeoCircle::setGeoCircle(const QGeoCircle &value)
{
    geoCircle = value;
}
