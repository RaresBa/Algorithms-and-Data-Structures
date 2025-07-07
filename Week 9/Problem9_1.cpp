#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
        struct StackNode{
            T data;
            StackNode *next;
            StackNode(const T& value):data(value),next(nullptr){}
        };
        
        StackNode* top; // top of stack
        int size; // -1 if not set, value otherwise
        int current_size; //unused if size = -1
    
public:
        Stack(int new_size=-1):top(nullptr),size(new_size),current_size(0){}
        ~Stack()
        {
            while (!isEmpty())
            {
                pop();
            }
        }

        void push(const T& x)
        {
            if(size!=1 && current_size>=size)
            {
                cerr<<"Stack overflow!"<<endl;
                return;
            }
            StackNode* newNode= new StackNode(x);
            newNode->next=top;
            top=newNode;
            current_size++;
        }

        T pop()
        {
            if(isEmpty())
            {
                cerr<"Stack underflow!"<<endl;
                throw out_of_range("Stack underflow");
            }
            StackNode* temp=top;
            T poppedData= temp->data;
            top= top ->next;
            delete temp;
            current_size--;
            return poppedData;
        }

        bool isEmpty() const
        {
            return top==nullptr;
        }
};


int main()
{
    Stack<int> stack(5);
    for(int i=1;i<=5;i++)
    {
        stack.push(i);
    }
    stack.push(6); // Stack overflow message
    while(!stack.isEmpty())
    {
        cout<<stack.pop()<<endl;
    }
    stack.pop(); // Stack underflow message
    return 0;
}