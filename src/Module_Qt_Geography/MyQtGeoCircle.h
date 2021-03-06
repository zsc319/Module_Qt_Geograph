#ifndef MYQTGEOCIRCLE_H
#define MYQTGEOCIRCLE_H

#include <QObject>
#include <QGeoCircle>
#include <MyQtGeoShapeBase.h>

class MyQtGeoCircle : public MyQtGeoShapeBase
{
public:
    explicit MyQtGeoCircle(const QGeoCoordinate &center, const qreal &radiusInMeters,bool *ok,
                          const  qint32 &geoShapeObjectID, const QString &name, QObject *parent = 0, const quint32 &utcTime=0);
    virtual ~MyQtGeoCircle() {}

    virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
    virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented

    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    QGeoCircle getGeoCircle() const;
    void setGeoCircle(const QGeoCircle &value);

private:
    QGeoCircle geoCircle;
};

#endif // MYQTGEOCIRCLE_H
