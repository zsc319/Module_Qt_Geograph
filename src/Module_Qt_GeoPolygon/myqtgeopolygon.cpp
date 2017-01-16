#include "myqtgeopolygon.h"
#include <QDebug>
#include <QLineF>

MyQtGeoPolygon::MyQtGeoPolygon(QVector<QPointF> geoPointsInDegreesParam, bool *ok, QObject *parent) : QObject(parent)
{
    this->geoPointsInDegrees=geoPointsInDegreesParam;
    QPolygonF polygonFTest(geoPointsInDegreesParam);
    if(!polygonFTest.isClosed())
    {
        qDebug()<<"Error: polygon is not closed! Make sure that starting point and ending point are the same!";
       *ok=false;
        return;
    }
    if(polygonFTest.size()<3)
    {
        qDebug()<<"Error: There are less than 3 points!";
        *ok=false;
        return;
    }
    if(insertNewPointsIntoGeoPoints())
        *ok=true;
    else
        *ok=false;


}

bool MyQtGeoPolygon:: insertNewPointsIntoGeoPoints()
{
    QPointF southPole(180,-90),northPole(180,90);
    QLineF lineF180DegreeLongitude(southPole,northPole); //longitude of the degree 180 degrees

    QMutableVectorIterator <QPointF> i(geoPointsInDegrees);
    QPointF lastPointF;
    bool isLastPointValid=false;
    while (i.hasNext())
    {
        if(!isLastPointValid)
        {
            lastPointF=i.next();
            if(!checkPointFValidity(lastPointF))
                return false;
            isLastPointValid=true;

        }
        else
        {
            QPointF currentPoint=i.next();
            if(!checkPointFValidity(currentPoint))
                return false;
            if(currentPoint.x()*lastPointF.x()<0) //one positive longitude, one negative longitude
            {
                QLineF lineF(lastPointF,currentPoint);
                if(lineF.dx()>180) //180 degree crossed
                {
                    if(currentPoint.x()<0)
                    {
                        currentPoint.setX(currentPoint.x()+360);
                    }
                    else if(lastPointF.x()<0)
                    {
                        lastPointF.setX(lastPointF.x()+360);
                    }
                    lineF.setPoints(lastPointF,currentPoint);
                    QPointF intersecPointF;
                    if(lineF.intersect(lineF180DegreeLongitude, &intersecPointF)==QLineF::BoundedIntersection)
                    {
                        i.insert(intersecPointF);
                    }
                }
            }
        }
    }
    return splitPointsBy180DegreeLongitudeAndDivideIntoMultiPolygons();
}

//根据180度经度线将点划分为两部分，分别组成多个多边形，然后再使用united方法合并
bool MyQtGeoPolygon::splitPointsBy180DegreeLongitudeAndDivideIntoMultiPolygons()
{
    QVectorIterator <QPointF> i(geoPointsInDegrees);
    QVector <QPointF> vectorPointFPositiveLongitude,vectorPointFNonPositiveLongitude;
    while (i.hasNext())
    {
        QPointF pointF =i.next();
        if(pointF.x()>0)
            vectorPointFPositiveLongitude.append(pointF);
        else
            vectorPointFNonPositiveLongitude.append(pointF);
    }

    QPolygonF polygonFPositiveLongitude(vectorPointFPositiveLongitude),polygonFNonPositiveLongitude(vectorPointFNonPositiveLongitude);
    polyGonF=polygonFNonPositiveLongitude.united(polygonFPositiveLongitude);
    return true;
}

bool MyQtGeoPolygon::checkPointFValidity(QPointF &pointF)
{
    if(pointF.x()<-180||pointF.x()>180||pointF.y()>90||pointF.y()<-90)
    {
        qDebug()<<"Invalid points:"<<pointF;
        return false;
    }
    return true;
}

QPolygonF MyQtGeoPolygon::getPolyGonF() const
{
    return polyGonF;
}
