#Qt_GeoPolygon
## 功能  
使用Qt的QPolygonF类进行扩展，支持对地理多边形的使用。地理圆形和矩形，可以使用QGeoCircle和QGeoRectangular。  
use x to represent longitude, y to represent longitude
## 接口  
-    explicit MyQtGeoPolygon(QVector <QPointF> paramGeoPointsInDegreesBeforeTranslate, bool *ok,QObject *parent = 0);
-    bool containsPoint(QPointF pointF, Qt::FillRule fillRule=Qt::OddEvenFill) ;

-    QPolygonF getPolygonFTranslated() const;
-    QVector <QPointF> getGeoPointsInDegreesBeforeTranslate() const;
-    QVector <QPointF> getGeoPointsInDegreeAfterTranslate() const;