#ifndef MYQTGEOANNULARSECTOR_H
#define MYQTGEOANNULARSECTOR_H

#include <QObject>
#include "MyQtGeoCircularSector.h"

class MyQtGeoAnnularSector : public MyQtGeoCircularSector
{
public:
    explicit  MyQtGeoAnnularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
                                    const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,
                                    const double &endDirectionInDegree, const float &radiusInnerInMeters, QObject *parent = 0, const quint32 &utcTime=0);

    virtual ~MyQtGeoAnnularSector() {}

    virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented

    float getRadiusInnerInMeters() const;
    void setRadiusInnerInMeters(float value);

private:
    float radiusInnerInMeters;
};

#endif // MYQTGEOANNULARSECTOR_H
