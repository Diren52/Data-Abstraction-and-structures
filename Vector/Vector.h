#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

    /**
	 * @class Vector
	 * @brief  A data structure that uses a dynamic array.
     *
     * Class T values would have been constructed elsewhere.
     * Which will be stored in a data structure, namely this Vector class
     *
	 * @author Joseph Sigar
	 * @version 01
	 * @date 12/04/2017 Joseph Sigar, Created Vector class
	 *
	 * @author Joseph Sigar
	 * @version 02
	 * @date 15/04/2017 Joseph Sigar, Unit Tested the available methods of the Vector class
	 *
	 * @author Joseph Sigar
	 * @version 03
	 * @date 17/04/2017 Joseph Sigar, Modified and deleted some methods not necessary to the data structure. E.g print
     *
	 * @author Joseph Sigar
	 * @version 04
	 * @date 24/04/2017 Joseph Sigar, Added comments and updated doxygen comments on the Header file and Cpp file
     *
     * @author Joseph Sigar
     * @version 05
     * @date 28/04/2017 Joseph Sigar, Added more comments on both the header and cpp file
     *
     * @author Joseph Sigar
     * @version 06
     * @date 28/05/2017 Joseph Sigar, made the class minimal and complete. plus tested it
     *
	 * @todo Make the Vector more 'Future Proof' to allow less change for future requirements
	 *
	 *
	 * @bug N/A at the moment may need further testing
	 *
	 */

template <class T>
class Vector
{
public:


            /**
            * @brief The initializer constructor of Vector class
            *
            * This function is the initializer constructor of the Vector class
            * which would set the size values to a value set by the user.
            *
            * @param size - user defined value that sets the size of the Vector.
            *
            *@return void
            */
    Vector(int size = 100);
        // initializes the Vector to a set size

            /**
             * @brief A copy constructor of the Vector class
             *
             * This function is a copy constructor of the Vector class that copies
             * another Vector elements defined elsewhere (most likely by client) to this Vector class.
             *
             * @param otherVector - the other Vector to copy
             *
             * @return void
             */
    Vector(const Vector<T> & otherVector);
        //Copy Constructor

            /**
             * @brief The Destructor function
             *
             * This function is the destructor of the vector class
             * which will delete the Vector class after the program completes.
             *
             * @return void
             */
    virtual ~Vector();
        //Destructor

            /**
             * @brief Inserts item to end
             *
             * This function will insert an item to the end of the Vector class.
             * And if the end is reached and more data is to be inserted in will resize the Vector.
             *
             * @param insertItem - item to be inserted to the data Structure
             *
             * @return void
             */
    void insertItem(const T & insertItem);
        //Function to insert item at the end of the Vector structure.

            /**
             * @brief Inserts item at a specified location
             *
             * This function will insert an item to a specified location of the Vector class.
             *
             * @param insertItem - item to be inserted to the data Structure
             * @param location - location at which to insert the item
             *
             * @return void
             * @post inserting at a specified location would push the other elements down, to a new location
             *       increasing the size if need be.
             */
    void insertItemAt(const T & insertItem, int location);
        //Function to insert item at a specified location.

            /**
             * @brief Gets item at a specified location
             *
             * This function will retrieve an item from a specified location of the Vector class.
             *
             * @param itemRetrieved - item to be retrieved from the data Structure
             * @param location - location at which to get the item from
             *
             * @return void
             *
             * @pre Vector structure must already hold elements for them to be retrieved
             * @post will get the item at the specified location. if the location is not more than the Maximum size
             */
    void getItemAt(T& itemRetrieved, int location) const;
        //Function to retrieve item at a specified location

            /**
             * @brief Removes item from a specified location of the Vector structure
             *
             * This function will delete an item from a specified location of the Vector class.
             *
             * @param location - location of item to be removed from the data Structure
             *
             * @return void
             *
             * @pre Vector structure must already hold elements for them to be deleted
             * @post will  remove the item from a specified location of the Vector structure.
             */
    void removeItemAt(int location);
        //Function to remove an item from a specified location

            /**
             * @brief Returns the current length of the Vector class
             *
             * This function will return the current length of the Vector class.
             *
             * @return int
             * @post will return 0 if there is no element in the Vector class
             */
    int getLength() const;
        //Function that returns the length of the Vector Structure.

            /**
             * @brief Returns the maximum size of the Vector Structure
             *
             * Function will return the current maximum size of the Vector Structure
             *
             * @return int
             */
    int getMaxSize() const;
        //Function that returns the current maximum size of the vector

           /**
             * @brief Gets item at a specified location
             *
             * This function will retrieve an item from a specified location of the Vector class.
             * overloads the subscript operator
             *
             * @param index - location at which to get the item from
             *
             * @return T
             *
             * @pre Vector structure must already hold elements for them to be retrieved
             * @post will get the item at the specified location. if the location is not more than the Maximum size
             */
    T & operator[](int index);
    // returns the kth element
private:

            /**
             * @brief Resizes the Vector structure
             *
             * This function resizes the Vector, assigning a new maximum size to it
             *
             * @return void
             */
    void resizeList();
        //Function that resizes the list to accommodate more or less elements

        /// A Dynamic array that holds the content
    T *vectorList;         //An Dynamic array to hold the elements of the list

        /// The length of the Vector structure. Amount of elements in the structure
    int length;            // The length of the Vector class. The amount of elements in the Vector

        /// The maximum size of the Vector Structure
    int maxSize;           // Maximum size of the Vector structure


};

//Vector default constructor
template <class T>
Vector<T>::Vector(int size) // Default constructor
{
    if(size <= 0) // Checks whether the size entered is not less than on equal to 0
    {
        cout << "Creating a default array size of 100. "
             << "Since value entered is less than or equal to 0" << endl;

        maxSize = 100; // If less than or equal 0 then sets the size to 100
    }
    else
        maxSize = size;

    length = 0; // initializes the length to 0.

    vectorList = new T[maxSize];
}

//Vector destructor
template <class T>
Vector<T>::~Vector() // Destructor of the Vector class
{
    delete [] vectorList;
}

//Vector copy constructor
template <class T>
Vector<T>::Vector(const Vector<T> & otherVector) // Copy Constructor
{
    //Assigning the other Vectors Variables to this vectors Variables
        maxSize = otherVector.maxSize;
        length = otherVector.length;

        vectorList = new T[maxSize];
    // Copies the contents from one Vector to the other
        for(int i = 0; i < length; i++)
            vectorList[i] = otherVector.vectorList[i];
}

template <class T>
void Vector<T>::insertItem(const T & insItem) // Inserts item at the end of the Vector
{
    if(length >= maxSize) // Resizes the vector if the length approaches the maximum size
        resizeList();

    vectorList[length] = insItem; // Inserts the item at the end of the Vector
    length++; // increases the length by 1

}

template <class T>
void Vector<T>::insertItemAt(const T & insItem, int loc) // Inserts item at location specified by the user
{

    if(loc < 0 || loc >= maxSize) // checks whether the location specified lies outside the range of the vector
        cout << "The location of the item to be inserted is \nout of range " << endl;
    else
    {
        if(length >= maxSize) // Resizes the vector if the length approaches the maximum size
            resizeList();

        for(int i = length; i > loc; i--)  // moves the values from the specified location down
            vectorList[i] = vectorList[i-1];

        vectorList[loc] = insItem; // inserts the item at the location specified

        length++; // increases the length of the Vector
    }
}

template <class T>
int Vector<T>::getLength() const // returns the length of the Vector.
{
    return length;
}

template <class T>
void Vector<T>::removeItemAt(int location) // removes item at location specified by the user
{
    if (location < 0 || location >= length)  // checks whether the location specified lies outside the range of the vector
        cout << "The location of the item to be removed is out of range." << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            vectorList[i] = vectorList[i+1];
        length--; // reduces the length of the vector if the item is reduced
    }
}

template <class T>
void Vector<T>::getItemAt(T& itemretrieved, int loc) const // Retrieves item at location specified by the user
{
    if(loc < 0 || loc >= maxSize) // checks whether the location specified lies outside the range of the vector
    {
        cout << "Location entered is out of bounds." << endl;
    }
    else
        itemretrieved = vectorList[loc];

}

template <class T>
int Vector<T>::getMaxSize() const  // returns the maximum size of the vector
{
    return maxSize;
}

template <class T>
void Vector<T>::resizeList()  // Resizes the Length of the vector
{
    //std::copy(vectorList, vectorList+maxSize , newList); // Copies the data from one vector to another vector
    maxSize *= 2;
    T *newList = new T[maxSize]; // Creates a new dynamic array with twice the length of the first array

    for (int i = 0; i < length; i++)
            newList[i] = vectorList[i];

    delete[] vectorList; // Deletes the previous vector

    vectorList = newList;
}

template<class T>
T & Vector<T>::operator[] (int index)
{
    return vectorList[index];
}
#endif // VECTOR_H

