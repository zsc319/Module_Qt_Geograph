#include "MyQtGeoLineSegment.h"

MyQtGeoLineSegment::MyQtGeoLineSegment(const QGeoCoordinate &geoCoordStart, const QGeoCoordinate &geoCoordEnd, bool *ok,
                       const   qint32 &geoShapeObjectID, const QString &name, QObject *parent) : MyQtGeoShapeBase(geoShapeObjectID,name,parent)
{
    this->geoCoordStart=geoCoordStart;
    this->geoCoordEnd=geoCoordEnd;
    if(geoCoordStart.isValid()&&geoCoordEnd.isValid())
        *ok=true;
    else
        *ok=false;
}

qreal MyQtGeoLineSegment::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{



    return -1;
}

Enum_MyQtGeoShapeType MyQtGeoLineSegment::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_LineSegment;
}
