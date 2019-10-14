#include "Time.h"
#include <iostream>

void testplan1();
void testplan2();
void testplan3();
void testplan4();
void testplan5();

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
    return 0;
}

void testplan1()
{ //Check the constructor has initializes the time.
//Also checks on the getter methods

    Time tme;
    tme = Time();
    cout<<"Testing default constructor " << endl;
    cout << tme.getHour() << " " << tme.getMinutes()<< endl;
}

void testplan2()
{ //Checks the constructor that initializes the content

    Time tme(12, 59);
    cout << "Testing copy constructor "
    cout << tme.getHour() << " " << tme.getMinutes()<< endl;
}

void testplan3()
{
    cout << "Checks using the constructor the range checking" << endl;

    Time tme(24, 49);
    cout << tme.getHour() << " " << tme.getMinutes()<< endl;
}

void testplan4()
{
    cout << "Checks the copy constructor" << endl;

    Time tme(23, 59);
    Time oT(tme);

    cout << oT.getHour() << " " << oT.getMinutes()<< endl;
}

void testplan5()
{
    cout << "Checks the setter and getter methods" << endl;
    Time tme;

    tme.setHour(10);
    tme.setMinutes(20);

    cout << tme.getHour() << " " << tme.getMinutes()<< endl;
}
