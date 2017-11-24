#include "MyQtGeoLineSegment.h"

MyQtGeoLineSegment::MyQtGeoLineSegment(const QGeoCoordinate &geoCoordStart, const QGeoCoordinate &geoCoordEnd, bool *ok,
                       const   qint32 &geoShapeObjectID, const QString &name, QObject *parent) : MyQtGeoShapeBase(geoShapeObjectID,name,parent)
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
    if(!geoCoordPoint.isValid())
        return -1;

    qreal distanceToStartPoint=geoCoordPoint.distanceTo(geoCoordStart) ;
    qreal distanceToEndPoint=geoCoordPoint.distanceTo(geoCoordEnd) ;

    c=getDistanceBtwP(PAy,PAx,PCy,PCx);//经纬坐标系中求两点的距离公式
    if(b*b>=c*c+a*a)return c;
    if(c*c>=b*b+a*a)return b;
    double l=(a+b+c)/2;     //周长的一半
    double s=sqrt(l*(l-a)*(l-b)*(l-c));  //海伦公式求面积
    return 2*s/a;


    return -1;
}

Enum_MyQtGeoShapeType MyQtGeoLineSegment::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_LineSegment;
}

qreal MyQtGeoLineSegment::getLineLength() const
{
    return lineLength;
}
