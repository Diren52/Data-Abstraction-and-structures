#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

    /**
	 * @class Time
	 * @brief  Manages all time that a data is obtained
     *
	 * @author Joseph Sigar
	 * @version 01
	 * @date 10/04/2017 Joseph Sigar, Created Time header
	 *
	 * @author Joseph Sigar
	 * @version 02
	 * @date 11/04/2017 Joseph Sigar, created the Time Cpp
	 *
	 * @author Joseph Sigar
	 * @version 03
	 * @date 17/04/2017 Joseph Sigar, Updated Unit Test the available methods
	 *
	 * @author Joseph Sigar
	 * @version 04
	 * @date 18/04/2017 Joseph Sigar, created and updated the I/O operations in the main cpp
     *
	 * @author Joseph Sigar
	 * @version 05
	 * @date 25/04/2017 Joseph Sigar, Added comments and updated deoxygen comments on the Header file and Cpp file
     *
     * @author Joseph Sigar
     * @version 06
     * @date 28/04/2017 Joseph Sigar, Add comments on both the header and cpp file
     *
     * @author Joseph Sigar
     * @version 07
     * @date 28/05/2017 Joseph Sigar,Unit tested it again
     *
     *
	 * @todo Make the Time more 'Future Proof' to allow less change for future requirements
	 *
	 * @bug N/A at the moment may need further testing
	 *
	 */

using namespace std;
class Time
{
    public:

          /**
            * @brief The Default constructor of Time class
            * This function is the default constructor of the Time class
            * which initializes the time variables to 00:00;
            *
            *@return void
            */
        Time();
            //Default constructor of the time class

             /**
             * @brief An Initializer constructor of Time class
             *
             * This function is a constructor of the time class that set's
             * User defined variable to the time class.
             *
             * @param hr - the hour to set
             * @param mins - the minutes to set
             *
             * @return void
             */
        Time(unsigned hr, unsigned mins);
            //Initializer constructor of the time class.

             /**
             * @brief A copy constructor of Time class
             *
             * This function is a copy constructor of the time class that copies
             * another time defined elsewhere (most likely by user) to the time class.
             *
             * @param otherTime - the time to copy
             *
             * @return void
             */
        Time(const Time &otherTime);
            //Copy constructor of the time class

            /**
             * @brief A Destructor of the Time class
             *
             * This function is a destructor of the Time class that deletes
             * the Time class.
             *
             * @return void
             */
        virtual ~Time();
            //Destructor of the time class

            /**
             * @brief sets the Hour of the time
             *
             * This function sets the hour of the time the data was obtained
             *
             * @param hrs - hour of the time
             * @return void
             *
             * @post would set the hour of the time to a user defined value
             */
        void setHour(unsigned hrs);
            //Function sets a user defined hour to the time class

            /**
             * @brief sets the minutes of the time
             *
             * This function sets the minutes of the time the data was obtained
             *
             * @param mins - minutes of the time
             *
             * @return void
             *
             * @post would set the minutes of the time to a user defined value
             */
        void setMinutes(unsigned mins);
            //Function sets a user defined minute to the time class

            /**
             * @brief returns the hour of the time
             *
             * This function returns the hour of the time the data was obtained
             *
             * @return unsigned
             *
             * @pre hours must have been initialized and set to a valid value
             *      or time class must have some content
             * @post will return to the user the hours of the time
             */
        unsigned getHour() const;
            //Function returns to the user the hours.

            /**
             * @brief returns the minutes of the time
             *
             * This function returns the minutes of the time the data was obtained
             *
             * @return unsigned
             *
             * @pre minutes must have been initialized and set to a valid value
             *      or time class must have some content
             * @post will return to the user the minutes of the time
             */
        unsigned getMinutes() const;
            //Function returns to the user the minutes.

    private:

            /**
              * @brief Checks the hours set by user
              *
              * A helper Function that checks whether the set Hour is within a valid range
              *
              * @return bool
              *
              * @pre the hours would need to be already set by the user
              * @post returns true/false if the hours set is within a set range
              */
        bool isHour(unsigned hour) const;
            //Functions that checks whether the value entered is a valid hour.

            /**
              * @brief Checks the minutes set by user
              *
              * A helper Function that checks whether the set minutes is within a valid range
              *
              * @return bool
              *
              * @pre the minutes would need to be already set by the user
              * @post returns true/false if the minutes set is within a set range
              */
        bool isMinutes(unsigned minutes) const;
            //Function that checks whether the value entered is a valid minute;

            ///The hour when the data was obtained
        unsigned hours; // Hours at which the data is obtained

            ///The minutes when the data was obtained
        unsigned minutes; // minutes at which the data is obtained

};

#endif // TIME_H
