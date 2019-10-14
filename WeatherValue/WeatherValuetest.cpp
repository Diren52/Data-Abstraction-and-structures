#include "WeatherValue.h"
#include <iostream>

void testplan1();
void testplan2();
void testplan3();
void testplan4();
void testplan5();
void testplan6();

using namespace std;

int main()
{
    cout << "Test 1: Defualt constructor";
    testplan1();
    cout << "Test 2:initializing using the default constructor ";
    testplan2();
    cout << "Test 3: checks the copy constructor";
    testplan3();
    cout << "Test 4: Checks the setter functions ";
    testplan4();
    cout << "Test 5: checking the conversion calculation ";
    testplan5();
    return 0;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.getDay() << " " << D.getMonth() << " " << D.getYear();
    return os;
}

ostream & operator <<( ostream & os, const Time & T )
{
    os << T.getHour() << " " << T.getMinutes() << " ";
    return os;
}

void testplan1()
{
    WeatherValue wD;

    cout << wD.getDate() << " " << wD.getTime()<< " " << wD.getSolarRadiation() << " " << wD.getWindSpeed() << endl;
}

void testplan2()
{
    Date dte;
    Time tme;
    WeatherValue wD(dte, tme, 10, 20);

    cout << wD.getDate() << " " << wD.getTime()<< " " << wD.getSolarRadiation() << " " << wD.getWindSpeed() << endl;
}

void testplan3()
{
    Date dte;
    Time tme;
    WeatherValue oD(dte, tme, 10.0, 20.0);
    WeatherValue wD(oD);

    cout << wD.getDate() << " " << wD.getTime()<< " " << wD.getSolarRadiation() << " " << wD.getWindSpeed() << endl;
}

void testplan4()
{
    Date dte(21, 3, 2017);
    Time tme(12, 30);
    WeatherValue wD;

    wD.setDate(dte);
    wD.setTime(tme);
    wD.setSolarRadiation(988);
    wD.setWindSpeed(1233);

    cout << wD.getDate() << " " << wD.getTime()<< " " << wD.getSolarRadiation() << " " << wD.getWindSpeed() << endl;
}

void testplan5()
{
    WeatherValue wD;

    cout << wD.convertSolarRadiation(6000) <<endl; // expect 1.0
}

