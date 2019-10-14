#include "Date.h"
#include <iostream>

void testplan1();
void testplan2();
void testplan3();
void testplan4();
void testplan5();
void testplan6();
void testplan7();
void testplan8();
void testplan9();

using namespace std;

int main()
{
    cout << "Test 1: ";
    testplan1();
    cout << "Test 2: ";
    testplan2();
    cout << "Test 3: ";
    testplan3();
    cout << "Test 4: ";
    testplan4();
    cout << "Test 5 ";
    testplan5();
    cout << "Test 6 ";
    testplan6();
    testplan7();
    testplan8();
    testplan9();

    return 0;
}

void testplan1()
{
    Date dte;
    cout<< "Testing default constructor" << endl;
    cout << dte.getDay() << " " << dte.getMonth() << " " << dte.getYear() << endl;
}

void testplan2()
{
    Date dte(01, 03, 2015);
    cout << "Checks the initializer constructor" << endl;
    cout << dte.getDay() << " " << dte.getMonth() << " " << dte.getYear() << endl;
}

void testplan3()
{
     Date dte(29, 02, 2016);
    cout<<"checking the leap funcion "<< endl;
    cout << dte.getDay() << " " << dte.getMonth() << " " << dte.getYear() << endl;
}

void testplan4()
{
     Date dte(31, 4, 2017);
    cout << "Some bound checking " <<endl;
    cout << dte.getDay() << " " << dte.getMonth() << " " << dte.getYear() << endl;
}

void testplan5()
{
    Date oD(29, 02, 2017);
    Date dte(oD);
    cout << "Checks the copy constructor" << endl;
    cout << dte.getDay() << " " << dte.printMonth(dte.getMonth()) << " " << dte.getYear() << endl;
}

void testplan6()
{
    Date dte;

    dte.setDay(12);
    dte.setMonth(12);
    dte.setYear(2017);
    cout << "checks the setters and getters" << endl;

    cout << dte.getDay() << " " << dte.getMonth() << " " << dte.getYear() << endl;
}

void testplan7()
{
    Date oD(28, 02, 2017);
    Date dte(27, 02, 2017);

     if (dte < oD)
        cout << "operator < working" << endl;

}

void testplan8()
{
    Date oD(28, 02, 2017);
    Date dte(27, 02, 2017);
    if(oD > dte)
        cout << "operator > working" << endl;
}

void testplan9()
{
    Date od(1,1,2011);
    Date od2(1,1,2011);

    if(od == od2 ) cout << "operator == working" << endl;
}
