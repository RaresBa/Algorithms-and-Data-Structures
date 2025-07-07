/*
CH-231-A
a2 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <list>
#include "WindGauge.h"

using namespace std;

int main()
{
    WindGauge test;

    test.currentWindSpeed(15);
    test.currentWindSpeed(16);
    test.currentWindSpeed(12);
    test.currentWindSpeed(15);
    test.currentWindSpeed(15);

    test.dump();
    cout<<endl;

    test.currentWindSpeed(16);
    test.currentWindSpeed(17);
    test.currentWindSpeed(16);
    test.currentWindSpeed(16);
    test.currentWindSpeed(20);
    test.currentWindSpeed(17);
    test.currentWindSpeed(16);
    test.currentWindSpeed(15);
    test.currentWindSpeed(16);
    test.currentWindSpeed(20);

    test.dump();
    cout<<endl;
    
    return 0;
}