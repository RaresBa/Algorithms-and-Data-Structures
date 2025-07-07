/*
CH-231-A
a1 p1.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Complex 
{
private:
    int real,imaginar;
public:

    //The setting method for real numbers
    void set_real(int r) 
    {
        real=r;
    }

    //The setting method for imaginar numbers
    void set_imaginar(int i)
    {
        imaginar=i;
    }

    Complex(int r=0, int i=0) 
    {
        real=r;  
        imaginar=i;
    }

    //The overloading of the operator "!="
    bool operator!=(Complex object)
    {
         return real!=object.real||imaginar!=object.imaginar;
    }
};
//The tamplate for the class t:
template<class tem>

//The array_search function using tamplate "tem":
int array_search(tem array[], tem e, int size)
{
    for(int i=0;i<size && array[i]!=e;i++)
    {

    }
    if(i==size)
        return -1;
    return i;
}

int main()
{
    //Declaring an intiger,char,object array:
    int intiger_array[10] = {0,1,2,3,4,5,6,7,8,9};
    char char_array[] = "abcdefghi";
    Complex class_array[10];

    
    for(int i=0; i<10;i++)
    {
        class_array[i].set_real(i);
        class_array[i].set_imaginar(i+1);
    }

    //The searching in all 3 arries:
    cout<<"Searching 4 in the intiger array: "<<array_search<int>(intiger_array, 4, 10)<<endl;
    cout<<"Searching i in the character array: "<<array_search<char>(char_array, 'i', 10)<<endl;
    cout<<"Searching 1 2 in the objects array: "<<array_search<Complex>(class_array, Complex(9,10), 10)<<endl;
    return 0;
}