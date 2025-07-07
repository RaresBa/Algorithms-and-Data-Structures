
/*
CH-231-A
a2 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/




#include <iostream>
#include <list>
#include <deque>

using namespace std;

class WindGauge 
{
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;

    void dump() const;
private:
    
    int p;
    deque<int>history;
};
