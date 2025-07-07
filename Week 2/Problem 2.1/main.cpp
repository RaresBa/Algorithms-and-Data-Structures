/*
CH-231-A
a2 p1.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/





#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main()
{
    //Creating the output file where we print the B list:
    ofstream out("listB.txt");

    //Task (1):
    list<int> A,B;
    int n;

    //Task (2):
    //Reading elemenets to the lists A and B:
    while(true)
    {
        cin>>n;
        if(n<=0)
        {
            break;
        }
        //Task (3):
        A.push_back(n);
        //Task (4):
        B.push_front(n);
    }

    //Task (5):
    //Printing list A
    cout<<"A: "<<endl;
    for(auto  i=A.begin();i!=A.end();i++)
    {
        cout<<*i<<" ";
    }
    //Printing list B in the file "out" and closing it:
    if(out.is_open())
    {
        for(auto i=B.begin();i!=B.end();i++)
        {
            out<<*i<<" ";
        }
        out.close();
    }
    //(6)
    cout<<endl;
    //(7)
    if(!A.empty())
    {
        int x;
        A.pop_front();
        A.push_back(x);
    }
    if(!B.empty())
    {
        int y;
        B.pop_front();
        B.push_back(y);
    }
    //(8)
    cout<<"A:";
    //Printing list A and putting a coma at the end:
    for(auto i=A.begin();i!=A.end();i++)
    {
        cout<<*i;
        if(next(i)!=A.end())
        {
            cout<<",";
        }
        cout<<" ";
    }
    cout <<endl;
    cout<<"B:";
    //Printing list B and putting a coma at the end:
    for(auto i=B.begin();i!=B.end();i++)
    {
        cout<<*i;
        if(next(i)!=B.end())
        {
            cout<<",";
        }
        cout<<" ";
    }
    cout<<endl;
    //(9)
    A.merge(B);
    A.sort();
    //(10)
    //Printing the sorted and merged list:
    for(auto i=A.begin();i!=A.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;   
    return 0;
}