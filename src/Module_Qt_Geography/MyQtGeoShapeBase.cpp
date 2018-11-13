#include "MyQtGeoShapeBase.h"

MyQtGeoShapeBase::MyQtGeoShapeBase(const qint32 &geoShapeObjectID, const QString &name, QObject *parent, const quint32 &utcTime) : QObject(parent)
{
    setGeoShapObjectID(geoShapeObjectID);
    setName(name);
    setRecordUTCTime(utcTime);
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

QString MyQtGeoShapeBase::getName() const
{
    return name;
}

void MyQtGeoShapeBase::setName(const QString &value)
{
    name = value;
}

quint32 MyQtGeoShapeBase::getRecordUTCTime() const
{
    return recordUTCTime;
}

void MyQtGeoShapeBase::setRecordUTCTime(const quint32 &value)
{
    recordUTCTime = value;
}
