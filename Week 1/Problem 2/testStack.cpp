/*
CH-231-A
a1 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <string>
#include <cstring>
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    //Parametric Constructor:
    Stack<int> sa(20);        

    for(int i = 0; i < 10 ; i++)
    {
        //Pusing the Elements:
        sa.push(i); 
    }                            
    int back=sa.back();  
    cout<<"The last element is: "<<back<<endl;  
    
    //Copy Constructor
    Stack<int> sb(sa);                      
    for(int i=0;i<10;i++)        
    {    
        //Poping the elements:    
        sa.pop(back);
    }
    return 0;
}