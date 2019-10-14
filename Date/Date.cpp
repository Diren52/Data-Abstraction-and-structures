#include "Date.h"

Date::Date() //Default constructor
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(unsigned dy, unsigned mnt, unsigned yr)
{
    if (!isDay(dy) || !isMonth(mnt) || !isYear(yr))
    {
        cout << "Invalid date entered." << endl;
        Date();
    }
    else
    {
        day = dy;
        month = mnt;
        year = yr;
    }
}

Date::~Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(const Date &odate)
{
    if (odate.isDay(odate.day) && odate.isMonth(odate.month) && odate.isYear(odate.year))
    {
        day = odate.day;
        month = odate.month;
        year = odate.year;
    }
    else
        cout << "Invalid date entered" << endl;
}

unsigned Date::getDay() const
{
    return day;
}

void Date::setDay(unsigned dy)
{
    day = dy;
}

unsigned Date::getMonth() const
{
    return month;
}

void Date::setMonth(unsigned mnt)
{
    month = mnt;
}

void Date::setYear(unsigned yr)
{
    year = yr;
}

unsigned Date::getYear() const
{
    return year;
}

bool Date::isYear(unsigned yr) const
{
    return (yr >= 1950 && yr <= 2100);
}

bool Date::isMonth(unsigned mnt) const
{
    return (mnt >= 1 && mnt <= 12);
}

unsigned Date::isLeapYear() const
{
    unsigned num;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
         num = 1;
    else
         num = 0;
    return num;
}

bool Date::isDay(unsigned dy) const
{
    return (dy >= 1 && dy <= daysInMonth());
}

unsigned Date::daysInMonth() const
{
    unsigned dayss;
    if (month == 2)
        dayss = (28 + isLeapYear()) ;
    else
        dayss =  (31 - ((month - 1) % 7) % 2);

    return dayss;
}

string Date::printMonth(unsigned mnt)
{
    string monthName;

    switch(mnt)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    default:
        cout << "Not a valid month";
    }

    return monthName;
}

bool Date::operator == (const Date & otherDate)
{
    if(this -> day == otherDate.day && this -> month == otherDate.month && this -> year == otherDate.year)
        return true;
    else
        return false;
}

bool Date::operator < (const Date & otherDate)
{
    bool flag = false;

    if (this -> year > otherDate.year || *this == otherDate)
        flag = false;
    else if (this -> year <= otherDate.year)
    {
        if (this -> day < otherDate.day && this -> month <= otherDate.month)
            flag = true;
        else if (this -> day >= otherDate.day && this -> month < otherDate.month)
            flag = true;
        else
            flag = false;
    }
    return flag;
}

bool Date::operator > (const Date & otherDate)
{
    bool flag = false;

    if (this -> year < otherDate.year)
        flag = false;
    else if (this -> year == otherDate.year)
    {
        if (this -> day > otherDate.day && this -> month >= otherDate.month)
            flag = true;
        else if (this -> day <= otherDate.day && this -> month > otherDate.month)
            flag = true;
        else
            flag = false;
    }
    else if (this -> year > otherDate.year)
    {
            flag = true ;
    }

    return flag;
}
