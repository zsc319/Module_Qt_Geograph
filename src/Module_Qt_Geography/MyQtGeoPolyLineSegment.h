#ifndef MYQTGEOPOLYLINESEGMENT_H
#define MYQTGEOPOLYLINESEGMENT_H

#include <QObject>
#include <QVector>
#include "MyQtGeoShapeBase.h"

class MyQtGeoPolyLineSegment : public MyQtGeoShapeBase
{
    Q_OBJECT
public:
    explicit MyQtGeoPolyLineSegment(const QVector<QGeoCoordinate *> &vectGeoCoordParam, bool *ok,
                                const   qint32 &geoShapeObjectID, const QString &name, QObject *parent = 0);
    void appendOneGeoCoord(QGeoCoordinate *newCoordinate);
    void removeFirstGeoCoord();
    void removeLastGeoCoord();
    void clearGeoCoord();

    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    virtual ~MyQtGeoPolyLineSegment(){}
    virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill)=0 ; //To be implemented
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)=0; //To be implemented
private:
    QVector <QGeoCoordinate*> vectGeoCoords;
};

#endif // MYQTGEOPOLYLINESEGMENT_H
