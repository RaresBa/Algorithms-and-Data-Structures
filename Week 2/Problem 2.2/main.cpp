/*
CH-231-A
a2 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/


#include <iostream>
#include <deque>

using namespace std;

int main()
{
    //(1):
    deque<float> A;
    float value;
    //(2):
    while(true)
    {
        cin>>value;
        if(value==0)
        {
            break;
        }
        //(3):
        if(value>0)
        {
            A.push_back(value);
        }

        if(value<0)
        {
            A.push_front(value);
        }
    }
    //(4):
    cout<<"A: ";
    for(auto i=A.begin();i!=A.end();i++)
    {
        cout<<*i<<" ";
    }
    //(5):
    cout<<endl;

    return 0;
}