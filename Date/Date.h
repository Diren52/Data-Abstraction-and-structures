#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

    /**
	 * @class Date
	 * @brief  Manages all date that a data is obtained in
     *
	 * @author Joseph Sigar
	 * @version 01
	 * @date 14/04/2017 Joseph Sigar, updated date header to cater for Assignment specifications
	 *
	 * @author Joseph Sigar
	 * @version 02
	 * @date 15/04/2017 Joseph Sigar, updated the date Cpp
	 *
	 * @author Joseph Sigar
	 * @version 03
	 * @date 16/04/2017 Joseph Sigar, updated Unit Test of the date methods
	 *
	 * @author Joseph Sigar
	 * @version 04
	 * @date 18/04/2017 Joseph Sigar, modify the I/O operations to cater for required specifications in the main cpp
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
     * @date 25/05/2017 Joseph Sigar, included overloaded operators for use in the BST
     *
     * @author Joseph Sigar
     * @version 08
     * @date 28/05/2017 Joseph Sigar, tested the class with the inclusion of the assignment operators
     *
	 * @todo Make the Date more 'Future Proof' to allow less change for future requirements
	 *
	 * @bug N/A at the moment may need further testing
	 *
	 */

class Date
{
    public:

           /**
            * @brief The Default constructor of Date class
            *
            * This function is the default constructor of the date class
            * which would set the date values to a default value 0/0/0.
            *
            *@return void
            */
        Date();
            //Default constructor of date

            /**
             * @brief An Initializer constructor of Date class
             *
             * This function is a constructor of the date class that set's
             * User defined variables to the date class.
             *
             * @param day - the day to set
             * @param month - the month to set
             * @param year - the year to set
             *
             * @return void
             */
        Date(unsigned day, unsigned month, unsigned year);
            // A constructor of date that initializes the parameters

            /**
             * @brief A copy constructor of the Date class
             *
             * This function is a copy constructor of the Date class that copies
             * another Date defined elsewhere (most likely by user) to the Date class.
             *
             * @param otherDate - the other date to copy
             *
             * @return void
             */
        Date(const Date & otherDate);
            //Copy Constructor of the date class

            /**
             * @brief A Destructor of the Date class
             *
             * This function is a destructor of the Date class that deletes
             * the Date class.
             *
             * @return void
             */
        virtual ~Date();
            // A Destructor of the date class.

            /**
             * @brief sets the day of the date
             *
             * This function sets the day of the date the data was obtained
             *
             * @param day - day of the date
             *
             * @return void
             *
             * @post would set the day of the date to a user defined value
             */
        void setDay(unsigned day);
            // set the day of the result obtained

            /**
             * @brief returns the day of the date
             *
             * This function returns the day of the date the data was obtained
             *
             * @return unsigned
             *
             * @pre day must have been initialized and set to a valid value
             *      or date class must have some content
             * @post will return to the user the day
             */
        unsigned getDay() const;
            // return the day

            /**
             * @brief sets the month of the date
             *
             * This function sets the month of the date the data was obtained
             *
             * @param month - month of the date
             *
             * @return void
             *
             * @post would set the month of the date to a user defined value
             */
        void setMonth(unsigned month);
        // sets the month

            /**
             * @brief returns the month
             *
             * This function returns the month of the date the data was obtained
             *
             * @return unsigned
             *
             * @pre month must have been initialized and set to a valid value
             *      or date class must have some content
             * @post will return to the user the month
             */
        unsigned getMonth() const;
        // returns the month

            /**
             * @brief sets the year of the date
             *
             * This function sets the year of the date the data was obtained
             *
             * @param year - year of the date
             *
             * @return void
             *
             * @post would set the year of the date to a user defined value
             */
        void setYear(unsigned year);
            // sets the year

            /**
             * @brief returns the year of the date
             *
             * This function returns the year of the date the data was obtained in
             *
             * @return unsigned
             *
             * @pre year must have been initialized and set to a valid value
             *      or date class must have some content
             * @post will return to the user the year
             */
        unsigned getYear() const;
            // returns the year

            /**
              * @brief Returns the month name
              *
              * Function returns the month name for an associated month number
              *
              *@return string
              *
              * @pre The month number must have been initialized and set to a valid value
              *      of the date class must have some content in it
              * @post will return to the user the month name of the date
              */
        string printMonth(unsigned mnt);
              //Function that return the corresponding month to its initiated value.

            /**
             * @brief Checks two date for equality
             *
             * Function returns a bool of true or false if two dates are equal or not
             *
             * @param dte - Date to compare with
             * @return bool
             *
             * @post returns whether two dates are equal or not.
             */
        bool operator == (const Date &dte);
        //compares two dates

            /**
             * @brief Checks if one date is more than another date
             *
             * Function returns a bool of true or false if one date is greater than the other
             *
             * @param dte - Date to compare with
             * @return bool
             *
             * @post returns whether the other date is less than this date.
             */
        bool operator > (const Date &dte);
        //compares two dates

            /**
             * @brief Checks if one date is less than another date
             *
             * Function returns a bool of true or false if one date is less than the other
             *
             * @param dte - Date to compare with
             * @return bool
             *
             * @post returns whether the other date is more than this date.
             */
        bool operator < (const Date &);
        //compares two dates

    private:
        /// The day of the data was obtained
        unsigned day; // day the data is obtained

        /// The month the same data was obtained
        unsigned month; // month the data is obtained

        /// The year the data was obtained in
        unsigned year; // year the data is obtained

            /**
              * @brief Checks the year set by user
              *
              * A helper Function that checks whether the set year is within a valid range
              *
              * @return bool
              *
              * @pre the year would need to be already set by the user
              * @post returns true/false if the year set is within a set range
              */
        bool isYear(unsigned yr) const;
            //Function that checks whether the entered value is withing the range.

            /**
              * @brief Checks the year set by user is a leap year
              *
              * A helper Function that checks whether the set year is a leap year or not
              *
              * @return unsigned
              *
              * @pre the year would need to be already set by the user
              * @post returns 0/1 if the year set is a leap year or not
              */
        unsigned isLeapYear() const;
            //Function that checks whether a year was a leap year or not.

            /**
              * @brief Checks the month set by user
              *
              * A helper Function that checks whether the set month is within a valid range
              *
              * @return bool
              *
              * @pre the month would need to be already set by the user
              * @post returns true/false if the month set is within a set range
              */
        bool isMonth(unsigned mnt) const;
            //Function that checks whether the value entered is a valid month

            /**
              * @brief Checks the day set by user
              *
              * A helper Function that checks whether the set day is within a valid range
              *
              * @return bool
              *
              * @pre the day would need to be already set by the user
              * @post returns true/false if the day set is within a set range
              */
        bool isDay(unsigned dy) const;
            //Functions that checks whether the value entered is a val=

            /**
              * @brief returns the number of days
              *
              * A helper Function that returns the number of days in a month. including leap years
              *
              * @return unsigned
              *
              * @pre the month needs to be initialized or set by the user prior to function returning any value
              * @post returns true/false if the minutes set is within a set range
              */
        unsigned daysInMonth() const;
            //Function that returns the number of days in a month.


};

#endif // DATE_H
