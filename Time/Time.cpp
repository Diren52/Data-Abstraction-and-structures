#include "Time.h"

Time::Time()
{
    hours = 0;
    minutes = 0;
}

// A constructor that assigns user defined values to the time object
Time::Time(unsigned hr, unsigned mins)
{
    if(isHour(hr) || isMinutes(mins))
    {
        cout << "Entered invalid time values. Default time initialized" << endl;
        hours = 00;
        minutes = 00;
    }
    else
    {
        hours = hr;
        minutes = mins;
    }
}

Time::Time(const Time & oT)
{
    if(oT.isHour(oT.hours) || oT.isMinutes(oT.minutes))
    {
        cout << "The time entered is invalid." << endl;
    }
    else
    {
        hours = oT.hours;
        minutes = oT.minutes;
    }
}

Time::~Time() // initializes the variables back to zero
{
    hours = 0;
    minutes = 0;
}

void Time::setHour(unsigned hr)
{
    hours = hr;
}

void Time::setMinutes(unsigned mins)
{
    minutes = mins;
}

unsigned Time::getHour() const
{
    return hours;
}

unsigned Time::getMinutes() const
{
    return minutes;
}

bool Time::isHour(unsigned hr) const
{
    return (hr < 0 || hr > 23);
}

bool Time::isMinutes(unsigned mins) const
{
    return ( mins < 0 || mins > 59);
}
