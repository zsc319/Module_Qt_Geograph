#ifndef MYQTGEOCIRCULARSECTOR_H
#define MYQTGEOCIRCULARSECTOR_H

#include <QObject>
#include <QGeoCircle>
#include "MyQtGeoShapeBase.h"
#include "MyQtGeoCircle.h"

class MyQtGeoCircularSector : public MyQtGeoCircle
{
public:
    explicit  MyQtGeoCircularSector(const QGeoCoordinate &center, const qreal &radiusInMeters,bool *ok,
                                    const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,
                                    const double &endDirectionInDegree,  QObject *parent = 0, const quint32 &utcTime=0);

    virtual ~MyQtGeoCircularSector() {}
    virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented

    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    double getStartDirectionInDegree() const;
    void setStartDirectionInDegree(double value);

    double getEndDirectionInDegree() const;
    void setEndDirectionInDegree(double value);

private:
    double startDirectionInDegree;
    double endDirectionInDegree;
};

#endif // MYQTGEOCIRCULARSECTOR_H
