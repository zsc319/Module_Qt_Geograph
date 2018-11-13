#include "MyQtGeoPolyLineSegment.h"
#include <QVector>
MyQtGeoPolyLineSegment::MyQtGeoPolyLineSegment(const QVector <QGeoCoordinate*> &vectGeoCoordParam,
             bool *ok, const   qint32 &geoShapeObjectID, const QString &name, QObject *parent, const quint32 &utcTime) :
            MyQtGeoShapeBase(geoShapeObjectID,name,parent, utcTime)
{
    this->vectGeoCoords=vectGeoCoordParam;
    *ok=isValid= true;
}

Enum_MyQtGeoShapeType MyQtGeoPolyLineSegment::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_PolyLineSegment;
}

QVector <QGeoCoordinate*> MyQtGeoPolyLineSegment::getVectGeoCoords() const
{
    return vectGeoCoords;
}

void MyQtGeoPolyLineSegment::appendOneGeoCoord(QGeoCoordinate *newCoordinate)
{
    vectGeoCoords.append(newCoordinate);
}

void MyQtGeoPolyLineSegment::removeFirstGeoCoord()
{
    vectGeoCoords.removeFirst();
}

void MyQtGeoPolyLineSegment::removeLastGeoCoord()
{
    vectGeoCoords.removeLast();
}

void MyQtGeoPolyLineSegment::clearGeoCoord()
{
    vectGeoCoords.clear();
}

//To be implemented
bool MyQtGeoPolyLineSegment::containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule)
{
    return false;
}

//To be implemented
qreal MyQtGeoPolyLineSegment::distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)
{
    return 0;
}

