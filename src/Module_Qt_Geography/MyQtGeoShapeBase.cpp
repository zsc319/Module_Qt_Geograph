#include "MyQtGeoShapeBase.h"

MyQtGeoShapeBase::MyQtGeoShapeBase(QObject *parent) : QObject(parent)
{

}

qint32 MyQtGeoShapeBase::getGeoShapObjectID() const
{
    return geoShapObjectID;
}

void MyQtGeoShapeBase::setGeoShapObjectID(const qint32 &value)
{
    geoShapObjectID = value;
}
