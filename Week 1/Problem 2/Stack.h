/*
CH-231-A
a1 p2.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <cstring>


using namespace std;


const int initial=200;

template <class tem>
 class Stack
 {
    private:
        int max,current;
        tem array[initial];
    public:

        //The default constructor:
        Stack()
        {                                      
            cout<<"The default constructor has been called"<<endl;
            max=10; 
            current=0;
        }       
        //The copy constructor:      
        Stack(const Stack& stk)
        {                           
            cout<<"The copy constructor has been called"<<endl;
            max=stk.max;
            current=stk.current;
            for(int i=0;i<maxSize;i++)
            {
                array[i] = stk.array[i];
            }
        }
        //The size constructor:
        Stack(int s)
        {       
            cout<<"Size Constructor has been called"<<endl;
            max=s;
            current=-1;
        }

        //The desctructor:
        ~Stack()
        {
            cout<<"The destructor has been called"<<endl;
        };

        //The push method:
        bool push(tem element)
        {                               
            if(current==max)
                return false;
            cout<<"Pushing: "<<element<<endl;
            current++;
            array[current]=element;
            return true;
        }

        //The pop method:
        bool pop(tem& out)
        {              
            if(current==-1)
                return false;
            cout<<"Popping: "<<array[current]<<endl;
            out = array[current];
            current--;
            return true;
        }
        
        //The back mathod:
        tem back(void)
        {
            return array[current];
        }

};