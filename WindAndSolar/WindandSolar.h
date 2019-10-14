#ifndef WINDANDSOLAR_H
#define WINDANDSOLAR_H
#include "../WeatherValue/WeatherValue.h"
#include "../Vector/Vector.h"
#include "../BinarySearchTree/BinarySearchTree.h"
#include "../Collect/Collect.h"
#include <map>
#include <iostream>

    /**
	 * @class WindandSolar
	 * @brief  Manages multiple weather values of the data using the Vector class.
     *
     * Weather values are constructed/stored using the WeatherValue class.
     * Which are stored in a data structure. in this case the Vector class defined here.
     *
	 * @author Joseph Sigar
	 * @version 01
	 * @date 21/04/2017 Joseph Sigar, Created WindandSolar header and cpp file
	 *
	 * @author Joseph Sigar
	 * @version 02
	 * @date 22/04/2017 Joseph Sigar, Unit Tested the available methods of the WindandSolar class
	 *
	 * @author Joseph Sigar
	 * @version 03
	 * @date 23/04/2017 Joseph Sigar, created and updated the I/O operations in the main cpp
     *
	 * @author Joseph Sigar
	 * @version 04
	 * @date 24/04/2017 Joseph Sigar, Added comments and updated doxygen comments on the Header file and Cpp file
     *
     * @author Joseph Sigar
     * @version 05
     * @date 28/04/2017 Joseph Sigar, Add comments on both the header and cpp file
     *
     * @author Joseph Sigar
	 * @version 06
	 * @date 14/05/2017 Joseph Sigar, tested out the BST in this class
	 *
	 * @author Joseph Sigar
	 * @version 07
	 * @date 24/05/2017 Joseph Sigar, Included the Collect class
	 *
	 * @author Joseph Sigar
	 * @version 08
	 * @date 02/06/2017 Joseph Sigar, fixed bugs associated with collect class
     *
	 * @todo Make the WindandSolar more 'Future Proof' to allow less change for future requirements
	 * @todo I think i achieved the above statement.
	 *
	 *
	 * @bug Not sure if I should be doing the output to Wind and solar csv here. Very hard to decide
	 *
	 */

using namespace std;

class WindandSolar
{
    /// The Map that holds that data for the WeatherClass
        typedef map<unsigned, map<unsigned, Vector<WeatherValue> > > Map;

    public:
            /**
             * @brief The Default constructor.
             *
             * This function is the default constructor of the WindandSolar class
             * which will initialize the Vector structure in the WindandSolar class
             * to a set default value
             *
             * @return void
             */
       WindandSolar();
            // Default constructor

            /**
             * @brief The copy constructor.
             *
             * This function is the copy constructor of the WindandSolar class
             * which will copy another WindandSolar Values to another WindandSolar class
             *
             * @param otherWindAndSolar - the windAndSolar value that is to be copied over
             *
             * @return void
             */
        WindandSolar(const WindandSolar & otherWindAndSolar);
            // Copy constructor

            /**
             * @brief The Destructor
             *
             * This function is the destructor of the WindandSolar class
             * which will delete the WindandSolar class after the program completes.
             *
             * @return void
             */
        ~WindandSolar();
            // Destructor function

            /**
             * @brief Calculates the average wind value
             *
             * This function will calculate the average wind speed value for each month in a specified year
             *
             * @param year - The year at which to calculate the average from
             * @param aveWindSpeed -  a fixed array thats will hold the average wind speed for each month
             *
             * @return void
             * @pre there need to be data in the class to function
             * @post Will store the average value for each month in a specified year.
             */
        void averageWindSpeed(unsigned year, double aveWindSpeed[]);
            // Calculates the average value for each month

            /**
             * @brief Calculates the total solar radiation
             *
             * This function will calculate the total solar radiation for each month in a specified year
             *
             * @param year - The year at which to calculate the average from
             * @param solarRad -  a fixed array that holds the total sum of the value to be averaged for each month.
             *
             * @return void
             *
             * @pre there need to be data in the class to function
             * @post Will store the total value for the total radiation for each month in a specified year.
             */
        void totSolarRadiation(unsigned year, double solarRad[]) ;
            // Calculates the total solar radiation for each month

            /**
             * @brief Calculates the Maximum value
             *
             * This function will calculate the maximum value of the wind speed
             *
             * @param month -  the specified month
             * @param year -  the specified year
             *
             * @return double
             * @pre there need to be data in the class to function
             * @post Will return the maximum value of the wind speed
             */
        double maxValue(unsigned month, unsigned year);
            // Calculates the maximum value'

            /**
             * @brief sets the WeatherValue
             *
             * This function will set the WeatherValue of the data at the end of the Map
             *
             * @param weatherVal - weather value to be inserted in to the map
             * @param year -  the year the value is to be inserted to
             * @param month -  the month the val is to be inserted to
             *
             * @return void
             *
             * @post would set the solar radiation to a user defined value
             */
       void setWeatherValue(const WeatherValue & weValue, unsigned year, unsigned month);
        //Set the Weather Values.

            /**
             * @brief returns the WeatherValue
             *
             * This function will return the WeatherValue of the data obtained
             *
             * @param year - the specified of a value
             * @param month -  the specified month of a value
             * @param i -  Location at which the WeatherValue is stored in the Vector Class
             * @return WeatherValue
             *
             * @pre The Vector class must have elements that correspond to the WeatherValue class
             * @post will return to the user an individual solar radiation from a certain location
             */
        WeatherValue & getWeatherValue(unsigned year, unsigned month, int i) ;
        // returns the WeatherValue

            /**
             * @brief Calculates the Maximum value
             *
             * This function will calculate the maximum value of the solar radiation
             *
             * @param dte -  the specified data to search
             * @param tme -  stores the time/s of the maximum values
             *
             * @return double
             * @pre there need to be data in the class to function
             * @post Will return the maximum value of the solar radiation and the associated time
             */
        double maxSolarRad(const Date &, Vector<Time> & tme);
        // returns the max solar radiation and associated time

    private:
        ///a map container that stores the values
        Map someMap;

            /**
             * @brief Calculates the average value
             *
             * This function will calculate the average value on a basic level
             *
             * @param totalSum - The total sum of the value to be averaged.
             * @param totalCount -  The total count of the value to be averaged
             *
             * @return double
             *
             * @post Will return the average value.
             */
        double calcAverage(double totalSum, double totalCount) const;
            // Calculates the average value

};

#endif // WINDANDSOLAR_H
