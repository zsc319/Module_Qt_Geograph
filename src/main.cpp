#include <QCoreApplication>
#include <QDebug>
#include "Module_Qt_GeoShapes/MyQtGeoPolygon.h"
#include "Module_Qt_GeoShapes/MyQtGeoRectangle.h"
#include <QGeoCoordinate>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool ok;
    QVector<QPointF> vectPF;
    vectPF.append(QPointF(160,60));
    vectPF.append(QPointF(160,20));
    vectPF.append(QPointF(-160,20));
    vectPF.append(QPointF(-160,60));
    vectPF.append(QPointF(160,60));
    MyQtGeoPolygon geoPolygon(vectPF,&ok);
    QGeoCoordinate pFTest(40,179);
    QGeoCoordinate pFTest2(40,-179);
    QGeoCoordinate pFTest3(40,129);

    qDebug()<<geoPolygon.containsPoint(pFTest)<<geoPolygon.containsPoint(pFTest2)<<geoPolygon.containsPoint(pFTest3);

    QVector<QPointF> vectPF2;
    vectPF2.append(QPointF(60,60));
    vectPF2.append(QPointF(20,60));
    vectPF2.append(QPointF(20,-60));
    vectPF2.append(QPointF(60,-60));
    vectPF2.append(QPointF(60,60));
    MyQtGeoPolygon geoPolygon2(vectPF2,&ok);
    QGeoCoordinate pFTesta(40,20);
    QGeoCoordinate pFTest2a(-40,20);
    QGeoCoordinate pFTest3a(40,70);
    qDebug()<<geoPolygon2.containsPoint(pFTesta)<<geoPolygon2.containsPoint(pFTest2a)<<geoPolygon2.containsPoint(pFTest3a);

    QGeoCoordinate coorBottomLeft(10,160);
    QGeoCoordinate coorUpperRight(40,-160);
    MyQtGeoRectangle *myGeoRect=new MyQtGeoRectangle (coorBottomLeft,coorUpperRight,&ok);
    qDebug()<<myGeoRect->getGeoRectangle().bottomLeft()<<myGeoRect->getGeoRectangle().bottomRight();
    MyQtGeoShapeBase *myShape=myGeoRect;
    QGeoCoordinate pFTestb(20,180);
    qDebug()<<myShape->containsPoint(pFTestb);

    return a.exec();
}
