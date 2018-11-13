#include "MyQtGeoAnnularSector.h"

MyQtGeoAnnularSector::MyQtGeoAnnularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
          const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,
            const double &endDirectionInDegree, const float &radiusInnerInMeters, QObject *parent, const quint32 &utcTime)
        : MyQtGeoCircularSector(center, radiusInMeters,ok,  geoShapeObjectID,name, startDirectionInDegree, endDirectionInDegree,  parent, utcTime)
{
    this->radiusInnerInMeters=radiusInnerInMeters;
    if(center.isValid()&&radiusInMeters>=0&&radiusInnerInMeters>=0&&radiusInMeters>=radiusInnerInMeters)
        *ok=isValid=true;
    else
        *ok=isValid=false;
}

bool MyQtGeoAnnularSector::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    if(!MyQtGeoCircularSector::containsPoint(geoCoordinate)) //Judge if inside the bigger circular sector
        return false;

    float distanceFromCenterInMeters=getGeoCircle().center().distanceTo(geoCoordinate);
    if(distanceFromCenterInMeters<radiusInnerInMeters) //Inside the inner circular sector, outside the annular
        return false;
    else //inside the annular
        return true;
}

qreal MyQtGeoAnnularSector::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{



    return -1;
}


Enum_MyQtGeoShapeType MyQtGeoAnnularSector::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_GeoAnnularSector;
}

float MyQtGeoAnnularSector::getRadiusInnerInMeters() const
{
    return radiusInnerInMeters;
}

void MyQtGeoAnnularSector::setRadiusInnerInMeters(float value)
{
    radiusInnerInMeters = value;
}
