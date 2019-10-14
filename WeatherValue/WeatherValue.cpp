#include "WeatherValue.h"

WeatherValue::WeatherValue()
{
    windSpeed = 0;
    solarRadiation = 0;
    date = Date();
    time = Time();
}

WeatherValue::~WeatherValue()
{
    windSpeed = 0;
    solarRadiation = 0;
    date = Date();
    time = Time();
}

WeatherValue::WeatherValue(const WeatherValue& other)
{
        date = other.date;
        time = other.time;
        windSpeed = other.windSpeed;
        solarRadiation = other.solarRadiation;
}

WeatherValue::WeatherValue(const Date & dte, const Time & tme, double wndspeed, double solrad)
{
    date = dte;
    time = tme;
    windSpeed = wndspeed;
    solarRadiation = solrad;
}

double WeatherValue::getSolarRadiation() const
{
    return solarRadiation;
}

void WeatherValue::setSolarRadiation(double sol)
{
    solarRadiation = sol;
}

double WeatherValue::getWindSpeed() const
{
    return windSpeed;
}

void WeatherValue::setWindSpeed(double speed)
{
    windSpeed = speed;
}

const Date & WeatherValue::getDate() const
{
    return date;
}

void WeatherValue::setDate(const Date & dte)
{
    date = dte;
}

const Time & WeatherValue::getTime() const
{
    return time;
}

void WeatherValue::setTime(const Time & tme)
{
    time= tme;
}

double WeatherValue::convertSolarRadiation(double solarrad)
{
    double owh,  temp;

    owh = solarrad * 1.0/6.0;

    temp = owh/1000.0;


    return temp;
}
