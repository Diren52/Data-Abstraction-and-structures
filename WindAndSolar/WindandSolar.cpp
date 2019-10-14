#include "WindandSolar.h"

WindandSolar::WindandSolar()
{
//    initializing the map
}

WindandSolar::~WindandSolar()
{
//    deleting the map
}

double WindandSolar::maxValue(unsigned month, unsigned year)
{
    Collect<double> c;
    int countc = 0;
    BinarySearchTree<double> myTree;
    double tempMax=0;

    while (countc <= someMap[year][month].getLength())
    {
        myTree.Insert(getWeatherValue(year, month, countc).getWindSpeed());
        countc++;
    }

    myTree.inOrderTraversal(c.getData); // using the function pinter to return some value from the BST
    for(int i=0; i<c.dataSize();i++)
        if (c[i] > tempMax)
            tempMax = c[i];

    return tempMax;
}

double WindandSolar::maxSolarRad(const Date &dte, Vector<Time> & tme)
{
    Collect<double> c;
    unsigned year = dte.getYear(), month = dte.getMonth(), day = dte.getDay();
    int countc = 0;
    BinarySearchTree<double> myTree;

    double tempSol=0;

    while (countc <= someMap[year][month].getLength())
    {
        if(dte.getDay() == getWeatherValue(year, month, countc).getDate().getDay())
            myTree.Insert(getWeatherValue(year, month, countc).getSolarRadiation());

        countc++;
    }

    myTree.inOrderTraversal(c.getData); // using the function pinter to return some value from the BST

    for(int i = 0; i < c.dataSize(); i++)
        if (c[i] > tempSol)
            tempSol = c[i];

    countc = 0;
    while (countc <= someMap[year][month].getLength())
    {
        if(day == getWeatherValue(year, month, countc).getDate().getDay() && tempSol == getWeatherValue(year, month, countc).getSolarRadiation())
            tme.insertItem(getWeatherValue(year, month, countc).getTime());
        countc++;
    }

    return tempSol;
}

void WindandSolar::averageWindSpeed(unsigned year, double aveWindSpeed[])
{
    int countc = 0;
    double totalSum[12];
    double totalCount[12];

    for (unsigned j = 0; j < 12; j++)
    {
        totalSum[j] = 0;
        totalCount[j] = 0;
    }

    for (unsigned mth = 0; mth < 12; mth++)
    {
        while (countc <= someMap[year][mth+1].getLength())
        {
            totalSum[mth] += getWeatherValue(year, mth+1, countc).getWindSpeed();
            totalCount[mth] += 1;
            countc++;
        }
        countc = 0;
    }

    for (unsigned i = 0; i < 12; i++)
        aveWindSpeed[i] = calcAverage(totalSum[i], totalCount[i]);
}

double WindandSolar::calcAverage(double totalSum, double totalCount) const
{
    if (totalSum != 0 || totalCount != 0)
        return totalSum/totalCount;
    else
        return -1;
}

void WindandSolar::totSolarRadiation(unsigned year, double solarRad[])
{
    int countc = 0;
    double tempsolrad;

     for (unsigned mth = 0; mth < 12; mth++)
    {
        while (countc <= someMap[year][mth+1].getLength())
        {
            if (getWeatherValue(year,mth+1,countc).getSolarRadiation() >= 80 )
            {
                tempsolrad = getWeatherValue(year, mth+1, countc).getSolarRadiation();
                solarRad[mth] += getWeatherValue(year, mth+1, countc).convertSolarRadiation(tempsolrad);
            }
            countc++;
        }

        countc = 0;
    }
}

void WindandSolar::setWeatherValue(const WeatherValue & weValue, unsigned year, unsigned month)
{
   someMap[year][month].insertItem(weValue);
}

WeatherValue & WindandSolar::getWeatherValue(unsigned year, unsigned month, int i)
{

    return someMap[year][month][i];
}
