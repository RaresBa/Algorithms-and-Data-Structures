/*
CH-231-A
a2 p6.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

ifstream in("data.txt");

int main()
{
    //Making a map for the name and birthday of a person:
    map<string,string> birthMap;
    string l;

    //Checking if the file can be opened:
    if(in.is_open()==false)
    {
        cout<<"File could not be opened";
        return 1;
    }

    //Reading the name and dates from the file:
    while(getline(in,l))
    {
        string name,date;
        istringstream iss(l);
        iss>>name>>date;
        birthMap[name]=date;
    }

    //Getting the name we search for:
    string query;
    cout<<"What do you search for: ?"<<endl;
    getline(cin,query);


    //If we fint the query in the file we print it:
    if(birthMap.find(query)!=birthMap.end())
    {
        cout<<"The birthday for "<<query<<" is: "<<birthMap[query];
    }else{
        cout<<"Name not found"<<endl;
    }

    in.close();
    return 0;
}