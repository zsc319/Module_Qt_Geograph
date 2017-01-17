#ifndef MYQTGEOSHAPEBASE_H
#define MYQTGEOSHAPEBASE_H

#include <QObject>
#include <QGeoCoordinate>

class MyQtGeoShapeBase : public QObject
{
    Q_OBJECT
public:
    explicit MyQtGeoShapeBase(QObject *parent = 0);
    virtual bool containsPoint(QGeoCoordinate geoCoordinate, Qt::FillRule fillRule=Qt::OddEvenFill) =0;
    qint32 getGeoShapObjectID() const;
    void setGeoShapObjectID(const qint32 &value);

signals:

public slots:

protected:
    qint32 geoShapObjectID;

};

#endif // MYQTGEOSHAPEBASE_H
