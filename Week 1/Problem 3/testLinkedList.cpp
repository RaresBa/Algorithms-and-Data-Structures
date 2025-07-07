 /*
CH-231-A
a1 p3.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/


#include "LinkedList.h"
#include <iostream>


using namespace std;

int main()
{
    double a[5] = {5.1,5.2,5.3,5.4,5.5};
    char robot[] = "megathron";

    //The list of ints:
    List<int> lint;        

    //The list of doubles:               
    List<double> ldouble(5,a);          

    //The list of chars:
    List<char> lchars(10,robot);    

    //Pushing in front 10 elements into the ints list:       
    for (int i = 0; i < 10; i++)  
    {          
        lint.push_front(i);
    }

    //Popping back 3 elements from the list of doubles:
    for (int i = 1; i <= 3; i++) 
    {           
        ldouble.pop_back();
    }

    cout<<"The last element of the list of ints is: "<<lint.get_back()<<endl;
    cout<<"The last element from the list of doubles is: "<<ldouble.get_back()<<endl;
    cout<<"The first element from list of chars is:  "<<lchars.get_front()<<endl;
    cout<<"The size of the list of chars is : "<<lchars.get_size()<<endl;
    cout<<"The size of the list of ints is: "<<lchars.get_size()<<endl;
    cout<<"The size of the list of doubles is : "<<lchars.get_size();
    
    return 0;

}