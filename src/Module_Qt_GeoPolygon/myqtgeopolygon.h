#ifndef MYQTGEOPOLYGON_H
#define MYQTGEOPOLYGON_H

#include <QObject>
#include <QPolygonF>

class MyQtGeoPolygon : public QObject
{
    Q_OBJECT
public:
    // use x to represent longitude, y to represent longitude
    explicit MyQtGeoPolygon(QVector<QPointF> geoPointsInDegrees, bool *ok,QObject *parent = 0);

    QPolygonF getPolyGonF() const;

signals:

public slots:

private:
    bool insertNewPointsIntoGeoPoints();
    bool splitPointsBy180DegreeLongitudeAndDivideIntoMultiPolygons();
    bool checkPointFValidity(QPointF &pointF);

    QPolygonF polyGonF;
    QVector<QPointF> geoPointsInDegrees;
};

#endif // MYQTGEOPOLYGON_H
