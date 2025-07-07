/*
CH-231-A
a2 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include "WindGauge.h"
#include <iostream>
#include <list>
#include <numeric>

using namespace std;

WindGauge::WindGauge(int p):p(p)
{

}


//Finding the current wind speed:
void WindGauge::currentWindSpeed(int speed)
{
    history.push_back(speed);
    if(history.size()>p)
    {
        history.pop_front();
    }
}

//Finding the highest temp:
int WindGauge::highest() const 
{
    int maxi=history.front();
    for(int i:history)
    {
        if(i>maxi)
        {
            maxi=i;
        }
    }
    return maxi;
}

//Finding the lowest temp:
int WindGauge::lowest() const 
{
    int mini=history.front();
    for(int i:history)
    {
        if(i<mini)
        {
            mini=i;
        }
    }
    return mini;
}


//The speed Average:
int WindGauge::average() const
{
    int s;
    s=accumulate(history.begin(),history.end(),0);
    return s/history.size();
}

void WindGauge::dump() const
{
    cout<<"The lowest is : "<<lowest()<<endl;
    cout<<"The highest is: "<<highest()<<endl;
    cout<<"The average is "<<average()<<endl;
}