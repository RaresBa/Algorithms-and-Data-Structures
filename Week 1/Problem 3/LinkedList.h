 /*
CH-231-A
a1 p3.cpp
Stefan Rares Baiasu
sbaiasu@jacobs-university.de
*/
 
 
 
 #include <iostream>

 using namespace std;
 
 
    template <class temp>
    struct node
    {
        temp value;
        node* prev;
        node* next;
    };

    template <typename temp> class List
    {
        private:
            int size;
            node<temp> *head;
        public:

            //The default constructor:
            List();   
            //The parametric constructor:                  
            List(int size, temp array[]);
            //The destructor:
            ~List(); 

            //Pushinh elements back and front:
            void push_front(temp elem);
            void push_back(temp eleme);

            //Poping elements back and front:
            temp pop_front(void);
            temp pop_back(void);
            //Getting elements back and front:
            temp get_front(void);
            temp get_back(void);

            //The get method:
            int get_size();
    };

    //The default constructor:
    template <class temp>
    List<temp>::List() 
    {
        cout<<"The default Constructor has been called: "<<endl;
        size=0; 
        head=new node<temp>;
        if(head==nullptr)
        {
            exit(1);
        }
        head->next=nullptr;
        head->prev=nullptr;
    }


    //The parametric constructor:
    template <class temp>
    List<temp>::List(int size, temp array[])
    {
        cout<<"The parametric Constructor has been called"<<endl;
        this->size=size;
        node<temp>*aux1;
        node<temp>*aux2;
        head=new node<temp>;
        if(head==nullptr)
        {
            exit(1);
        }
        aux1=new node<temp>;
        if(aux1==nullptr)
        {
            exit(1);
        }
        head=aux1;
        aux1->value=array[0];
        aux1->prev=nullptr;
        for(int i=1;i<size;i++)
        {
            aux2 = new node<temp>;
            if(aux2 == nullptr)
            {
                exit(1);
            }
            aux1->next=aux2;
            aux2->value=array[i];
            aux2->prev=aux1;
            aux1=aux2;
        }
        aux2->next=nullptr;
    }


    //The destructor consturctor:
    template <class temp>
    List<temp>::~List()
     {
        cout<<"The Destructor constructor has been called"<<endl;
        while(head != nullptr)
        {
            node<temp>*aux=head;
            aux=head;
            head=head->next;
            delete aux;  
        }
    }


    //The pushing in the front method:
    template <class temp>
    void List<temp>::push_front(temp var)
     {
        cout<<"Pushing the "<<var<<" in the front"<<endl;
        node<temp>*aux=new node<temp>;
        if(aux == nullptr)
        {
          exit(1);
        }
        size++;
        aux->value=var;
        aux->prev=nullptr;
        aux->next=head;
        head->prev=aux;
        head=aux;
    }

    //The push in the back method:
    template <class temp>
    void List<temp>::push_back(temp var)
     {
        cout<<"Pushing the "<<var<<" in the back"<<std::endl;
        node<temp> *aux = new node<temp>;
        if(aux == nullptr)
        {
            exit(1);
        }
        node<temp>*c=head;
        aux->value = element;
        aux->next = nullptr;
        while(c->next != nullptr)
        {
            c=c->next;
        }
        size++;
        aux->prev=c;
        c->next=aux;
    }

    //The popping from the front method:
    template <class temp>
    temp List<temp>::pop_front() 
    {
        temp n=head->value;
        cout<<"Popping "<<n<<" from front"<<endl;
        node<temp>*aux=head->next;
        aux->prev=nullptr;
        size--;
        delete head;
        return x;
    }

    //The popping from the back method:
    template <class temp>
    temp List<temp>::pop_back()
    {
        temp n;
        node<temp>*c=head;
        while(c->next!=nullptr)
        {
            c=c->next;
        }
        size--;
        n=c->value;
        cout<<"Popping "<<x<<" from back"<<endl;
        c->prev->next = nullptr;
        delete c;
        return x;
    }

    //The getting from the front method:
    template <class temp>
    temp List<temp>::get_front()
     {
        return head->value;
    }

    //The get from the back method:
    template <class temp>
    temp List<temp>::get_back()
     {
        node<temp>*c=head;
        while(c->next != nullptr)
        {
            c=c->next;
        }
        return c->value;
    }

    //Getting the size:
    template <class temp>
    int List<temp>::get_size() 
    {
        return size;
    }

