# Qt_Geography  

项目类关系图见下：
![类图](https://gitee.com/uploads/images/2017/1124/150703_68026d38_854788.jpeg "软件项目类图.jpg")


## 功能1:地理多边形  
封装Qt的QGeoCircle、QGeoRectangle和QPolygonF类，成为地理多边形、地理圆形和地理矩形，共同的基类为MyQtGeoShapeBase。  
提供一个常用功能：查询某个坐标是否在某个地理形状内。  
当从西向东运动的时候，经度值逐渐增大，直到东经180度后突变为-180度（西经用复数表示），然后再逐渐增长到-179度，-178度，以此类推。当一个空间区域跨东经180度的时候，进行特殊处理，判断覆盖范围。下图是地球上的经度划分：  

![经度](http://git.oschina.net/uploads/images/2017/0118/220228_c52e8930_854788.jpeg "经度划分")  

如下图所示，是一个横跨180度经度线的多边形区域，绿色点是海上的目标。通过提供的GeoShapes库，可以生成多边形空间对象，判断某个坐标点是否在该多边形内。  

![横跨国际日期变更线的多边形区域](http://git.oschina.net/uploads/images/2017/0118/215338_69f64e39_854788.png "多边形区域")  

## 功能2:地理扇形及扇环  
在地理圆形的基础上进一步封装为地理扇形，地理扇形的基础上封装为地理扇环。    


## 功能3:空间距离计算及日出日落计算  
- 计算两个经纬度间的距离（great circle）    
- 计算给定经纬度给定日期的日出日落时间  

## 基类接口  
```C++  
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) =0;
qint32 getGeoShapObjectID() const;
void setGeoShapObjectID(const qint32 &value);  
virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint)=0;
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

## 扇形类接口  
```C++  
explicit  MyQtGeoCircularSector(const QGeoCoordinate &center, const qreal &radiusInMeters,bool *ok,const qint32 &geoShapeObjectID, const QString &name, const double &startDirectionInDegree,const double &endDirectionInDegree,  QObject *parent = 0);
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
virtual Enum_MyQtGeoShapeType getGeoShapeType() const;
```  

## 扇环类接口  
```C++  
explicit  MyQtGeoAnnularSector(const QGeoCoordinate &center, const qreal &radiusInMeters,bool *ok,const qint32 
&geoShapeObjectID, const QString &name, const double &startDirectionInDegree, const double &endDirectionInDegree,
 const float &radiusInnerInKM, QObject *parent = 0);
virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) ;
virtual Enum_MyQtGeoShapeType getGeoShapeType() const;  
```  

## 线段类接口  
```C++
explicit MyQtGeoLineSegment(const QGeoCoordinate &geoCoordStart, const QGeoCoordinate &geoCoordEnd, bool *ok,
                                const   qint32 &geoShapeObjectID, const QString &name, QObject *parent = 0);
virtual bool containsPoint(const QGeoCoordinate &geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill)=0 ; //To be implemented
virtual qreal distanceFromPointInMeters(const QGeoCoordinate &geoCoordPoint); //To be implemented
virtual Enum_MyQtGeoShapeType getGeoShapeType() const;
qreal getLineLength() const;
```


## Geography接口  
```C++
static  qreal GetDistance(double lat1, double lng1, double lat2, double lng2);
static  qreal GetAzimuth(double lat1, double lng1, double lat2, double lng2);
static  float calculateSunriseAsUTCHour(int year, int month, int day, float lat, float lng);
static  float calculateSunsetAsUTCHour(int year, int month, int day, float lat, float lng);
```

## 使用示例  
构造一个跨过东经180度线的矩形，然后判断(20,180)这一个点是否在区域内。
```C++
QGeoCoordinate coorBottomLeft(10,160); //第一个参数是纬度，第二个参数是经度
QGeoCoordinate coorUpperRight(40,-160);
MyQtGeoRectangle *myGeoRect=new MyQtGeoRectangle (coorBottomLeft,coorUpperRight,&ok);
qDebug()<<myGeoRect->getGeoRectangle().bottomLeft()<<myGeoRect->getGeoRectangle().bottomRight();
MyQtGeoShapeBase *myShape=myGeoRect;
QGeoCoordinate pFTestb(20,180);
qDebug()<<myShape->containsPoint(pFTestb);
```