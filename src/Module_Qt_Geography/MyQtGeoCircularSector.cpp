#include <QDebug>
#include "MyQtGeoCircularSector.h"
#include "MyGeography.h"

MyQtGeoCircularSector::MyQtGeoCircularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
          const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree, const double &endDirectionInDegree, QObject *parent, const quint32 &utcTime)
        : MyQtGeoCircle(center, radiusInMeters,ok,  geoShapeObjectID,name,parent, utcTime)
{
    this->startDirectionInDegree=startDirectionInDegree;
    this->endDirectionInDegree=endDirectionInDegree;
    if(center.isValid()&&radiusInMeters>=0)
        *ok=isValid=true;
    else
        *ok=isValid=false;
}

bool MyQtGeoCircularSector::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    if(!geoCoordinate.isValid())
        qDebug()<<"Error: invalid geoCooridinate:"<<geoCoordinate;

    if(!MyQtGeoCircle::containsPoint(geoCoordinate))
        return false;

    double directionFromCenre=getGeoCircle().center().azimuthTo(geoCoordinate);
    if(startDirectionInDegree<=endDirectionInDegree)
        return directionFromCenre>=startDirectionInDegree&&directionFromCenre<=endDirectionInDegree;
    else //0 degree is crossed
        return directionFromCenre>=startDirectionInDegree || directionFromCenre<=endDirectionInDegree;
}

qreal MyQtGeoCircularSector::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)//To be implemented
{



    return -1;
}

Enum_MyQtGeoShapeType MyQtGeoCircularSector::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_GeoCircularSector;
}

double MyQtGeoCircularSector::getStartDirectionInDegree() const
{
    return startDirectionInDegree;
}

void MyQtGeoCircularSector::setStartDirectionInDegree(double value)
{
    startDirectionInDegree = value;
}

double MyQtGeoCircularSector::getEndDirectionInDegree() const
{
    return endDirectionInDegree;
}

void MyQtGeoCircularSector::setEndDirectionInDegree(double value)
{
    endDirectionInDegree = value;
}
