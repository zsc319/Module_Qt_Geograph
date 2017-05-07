#include "MyQtGeoShapeBase.h"

MyQtGeoShapeBase::MyQtGeoShapeBase(qint32 geoShapeObjectID, QObject *parent) : QObject(parent)
{
    setGeoShapObjectID(geoShapeObjectID);
}

Enum_MyQtGeoShapeType MyQtGeoShapeBase::getGeoShapeType() const
{
    return EV_MyQtGeoShapeType_Base;
}

qint32 MyQtGeoShapeBase::getGeoShapObjectID() const
{
    return geoShapObjectID;
}

void MyQtGeoShapeBase::setGeoShapObjectID(const qint32 &value)
{
    geoShapObjectID = value;
}
