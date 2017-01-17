#Qt_GeoPolygon
## 功能  
使用Qt的QPolygonF类进行扩展，支持对地理多边形、地理圆形和地理矩形，共同的基类为MyQtGeoShapeBase。  
## 基类接口  
```C++  
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) =0;
qint32 getGeoShapObjectID() const;
void setGeoShapObjectID(const qint32 &value);  
```  
## 多边形类接口  
```C++  
// use x to represent longitude, y to represent latitude.
// Note the difference from QGeoCoordinate: first parameter is latitude, second parameter is longitude.
explicit MyQtGeoPolygon(QVector<QPointF> paramGeoPointsInDegreesBeforeTranslate, bool *ok,QObject *parent = 0);
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
QPolygonF getPolygonFTranslated() const;
QVector<QPointF> getGeoPointsInDegreesBeforeTranslate() const;
QVector<QPointF> getGeoPointsInDegreeAfterTranslate() const;
```  

## 矩形类接口  
```C++  
explicit MyQtGeoRectangle(const QGeoCoordinate &bottomLeft, const QGeoCoordinate &topRight, bool *ok, QObject *parent = 0);
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
QGeoRectangle getGeoRectangle() const;
void setGeoRectangle(const QGeoRectangle &value);
```  

## 圆形类接口  
```C++  
explicit MyQtGeoCircle(const QGeoCoordinate &center, qreal radiusInMeters,bool *ok,QObject *parent = 0);
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
QGeoCircle getGeoCircle() const;
void setGeoCircle(const QGeoCircle &value);
```  

## 使用示例  
```C++
QGeoCoordinate coorBottomLeft(10,160);
QGeoCoordinate coorUpperRight(40,-160);
MyQtGeoRectangle *myGeoRect=new MyQtGeoRectangle (coorBottomLeft,coorUpperRight,&ok);
qDebug()<<myGeoRect->getGeoRectangle().bottomLeft()<<myGeoRect->getGeoRectangle().bottomRight();
MyQtGeoShapeBase *myShape=myGeoRect;
QGeoCoordinate pFTestb(20,180);
qDebug()<<myShape->containsPoint(pFTestb);
```