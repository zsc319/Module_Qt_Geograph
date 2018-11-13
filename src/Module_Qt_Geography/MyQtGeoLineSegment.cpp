#include "MyQtGeoLineSegment.h"

MyQtGeoLineSegment::MyQtGeoLineSegment(const QGeoCoordinate &geoCoordStart, const QGeoCoordinate &geoCoordEnd, bool *ok,
                       const   qint32 &geoShapeObjectID, const QString &name, QObject *parent, const quint32 &utcTime)
                : MyQtGeoShapeBase(geoShapeObjectID,name,parent, utcTime)
{
    this->geoCoordStart=geoCoordStart;
    this->geoCoordEnd=geoCoordEnd;
    lineLength=geoCoordStart.distanceTo(geoCoordEnd);
    if(geoCoordStart.isValid()&&geoCoordEnd.isValid())
        *ok=isValid= true;
    else
        *ok=isValid= false;
}

qreal MyQtGeoLineSegment::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{
    if(!geoCoordPoint.isValid()||!isValid)
        return -1;

    qreal distanceToStartPoint=geoCoordPoint.distanceTo(geoCoordStart) ;
    qreal distanceToEndPoint=geoCoordPoint.distanceTo(geoCoordEnd) ;

    //obtuse
    if(distanceToStartPoint*distanceToStartPoint>=(distanceToEndPoint*distanceToEndPoint+lineLength*lineLength) )
        return distanceToEndPoint;
    //obtuse
    if(distanceToEndPoint*distanceToEndPoint>=(distanceToStartPoint*distanceToStartPoint+lineLength*lineLength) )
        return distanceToStartPoint;

    double halfGirth=(lineLength+distanceToStartPoint+distanceToEndPoint)/2;     //周长的一半
    double area=sqrt(halfGirth*(halfGirth-lineLength)*(halfGirth-distanceToStartPoint)*(halfGirth-distanceToEndPoint));  //海伦公式求面积
    return 2*area/lineLength;
}

Enum_MyQtGeoShapeType MyQtGeoLineSegment::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_LineSegment;
}

qreal MyQtGeoLineSegment::getLineLength() const
{
    return lineLength;
}
