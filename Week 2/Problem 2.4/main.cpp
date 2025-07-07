/*
CH-231-A
a2 p4.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <Vector.h>

using namespace std;

int main()
{
    //Making a vector and filling it with 30 elements:
    vector<int> n;
    for(int i=0;i<=30;i++)
    {
        n.push_back(i);
    }

    //Putting 5 in the end of the vector:
    n.push_back(5);

    //Reversing the vector:
    reverse(n.begin(),n.end());

    //Printing the vector:
    cout<<"The reversed vector: ";
    for(auto i=n.begin();i!=n.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    //Replacing 5 with 129:
    replace(n.begin(),n.end(),5,129);

    //Printing the new vector with "129":
    cout<<"The new vector: ";
    for(auto i=n.begin();i!=n.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}