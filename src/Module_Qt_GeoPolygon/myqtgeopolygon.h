#ifndef MYQTGEOPOLYGON_H
#define MYQTGEOPOLYGON_H

#include <QObject>
#include <QPolygonF>

class MyQtGeoPolygon : public QObject
{
    Q_OBJECT
public:
    // use x to represent longitude, y to represent longitude
    explicit MyQtGeoPolygon(QVector<QPointF> paramGeoPointsInDegreesBeforeTranslate, bool *ok,QObject *parent = 0);
    bool containsPoint(QPointF pointF, Qt::FillRule fillRule=Qt::OddEvenFill) ;

    QPolygonF getPolygonFTranslated() const;
    QVector<QPointF> getGeoPointsInDegreesBeforeTranslate() const;
    QVector<QPointF> getGeoPointsInDegreeAfterTranslate() const;
signals:

public slots:

private:
    bool setIs180LongitudeCrossedAndCheckPointsValidity();
    bool translatePointsWhenNeeded();
    bool checkPointFValidity(QPointF &pointF);

    QPolygonF polygonFTranslated; //Polygon after negative longitude values adding 360 (when 180 longitude crossed)
    QVector<QPointF> geoPointsInDegreesBeforeTranslate,geoPointsInDegreeAfterTranslate;

    bool is180LongitudeCrossed; //if crossed, add 360 degrees to negative longitude values
};

#endif // MYQTGEOPOLYGON_H
