#include <QCoreApplication>
#include <QDebug>
#include "Module_Qt_GeoPolygon/myqtgeopolygon.h"

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
    QPointF pFTest(179,40);
    QPointF pFTest2(-179,40);
    QPointF pFTest3(129,40);

    qDebug()<<geoPolygon.containsPoint(pFTest)<<geoPolygon.containsPoint(pFTest2)<<geoPolygon.containsPoint(pFTest3);

    QVector<QPointF> vectPF2;
    vectPF2.append(QPointF(60,60));
    vectPF2.append(QPointF(60,20));
    vectPF2.append(QPointF(-60,20));
    vectPF2.append(QPointF(-60,60));
    vectPF2.append(QPointF(60,60));
    MyQtGeoPolygon geoPolygon2(vectPF2,&ok);
    QPointF pFTesta(20,40);
    QPointF pFTest2a(-20,40);
    QPointF pFTest3a(70,40);
    qDebug()<<geoPolygon2.containsPoint(pFTesta)<<geoPolygon2.containsPoint(pFTest2a)<<geoPolygon2.containsPoint(pFTest3a);



    return a.exec();
}
