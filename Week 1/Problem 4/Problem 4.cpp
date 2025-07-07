/*
CH-231-A
a1 p4.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/



#include <iostream>
#include <vector>
#include <string>
#include <string.h>


using namespace std;

int main()
{
    int size=0;
    string st;
    vector<string> v;
    
    //Reading words from the keyboard until the user enteres "End" (1) and (2):

    do
    {
        cin>>st;
        v.push_back(st); 
        size++;
    }while(st!="END");

    int i=0;

    //Printing the words on the startd output separated by spaces: (3)
    for(i=0;i<size;i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;

    //Printing the words separated by commas: (4)
    for(i=0;i<=size;i++)
    {
        cout<<v[i]<<", ";
    }
    cout<<v[i]<<endl;
    return 0;
}