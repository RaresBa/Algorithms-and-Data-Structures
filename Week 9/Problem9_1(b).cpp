#include <iostream>
#include <stdexcept>
#include <stack>

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

template <typename T>
class QueueWithTwoStacks
{
    private:
        Stack<T> stack1;
        Stack<T> stack2;
    public:
        void enqueue(const T& x)
        {
            stack1.push(x);
        }
        T dequeue()
        {
            if(stack2.isEmpty())
            {
                if(stack1.isEmpty())
                {
                    cerr<<"Queue is empty"<<endl;
                    throw out_of_range("Queue underflow");
                }
                while(!stack.isEmpty())
                {
                    stack2.push(stack1.pop()); 
                }
            }
            return stack2.pop();
        }
        bool isEmpty() const
        {
            return stack1.isEmpty() && stack2.isEmpty();
        }
};
int main()
{
    QueueWithTwoStacks <int> queue;
    for(int i=1;i<-5;i++)
    {
        queue.enqueue(i);
    }
    for(int i=0;i<5;i++)
    {
        cout<<queue.dequeue()<<endl;
    }
    try
    {
        cout<<queue.dequeue()<<endl;
    }catch(const out_of_range& e)
    {
        cerr<< endl;
    }
    return 0;
}