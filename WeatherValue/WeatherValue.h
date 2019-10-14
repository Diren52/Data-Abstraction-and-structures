#ifndef WEATHERVALUE_H
#define WEATHERVALUE_H
#include "../Date/Date.h"
#include "../Time/Time.h"
#include <string>
#include <iostream>

    /**
	 * @class WeatherValue
	 * @brief  Manages all weather values of the data
     *
	 * @author Joseph Sigar
	 * @version 01
	 * @date 20/04/2017 Joseph Sigar, Created WeatherValue header and cpp file
	 *
	 * @author Joseph Sigar
	 * @version 02
	 * @date 21/04/2017 Joseph Sigar, Unit Tested the available methods of the WeatherValue class
	 *
	 * @author Joseph Sigar
	 * @version 03
	 * @date 22/04/2017 Joseph Sigar, created and updated the I/O operations in the main cpp
     *
	 * @author Joseph Sigar
	 * @version 04
	 * @date 25/04/2017 Joseph Sigar, Added comments and updated deoxygen comments on the Header file and Cpp file
     *
     * @author Joseph Sigar
     * @version 05
     * @date 28/04/2017 Joseph Sigar, Add comments on both the header and cpp file
     *
     * @author Joseph Sigar
     * @version 06
     * @date 28/05/2017 Joseph Sigar,Unit tested it again
     *
	 * @todo Make the WeatherValue more 'Future Proof' to allow less change for future requirements
	 * @todo Find a better naming convention for the WeatherValue class
	 *
	 * @bug N/A at the moment may need further testing
	 *
	 */

using namespace std;

class WeatherValue
{
    public:

            /**
             * @brief The Default constructor of the WeatherValue class.
             *
             * This function will initialize the Weather values to a set default value
             *
             * @return void
             */
        WeatherValue();
            //Default constructor

            /**
             * @brief A Destructor of the WeatherValue class.
             *
             * This function deletes the WeatherValue class.
             *
             * @return void
             */
        ~WeatherValue();
            // Function is the destructor of the WeatherValue class

            /**
             * @brief A copy constructor of the WeatherValue class
             *
             * This function copies another WeatherValue defined elsewhere (most likely by client) to the WeatherValue class.
             *
             * @param otherWeatherValue - the other weather value that is to be copied to the class weather value
             *
             * @return void
             */
        WeatherValue(const WeatherValue& otherWeatherValue);
            //Copy constructor

            /**
             * @brief An Initializer constructor of WeatherValue class
             *
             * This function is a constructor of the WeatherValue class that set's
             * User defined variables to the WeatherValue class.
             *
             * @param date - the date to set
             * @param time - the time to set
             * @param windSpeed - the wind speed to set
             * @param solarRadiation - the solar Radiation to set
             *
             * @return void
             */
        WeatherValue(const Date & date, const Time & time, double windSpeed, double solarRadiation);
            // Initializer constructor

            /**
             * @brief returns the solar radiation of the data
             *
             * This function returns the solar radiation of the data obtained
             *
             * @return double
             *
             * @pre solar radiation must have been initialized and set to a valid value
             *      or WeatherValue class must have some content
             * @post will return to the user the solar radiation
             */
        double getSolarRadiation() const;
             // gets the solar radiation

             /**
             * @brief sets the solar radiation
             *
             * This function sets the solar radiation of the data
             *
             * @param solRad - solar radiation to be set
             *
             * @return void
             *
             * @post would set the solar radiation to a user defined value
             */
        void setSolarRadiation(double solRad);
            // sets the solar radiation

            /**
             * @brief returns the wind speed of the data
             *
             * This function returns the wind speed of the data obtained
             *
             * @return double
             *
             * @pre wind speed must have been initialized and set to a valid value
             *      or WeatherValue class must have some content
             * @post will return to the user the wind speed
             */
        double getWindSpeed() const;
             // gets the wind speed

            /**
             * @brief sets the wind speed
             *
             * This function sets the wind speed of the data
             *
             * @param windSpd - wind speed to be set
             *
             * @return void
             *
             * @post would set the wind speed to a user defined value
             */
        void setWindSpeed(double windSpd);
             // sets the wind speed

            /**
             * @brief Returns converted solar radiation
             *
             * This function will convert the solar radiation from W/m^2 to kWh/m^2
             * and return the results to the client.
             *
             * @param solarRad -  the value of the solar radiation to be converted
             *
             * @return double
             *
             * @post will return to the client a converted value.
             **/
        double convertSolarRadiation(double solarRad);
            // Converts the solar radiation

            /**
             * @brief returns the date of the data obtained
             *
             * This function returns the date of the data obtained
             *
             * @return Date
             *
             * @pre Date must have been initialized and set to a valid value
             *      or WeatherValue class must have some content
             * @post will return to the user the date
             */
        const Date & getDate() const;
            // gets the date

            /**
             * @brief sets the date
             *
             * This function sets the date of the data obtained
             *
             * @param dte - date to be set
             *
             * @return void
             *
             * @post would set the date to a user defined value
             */
        void setDate(const Date & dte);
            // sets the date

            /**
             * @brief returns the Time of the date
             *
             * This function returns the time of the data obtained
             *
             * @return Time
             *
             * @pre Time must have been initialized and set to a valid value
             *      or WeatherValue class must have some content
             * @post will return to the user the Time
             */
        const Time & getTime() const;
            // gets the time

            /**
             * @brief sets the date
             *
             * This function sets the date of the data obtained
             *
             * @param tme - date to be set
             *
             * @return void
             *
             * @post would set the date to a user defined value
             */
        void setTime(const Time & tme);
            // sets the time

    private:

        /// The wind speed of the data obtained
        double windSpeed; // wind speed on a particular time

        /// The solar radiation of the data obtained
        double solarRadiation; // solar radiation on a particular time

        /// The Time the data was obtained
        Time time; // time the data was obtained

        /// The date the data was obtained
        Date date; // date the data was obtained
};

#endif // WEATHERVALUE_H
