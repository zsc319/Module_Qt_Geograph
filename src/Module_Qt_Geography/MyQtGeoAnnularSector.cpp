#include "MyQtGeoAnnularSector.h"

MyQtGeoAnnularSector::MyQtGeoAnnularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
          const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,
            const double &endDirectionInDegree, const float &radiusInnerInKM, QObject *parent)
        : MyQtGeoCircularSector(center, radiusInMeters,ok,  geoShapeObjectID,name, startDirectionInDegree, endDirectionInDegree,  parent)
{
    this->radiusInnerInKM=radiusInnerInKM;
}

bool MyQtGeoAnnularSector::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    if(!MyQtGeoCircularSector::containsPoint(geoCoordinate)) //Judge if inside the bigger circular sector
        return false;

    float distanceFromCenterInKM=getGeoCircle().center().distanceTo(geoCoordinate)/1000.0;
    if(distanceFromCenterInKM<radiusInnerInKM) //Inside the inner circular sector, outside the annular
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

float MyQtGeoAnnularSector::getRadiusInnerInKM() const
{
    return radiusInnerInKM;
}

void MyQtGeoAnnularSector::setRadiusInnerInKM(float value)
{
    radiusInnerInKM = value;
}
