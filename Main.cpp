#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "WindAndSolar/WindandSolar.h"

istream & operator >>(istream & input, Date & D);
ostream & operator <<( ostream & os, const Date & D );

ostream & operator <<( ostream & os, const Time & T);
istream & operator >>(istream & input, Time & T);

ostream & operator <<( ostream & os, const WeatherValue & W);
istream & operator >> (istream & input, WeatherValue & W);

ostream & operator <<( ostream & os, const WindandSolar & S);
istream & operator >> (istream & input, WindandSolar & S);

void initializeArray(double clientArray[], unsigned arrayLength, unsigned num);
void clientPrintFnctn (double dataToPrint, unsigned monthNum);
template<class T>
void clientPrintFnctn(const Date & dte, double num, const Vector<T> & tempNum);
void clientPrintToFile(unsigned year, double dataOne[], double dataTwo[]);
void displayMenu();
void dochoice(unsigned choice, WindandSolar & sm);


using namespace std;

int main()
{
    unsigned choice;
    //ifstream infile ("WindAndSolarTest.csv"); //For testing the Wind and Solar/ main program
                                                              // to be commented out when required
    ifstream infile ("data/met_index.txt");
    if( !infile ) return -1; // exits with a error message if file not found


    WindandSolar windSolar;

    //infile >> windSolar; used for testing
    string dtName;

    while (getline(infile, dtName))
    {
        string temp = "data/" + dtName;
        //cout << temp << endl; Client debugging reading of multiple files

        const char * dataName = temp.c_str();

        ifstream infile2(dataName);
        infile2 >> windSolar;
        infile2.close();
    }
    infile.close();

    cout << fixed << showpoint << setprecision(1); // sets the precision of the output to screen to 1 decimal point

    do
    {
        displayMenu();
        cout << "Enter choice here: ";
        cin >> choice; // reads user choice
        cout << endl;
        dochoice(choice, windSolar);
    }while (choice != 6);

    return 0;
}

ostream & operator <<( ostream & os, const WindandSolar & W)
{
    return os;
}

istream & operator >> (istream & input, WindandSolar & W)
{

    static WeatherValue weatherlog;
    unsigned solarpos = 0, i = 0, windpos = 0, timepos = 0;
    string data, str, str2, str3, str4, str5;

    getline(input, data); // gets the header from the file
    istringstream temp(data); // temporarily assigns the header as an input stream

    while (temp) // searches the new temporary stream for specific headers
    {
        getline(temp, str, ',');
        if (str == "WAST" || str == "UTC")
            timepos = i;
        else if(str == "S")
                windpos = i;
        else if(str == "SR")
                solarpos = i;
        i++;
    }

    while(getline(input, str2))
    {
        istringstream temp1(str2); // assigns a line to a temporary input stream

        for (unsigned j = 0; j < i; j++)  // searches the temporary input stream
        {
            getline(temp1, str3, ',');

            if (j == timepos || j == windpos || j == solarpos)
                str4 = str4 + str3 + " "; //concatenates the required input
        }

        istringstream temp2(str4); // turns the required input into an input stream
        //cout << ++ii << " " << str4 << endl;
        str4.clear(); // clears the string variable to allow new values

        temp2 >> weatherlog;

        W.setWeatherValue(weatherlog, weatherlog.getDate().getYear(), weatherlog.getDate().getMonth());
        //cout << weatherlog << endl;
    }

    return input;
}

void displayMenu()
{
    cout << "Enter 1\nTo display the maximum Wind speed for a specific month and year.\n"
        << "\nEnter 2\nTo display the average wind speed for each month of a specific year.\n"
        << "\nEnter 3\nTo display the total solar radiation in kWh/m^2 for each month of a year.\n"
        << "\nEnter 4\nTo save the average wind speed and total solar radiation for each month of a \nyear to a file"
        << "named WindandSolar.csv\n"
        << "\nEnter 5\nTo Display the maximum Solar Radiation and the corresponding time(s) for \ndd/mm/yyyy.\n"
        << "\nEnter 6 \nTo quit the program.\n" << endl;
}

void dochoice(unsigned choice, WindandSolar & windSolar)
{
    unsigned month, year;
    double maxValue, maxSolar;
    double windArray[12];
    double solarArray[12];
    static Date dte;
    Vector <Time> tme; // storing the values of the time.
                       // Can be a vector or an array. Since the output of values is not known.
                       // cons of using the array, the number of values is not known.
                       // no difference between a dynamic array and a vector. However Dynamic arrays have a
                       // slight problem when determining the number of elements in the array

    switch(choice)
    {
    case 1:{
        cout << "Enter month (1 - 12) and year here (respectively): " ;
        cin >> month >> year;
        cout << endl;
        maxValue = windSolar.maxValue(month, year);
        cout << "The Maximum wind speed is: " << maxValue << " km/h";
        cout << endl;
        }break;

    case 2:{
        initializeArray(windArray, 12, 0);
        cout << "Enter year here: ";
        cin >> year;
        cout << endl;

        windSolar.averageWindSpeed(year, windArray);

        for (unsigned i = 0; i < 12; i++)
            clientPrintFnctn(windArray[i], i + 1);

        cout << endl;
        }break;

    case 3:{
        initializeArray(solarArray, 12, 0);
        cout << "Enter year here: ";
        cin >> year;
        cout << endl;

        windSolar.totSolarRadiation(year, solarArray);

        for (unsigned i = 0; i < 12; i++)
            clientPrintFnctn(solarArray[i], i + 1);

        cout << endl;
        }break;

    case 4:{
        initializeArray(windArray, 12, 0);

        cout << "Enter year here: ";
        cin >> year;
        cout << endl;

        windSolar.averageWindSpeed(year, windArray);

        initializeArray(solarArray, 12, 0);

        windSolar.totSolarRadiation(year, solarArray);

        clientPrintToFile(year, windArray, solarArray);

        }break;

    case 5:{
        Date dte1;
        cout << "Enter date in the format d/mm/yyyy: " ;
        cin >> dte1;
        cout << endl;

        maxSolar = windSolar.maxSolarRad(dte1, tme);

        clientPrintFnctn(dte1, maxSolar, tme);

        }break;

    case 6:
        cout << "You have chosen to quit the program. \nThank you and Goodbye.\n"
             << "---------------------------------------------------------------------------- \n" << endl;
        break;
    default:
        cout << "You have entered an invalid input. \nPlease review the menu and try again.\n"
             << "---------------------------------------------------------------------------- \n" << endl;
    }
}

ostream & operator <<( ostream & os, const WeatherValue & W)
{
    return os;
}

istream & operator >> (istream & input, WeatherValue & W)
{
    //string spd, rad, strdte, strtme;
    double speed, radiation;
    static Date dte;
    static Time tme;

    input >> dte >> tme >> speed >> radiation;

/*  getline(input, strdte, ',');
    getline(input, strtme, ',');
    getline(input, spd, ',');
    getline(input, rad, ',');

    stringstream str1;

    str1.clear();
    str1.str("");
    str1.str(strdte);
    str1 >> dte;

    str1.clear();
    str1.str("");
    str1.str(strtme);
    str1 >> tme;

    str1.clear();
    str1.str("");
    str1.str(spd);
    str1 >> speed;

    str1.clear();
    str1.str("");
    str1.str(rad);
    str1 >> radiation;
*/

    W.setDate(dte);
    W.setTime(tme);
    W.setWindSpeed(speed);
    W.setSolarRadiation(radiation);

    return input;
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

ostream & operator <<( ostream & os, const Date & D )
{
    os << D.getDay() << "/" << D.getMonth() << "/" << D.getYear();
    return os;
}

istream & operator >>(istream & input, Time & T)
{
    string tme;
    unsigned hours, minutes;
    stringstream str1;

    input >> tme;

    unsigned flash = tme.find_last_of(" "); //Assuming there is no space after the time i.e 01/01/2001  01:05,
    unsigned slash = tme.find_last_of(':');

    str1.clear();
    str1.str(" ");
    str1.str(tme.substr(flash + 1, slash));
    str1 >> hours;

    str1.clear();
    str1.str(" ");
    str1.str(tme.substr(slash + 1));
    str1 >> minutes;

    T.setHour(hours);
    T.setMinutes(minutes);

    return input;
}

ostream & operator <<( ostream & os, const Time & T)
{
    cout << T.getHour() << ":" << T.getMinutes();
    return os;
}

void initializeArray(double clientArray[], unsigned arrayLength, unsigned num)
{
    for (unsigned i = 0; i < arrayLength; i++)
        clientArray[i] = num;
}

void clientPrintFnctn (double dataToPrint, unsigned monthNum)
{
    Date dte;

            if(dataToPrint != 0) // cant have an average of zero unless there are negative values
                                                          // in the data file. in which the client would change these values
                cout << dte.printMonth(monthNum) << ": " << dataToPrint << endl;
            else
                cout << dte.printMonth(monthNum) << ": No data for this month" << endl;

}

void clientPrintToFile(unsigned year, double dataOne[], double dataTwo[])
{
    Date dte;
    ofstream ofile ("WindandSolar.csv");

    ofile << fixed << showpoint << setprecision(1);

    ofile << year << endl;

    for (unsigned i = 0; i < 12; i++)
        if (dataOne[i] != 0 && dataTwo[i] != 0)
            ofile << dte.printMonth(i+1) <<", " << dataOne[i] << ", " << dataTwo[i] << endl;

}

template<class T>
void clientPrintFnctn(const Date & dte, double num, const Vector<T> & tempNum)
{
    Time tme1;

    cout << dte << endl;
    cout << "Highest Solar Radiation for the Day: " << num << " W/m2" << endl;
    cout << "Time: " << endl;
    for (int i = 0; i < tempNum.getLength(); i++)
    {
        tempNum.getItemAt(tme1, i);
        cout << tme1 << endl;
    }
}
