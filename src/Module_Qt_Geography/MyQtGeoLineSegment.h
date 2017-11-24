#ifndef MYQTGEOLINESEGMENT_H
#define MYQTGEOLINESEGMENT_H

#include <QObject>
#include "MyQtGeoShapeBase.h"

class MyQtGeoLineSegment : public MyQtGeoShapeBase
{
    Q_OBJECT

public:
    explicit MyQtGeoLineSegment(const QGeoCoordinate &geoCoordStart, const QGeoCoordinate &geoCoordEnd, bool *ok,
                                const   qint32 &geoShapeObjectID, const QString &name, QObject *parent = 0);
    virtual ~MyQtGeoLineSegment(){}
    virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill)=0 ; //To be implemented
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented

    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;


    qreal getLineLength() const;

private:
    QGeoCoordinate geoCoordStart, geoCoordEnd;
    qreal lineLength;

};

#endif // MYQTGEOLINESEGMENT_H
