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
                                    const double &endDirectionInDegree,  QObject *parent = 0);

private:
    double startDirectionInDegree;
    double endDirectionInDegree;
};

#endif // MYQTGEOCIRCULARSECTOR_H
