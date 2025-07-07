#include <iostream>
#include <cassert>

using namespace std;
 
class Node 
{
public:
    int key;
    int value;
    Node(int key, int value):key(key),value(value){}
};

class HashTable
{
private:
    Node **arr;
    int maxSize;
    int currentSize;
    int hashcode(int key)
    {
        return key%maxSize;
    }
public:
    //Constructor Method:
    HashTable(int size=10):maxSize(size),currentSize(0)
    {
        arr=new Node*[maxSize]; 
        for(int i=0;i<maxSize;i++)
        {
            arr[i]=nullptr;
        }
    }

    //Destructor Method:
    ~HashTable() {
        for (int i = 0; i < maxSize; i++)
        {
            delete arr[i];
        }
        delete[] arr;
    }

    //InsertNode Method
    void insertNode(int key, int value)
    {
        int hash=hashcode(key);
        int originalHash=hash;
        while (arr[hash]!=nullptr && arr[hash]->key != key) 
        {
            hash=(hash + 1)%maxSize;
            if (hash==originalHash) {
                throw overflow_error("Hash table overflow");
            }
        }
        if (arr[hash] != nullptr)
        {
            delete arr[hash];
        }
        arr[hash] = new Node(key, value);
        currentSize++;
    }

    int get(int key)
    {
        int hash=hashcode(key);
        int originalHash=hash;
        while (arr[hash]!=nullptr && arr[hash]->key!=key)
        {
            hash=(hash+1)%maxSize;
            if(hash==originalHash) 
            {
                return -1;
            }
        }
        return arr[hash]!=nullptr?arr[hash]->value:-1;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }
};

