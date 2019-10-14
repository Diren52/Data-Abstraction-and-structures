#include <iostream>
#include "Vector.h"

using namespace std;

void testplan1();
void testplan2();
void testplan3();
void testplan4();
void testplan5();
void testplan6();


using namespace std;

int main()
{
    cout << "Test 1: Defualt constructor ";
    testplan1();
    cout << "Test 2: Checks the initializing of size to 10";
    testplan2();
    cout << "Test 3: Checks the insert item and getItemat given that both need data to be in the vector file Also checks the resizing of the vector";
    testplan3();
    cout << "Test 4: Checks the remove item at function and would return an error message if the value is not in range and the [] operator";
    testplan4();
    cout << "Test 5 Checks the remove item function and would return an error message if the value is not in range";
    testplan5();
    cout << "Test 6 Checks the copy constructor of the vector class";
    testplan6();
    return 0;
}

void testplan1()
{
    // initial constructor
    Vector<int> num;

    cout << num.getLength() << " " << num.getMaxSize() << endl;
}

void testplan2()
{
    // setting the size
    Vector<int> num(10);
    cout << num.getLength() << " " << num.getMaxSize() << endl;
}

void testplan3()
{
    // inserting and retrieving values from them vector
    // and also resizing
    Vector<int> num(5);
    int num2;
    cout << num.getLength() << " " << num.getMaxSize() << endl;
    for(int i = 0; i < 10; i++)
        num.insertItem(i * i);
    for (int k = 0; k < num.getLength(); k++)
    {
        num.getItemAt(num2, k);
        cout << num2 << ", ";
    }
    cout << endl;
    cout << num.getLength() << " " << num.getMaxSize() << endl;
    for (int j = 0; j < 20; j++)
        num.insertItemAt(j, j+2);
    cout << num.getLength() << " " << num.getMaxSize() << endl;
    for (int k = 0; k < num.getLength(); k++)
    {

        cout << num[k] << ", ";
    }
    cout << endl;
}

void testplan4()
{
    Vector<int> num(5);
    int num2;

    for(int i = 0; i < 10; i++)
        num.insertItem(i * i);

    for (int j = 0; j < 20; j++)
        num.insertItemAt(j, j+2);

    for (int l = 0; l < num.getLength(); l++)
    {
        num.removeItemAt(l + 5);
    }

    for (int k = 0; k < num.getLength(); k++)
    {
        num.getItemAt(num2, k);
        cout << num2 << ", ";
    }
    cout << endl;
}

void testplan5()
{
    Vector<int> num(5);
    int num2;

    num.insertItem(21);
    num.insertItem(50);
    num.insertItem(501);

    num.removeItemAt(0);

    for (int k = 0; k < num.getLength(); k++)
    {
        num.getItemAt(num2, k);
        cout << num2 << ", ";
    }
    cout << endl;
}
void testplan6()
{
    Vector<int> num2(5);

    int num3;

    for(int i = 0; i < 10; i++)
        num2.insertItem(i * i);

    for (int j = 0; j < 20; j++)
        num2.insertItemAt(j, j+2);

    Vector<int> num(num2);
    for (int k = 0; k < num.getLength(); k++)
    {
        num.getItemAt(num3, k);
        cout << num3 << ", ";
    }
    cout << endl;
}
