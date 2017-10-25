#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <QObject>

#define PI 3.1415926
#define ZENITH -.83

class MyGeography : public QObject
{
    Q_OBJECT
public:
    explicit MyGeography(QObject *parent = 0);
    ~MyGeography();
    static  qreal GetDistance(const double &lat1, const double &lng1, const double &lat2,const  double &lng2);
    static  qreal GetAzimuth(const double &lat1,const  double &lng1, const double &lat2, const double &lng2);
    static  float calculateSunriseAsUTCHour(const int &year, int &month, int &day, float &lat, float &lng);
    static  float calculateSunsetAsUTCHour(const int &year,const  int &month, const int &day,const  float &lat,const  float &lng);

signals:

public slots:

private:

};

#endif // GEOGRAPHY_H
