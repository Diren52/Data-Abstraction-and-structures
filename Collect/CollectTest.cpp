#include "Collect.h"
#include "../BinarySearchTree/BinarySearchTree.h"
#include "../Date/Date.h"


#include <fstream>
#include <sstream>

using namespace std;

template<class T>
void testplan1(BinarySearchTree<T> & bst);
template<class T>
void testplan2(BinarySearchTree<T> & bst);
istream & operator >>(istream & input, Date & D);
ostream & operator <<( ostream & os, const Date & D );
template<class T>
istream & operator >>(istream & input, BinarySearchTree<T> & bst);


int main()
{
    ifstream infile ("testData.csv");
    if( !infile ) return -1; // exits with a error message if file not found

    BinarySearchTree<Date> newTree;

    infile >> newTree;
    cout << "Gets the value from the BST and prints them out to screen" << endl;
    testplan1(newTree);
    cout << "Checks the data size function returning the number of elements in the class" << end;
    testplan2(newTree);
    cout << endl;

    return 0;
}
istream & operator >>(istream & input, Date & D)
{
    unsigned day, month, year;
    string dte;
    stringstream str1;

    input >> dte;
    unsigned flash = dte.find_first_of('/');
    unsigned slash = dte.find_last_of('/');

    str1.clear();
    str1.str(" ");
    str1.str(dte.substr(0, flash));
    str1 >> day;

    str1.clear();
    str1.str(" ");
    str1.str(dte.substr(flash + 1, slash));
    str1 >> month;

    str1.clear();
    str1.str(" ");
    str1.str(dte.substr(slash + 1, dte.find_first_of(" ")));
    str1 >> year;

    D.setDay(day);
    D.setMonth(month);
    D.setYear(year);

    return input;
}

template<class T>
istream & operator >>(istream & input, BinarySearchTree<T> & bst)
{

    static Date dte;
    unsigned timepos = 0, i = 0;
    string data, str, str2, str3, str4;

    getline(input, data); // gets the header from the file
    istringstream temp(data); // temporarily assigns the header as an input stream

    while (temp) // searches the new temporary stream for specific headers
    {
        getline(temp, str, ',');
        if (str == "WAST")
            timepos = i;
        i++;
    }

    while(getline(input, str2))
    {
        istringstream temp1(str2); // assigns a line to a temporary input stream

        for (unsigned j = 0; j < i; j++)  // searches the temporary input stream
        {
            getline(temp1, str3, ',');

            if (j == timepos)
                str4 = str4 + str3 + " "; //concatenates the required input
        }

        istringstream temp2(str4); // turns the required input into an input stream

        str4.clear(); // clears the string variable to allow new values

        temp2 >> dte;

        //cout << dte << endl;

        bst.Insert(dte);
    }

    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.getDay() << "/" << D.getMonth() << "/" << D.getYear();
    return os;
}

template<class T>
void testplan1(BinarySearchTree<T> & bst)
{
    Collect<Date> c;
    bst.inOrderTraversal(c.getData);

    for (int i = 0; i < c.dataSize(); i++)
        cout << c[i] << endl;
}

template<class T>
void testplan2(BinarySearchTree<T> & bst)
{
    Collect<Date> c;
    bst.inOrderTraversal(c.getData);

    cout << c.dataSize() << endl;
}
