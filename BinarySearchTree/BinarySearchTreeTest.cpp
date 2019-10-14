#include <iostream>
#include "BinarySearchTree.h"
#include"../Date/Date.h"

#include <fstream>
#include <sstream>

using namespace std;

istream & operator >>(istream & input, Date & D);
ostream & operator <<( ostream & os, const Date & D );
template<class T>
istream & operator >>(istream & input, BinarySearchTree<T> & bst);

void testplan1(); // Testing the default constructor
template <class T>
void testplan2(const BinarySearchTree<T> & bst); // Testing the copy constructor
template <class T>
void testplan7(BinarySearchTree<T> & bst); // Testing the Remove method,
                                       // with various input by the user
template <class T>
void testplan6(BinarySearchTree<T> & bst); // Testing the Search method
                                       // with various inputs from the user
template <class T>
void testplan3(BinarySearchTree<T> & bst); // Testing the in order traversal method
template <class T>
void testplan4(BinarySearchTree<T> & bst); // Testing the pre order traversal method
template <class T>
void testplan5(BinarySearchTree<T> & bst); // Testing the post order traversal method
template <class T>
void testplan8(BinarySearchTree<T> & bst); // Testing the destroy tree function.
template <class T>
void print(T& someT);


int main()
{
    ifstream infile ("testData.csv");
    if( !infile ) return -1; // exits with a error message if file not found

    BinarySearchTree<Date> newTree;

   infile >> newTree;

    // typedef int INT; Used for the int testing

    testplan1(); // Testing the default constructor
    cout << endl;
    testplan2(newTree); // Testing the copy constructor
    cout << endl;
    testplan3(newTree); // Testing the inOrder method
    cout << endl;
    testplan5(newTree); // Testing the PostOrder method
    cout << endl;
    testplan4(newTree); // Testing the PreOrder method
    cout << endl;
    testplan6(newTree); // Testing the Search method
    cout << endl;
    testplan7(newTree); // Testing the Remove method
    cout << endl;
    testplan8(newTree); // Testing the Destroy tree function
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

void testplan1() // Test the Default constructor, using the isEmpty function
{
    BinarySearchTree<Date> bst;
    if (bst.isEmpty())
        cout << "Test 1 Passed. We have an Empty Tree." << endl;
    else
        cout << "Test 1 Failed. Debug needed" << endl;
}

template <class T>
void testplan2(const BinarySearchTree<T> & bst) // Testing the copy constructor
{
    //cout << "Testing this **** hole" << endl;
    BinarySearchTree<T> newTree(bst);

    if (newTree.isEmpty())
        cout << "Test 2 failed. Copy Constructor not working" << endl;
    else
        cout << "Test 2 passed. Copy constructor is success full" << endl;
}

template <class T>
void testplan7(BinarySearchTree<T> & bst) // Testing the remove method
{
    unsigned day, month, year;
    char choice;

    do
    {
        cout << "Test 7: Enter Date to remove: e.g 12 04 2014 for 12/04/2014 ";
        cin >> day >> month >> year;
        Date num(day, month, year);
        cout << endl;
        bst.Remove(num); // Testing removing a value inside the tree.
        cout << endl;

        bst.inOrderTraversal(print); // Printing out of the remaining values.
        cout << endl;

        cout << "Enter c to continue: ";
        cin >> choice;
        cout << endl;
    }while (choice == 'c');
}

template <class T>
void testplan6(BinarySearchTree<T> & bst) // Testing the search method
{

    unsigned day, month, year;
    char choice;

    do
    {
        cout << "Test 6: Enter Date to search: e.g 12 04 2014 for 12/04/2014 ";
        cin >> day >> month >> year;
        Date num(day, month, year);

        if (bst.Search(num)) // Testing search a value inside the tree.
        {
            cout << "Test 6 Successful. Search item found in the tree." << endl;
            cout << "Retrieved Item is: " << bst.SearchAndRetrieve(num) << endl;;
        }
        else if(!bst.Search(num))
            cout << "Test 6 Successful. Search item not found in the tree." << endl;
        else
            cout << "Test 6 Failed. Search method not working" << endl;



        cout << "Enter c to continue: ";
        cin >> choice;
        cout << endl;
    }while (choice == 'c');
}

template <class T>
void testplan3(BinarySearchTree<T> & bst) // Testing the in order traversal method
{
    cout << "In-Order Traversal: " << endl;
    bst.inOrderTraversal(print);
    cout << endl;
}

template <class T>
void testplan4(BinarySearchTree<T> & bst) // Testing the pre order traversal method
{
    cout << "Pre-Order Traversal:  " << endl;
    bst.preOrderTraversal(print);
    cout << endl;
}

template <class T>
void testplan5(BinarySearchTree<T> & bst) // Testing the post order traversal method
{
    cout << "Post-Order Traversal: " << endl;
    bst.postOrderTraversal(print);
    cout << endl;
}

template <class T>
void testplan8(BinarySearchTree<T> & bst) // Testing the destroy tree function
{
    bst.destroyBinarySearchTree();

    if (bst.isEmpty())
        cout << "Test 8 Passed. The tree has been destroyed." << endl;
    else
        cout << "Test 8 failed. Destroy Function not working" << endl;

}

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.getDay() << "/" << D.getMonth() << "/" << D.getYear();
    return os;
}

template <class T>
void print(T & someT)
{
    cout << someT << ',' ;
}
