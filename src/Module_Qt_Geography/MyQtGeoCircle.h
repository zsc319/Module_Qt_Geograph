#ifndef MYQTGEOCIRCLE_H
#define MYQTGEOCIRCLE_H

#include <QObject>
#include <QGeoCircle>
#include <MyQtGeoShapeBase.h>

class MyQtGeoCircle : public MyQtGeoShapeBase
{
public:
    explicit MyQtGeoCircle(const QGeoCoordinate &center, qreal radiusInMeters,bool *ok,QObject *parent = 0);
    virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;

    QGeoCircle getGeoCircle() const;
    void setGeoCircle(const QGeoCircle &value);

protected:
    QGeoCircle geoCircle;
};

#endif // MYQTGEOCIRCLE_H
