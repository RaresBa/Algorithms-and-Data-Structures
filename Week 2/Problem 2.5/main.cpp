/*
CH-231-A
a2 p5.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>

using namespace std;

int main()
{
    set<int> n;
    //The random number generator with local time:
    srand(static_cast<unsigned int>(time(nullptr)));

    //Picking 6 random numbers:
    do
    {
        int pick=rand()%49+1;
        n.insert(pick);
    }while(n.size()<6);

    //Printing the numbers in an ascending order:
    for(auto i=n.begin();i!=n.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}