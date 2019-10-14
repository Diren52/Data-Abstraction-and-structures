#ifndef COLLECT_H
#define COLLECT_H
#include "../Vector/Vector.h"

/**
     * @class Collect
     * @brief A data Structure that stores data gotten from elsewhere
     *
     * if used as a call back. would retrieve data from whence been called from.
     *
     * @author Joseph Sigar
     * @version 01
     * @date 30/05/17 Joseph Sigar Created Basic collect class with no templates
     *
     * @author Joseph Sigar
     * @version 02
     * @date 31/05/17 Joseph Sigar Modified and tested the Basic collect.
     *
     * @author Joseph Sigar
     * @version 03
     * @date 1/06/17 Joseph Sigar Modified the class to cater for templates.
     *
     * @author Joseph Sigar
     * @version 04
     * @date 02/06/17 Joseph Sigar incorporated into the assignement
     *
     * @todo Make class into a minimal but complete class
     *
     * @bug N/A at the moment. Needs further testing.
     *
     */

template<class T>
class Collect  // collects the T data from the callback
{

public:

        /**
         * @brief Stores data into the class
         *
         * function will store data into the class if used as a function pointer
         *
         * @param data - data to be stored into the collect class
         *
         * @return void
         *
         * @post will store data from another class(bst) into this class
         */
    static void getData( T &data);
    // A retains the data used in the call back.
        /**
         * @brief returns the size of the vector
         *
         * @return int
         * @post returns the number of elements in the vector
         */
    int dataSize();
    // returns the number of elements in A.

        /**
         * @brief returns the kth element to the user
         *
         * @param k - element location
         * @return T
         *
         * @post will return the kth element to the client for processing or storage.
         */
    T& operator[](int k);
    // Returns the kth element
private:
    ///data are stored in the vector class
    static Vector<T> A;  // use a vector to store values
};

template<class T>
Vector<T> Collect<T>::A;// 100 objects get created here and unit's value of c would track obj creations.

template<class T>
void Collect<T>::getData( T &data)
{
    A.insertItem(data);   // keeps the data that is returned. static method needs static data
}

template <class T>
int Collect<T>::dataSize()
{
    return A.getLength();
}

template <class T>
T & Collect<T>::operator[](int k) // Assuming that k is positive and within the required range
{
    return A[k];   // used to return the data that has been collected.
}
#endif // COLLECT_H
