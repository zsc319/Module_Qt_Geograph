#include <QDebug>
#include "MyQtGeoCircularSector.h"
#include "MyGeography.h"

MyQtGeoCircularSector::MyQtGeoCircularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
          const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree, const double &endDirectionInDegree, QObject *parent)
        : MyQtGeoCircle(center, radiusInMeters,ok,  geoShapeObjectID,name,parent)
{
    this->startDirectionInDegree=startDirectionInDegree;
    this->endDirectionInDegree=endDirectionInDegree;

}

bool MyQtGeoCircularSector::containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule)
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
