#include "MyQtGeoRectangle.h"
#include <QDebug>

MyQtGeoRectangle::MyQtGeoRectangle(const QGeoCoordinate &bottomLeft, const QGeoCoordinate &topRight,
                     bool *ok, const qint32 &geoShapeObjectID, const QString &name, QObject *parent)   : MyQtGeoShapeBase(geoShapeObjectID,name,parent)
{
    geoRectangle.setBottomLeft(bottomLeft);
    geoRectangle.setTopRight(topRight);
    *ok=isValid= geoRectangle.isValid();
}

bool  MyQtGeoRectangle::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    if(!geoCoordinate.isValid())
    {
        qDebug()<<"Error: invalid geoCooridinate:"<<geoCoordinate;
        return false;
    }
    return geoRectangle.contains(geoCoordinate);
}

qreal MyQtGeoRectangle::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{



    return -1;
}

Enum_MyQtGeoShapeType MyQtGeoRectangle::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_Rectangle;
}


QGeoRectangle MyQtGeoRectangle::getGeoRectangle() const
{
    return geoRectangle;
}

void MyQtGeoRectangle::setGeoRectangle(const QGeoRectangle &value)
{
    geoRectangle = value;
}
