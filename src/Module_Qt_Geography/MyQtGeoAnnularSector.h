#ifndef MYQTGEOANNULARSECTOR_H
#define MYQTGEOANNULARSECTOR_H

#include <QObject>
#include "MyQtGeoCircularSector.h"

class MyQtGeoAnnularSector : public MyQtGeoCircularSector
{
public:
    explicit  MyQtGeoAnnularSector(const QGeoCoordinate &center, const qreal &radiusInMeters,bool *ok,
                                    const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,
                                    const double &endDirectionInDegree, const float &radiusInnerInKM, QObject *parent = 0);

    virtual ~MyQtGeoAnnularSector() {}
    virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    float getRadiusInnerInKM() const;
    void setRadiusInnerInKM(float value);

private:
    float radiusInnerInKM;
};

#endif // MYQTGEOANNULARSECTOR_H
