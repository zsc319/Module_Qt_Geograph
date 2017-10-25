#ifndef MYQTGEOSHAPEBASE_H
#define MYQTGEOSHAPEBASE_H

#include <QObject>
#include <QGeoCoordinate>

enum Enum_MyQtGeoShapeType
{
    EV_MyQtGeoShapeType_Base = 0,
    EV_MyQtGeoShapeType_Circle = 1,
    EV_MyQtGeoShapeType_Rectangle = 2,
    EV_MyQtGeoShapeType_Polygon = 3,
    EV_MyQtGeoShapeType_GeoPoint = 4,
    EV_MyQtGeoShapeType_GeoCircularSector = 5,  //扇形
    EV_MyQtGeoShapeType_GeoAnnularSector = 6  //扇环
};

class MyQtGeoShapeBase : public QObject
{
    Q_OBJECT
public:
    explicit MyQtGeoShapeBase(const qint32 &geoShapeObjectID,const QString &name,QObject *parent = 0);
    virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) =0;
    virtual Enum_MyQtGeoShapeType getGeoShapeType() const;

    virtual ~MyQtGeoShapeBase()  {}

    qint32 getGeoShapObjectID() const;
    void setGeoShapObjectID(const qint32 &value);

    QString getName() const;
    void setName(const QString &value);

private:
    qint32 geoShapObjectID;
    QString name; //Name of this object
signals:

public slots:

};

#endif // MYQTGEOSHAPEBASE_H
