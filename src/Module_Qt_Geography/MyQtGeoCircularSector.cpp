#include "MyQtGeoCircularSector.h"

MyQtGeoCircularSector::MyQtGeoCircularSector(const QGeoCoordinate &center, const qreal &radiusInMeters, bool *ok,
          const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree, const double &endDirectionInDegree, QObject *parent)
        : MyQtGeoCircle(center, radiusInMeters,ok,  geoShapeObjectID,name,parent)
{






}
