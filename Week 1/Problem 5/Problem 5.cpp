/*
CH-231-A
a1 p5.cpp
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
    int size = 0;
    bool check=false;
    string st;
    vector<string> v;
    vector<string>::iterator viter;

    //Read strings from the keyboard until user enters "END": (1) and (2)
    do
    {
        getline(cin, st);
        v.push_back(st); 
        if(size==5)
        {
            check=true;
        }
        size++;
    }while(st!="END");

    //Swapping the second and fifth element: (3)
    if(check)
    {
        string copy=v[4];
        v[4]=v[1];
        v[1]=copy;
    }

    //Replacing the last element: (4)
    v[size-1] = "???";
    
    int i=0;

    //Printing the strings: (5)
    for(int i=0;i<size-1;i++)
    {
        cout<<v[i]<<", ";
    }
    cout<<v[i]<<endl;

    //Printing the output separated by ";" (6)
    viter = v.begin();
    cout<<*viter;
    viter++;
    while(viter!=v.end())
    {
        cout<<"; "<<*viter;
        viter++;
    }
    cout<<endl;

    //Printing the output separate by one " " (7)
    viter = v.end();
    while(viter != v.begin())
    {
        cout<<*viter<<" ";
        viter--;
    }
    cout<<*viter<<endl;

    return 0;
}