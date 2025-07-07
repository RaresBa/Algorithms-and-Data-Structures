//For this problem I only did a "tamplate" I did not
//code the functions because I do not know how.



#include <iostream>

//I get limit the colors of the red-black tree:
enum Color 
{
    RED,BLACK
};

struct Node 
{
    int data;
    Color color;
    Node *left,*right,*parent;
};

class RedBlackTree 
{

private:

    Node *root;

protected:

    void rotateLeft(Node *&);
    void rotateRight(Node *&);

public:
    RedBlackTree();
    void insertRB(int);
    void deleteRB(Node *&);
    Node *predecessor(const Node *);
    Node *successor(const Node *);
    Node *getMinimum();
    Node *getMaximum();
    Node *search(int);
};

RedBlackTree::RedBlackTree()
{
    root = NULL;

}

// Rotate left function:
void RedBlackTree::rotateLeft(Node *&ptr) 
{

}

// Rotate right function:
void RedBlackTree::rotateRight(Node *&ptr)
{
    
}

//The function to insert a value in the tree:
void RedBlackTree::insertRB(int data) 
{
    
}

//The function to delete a value from the tree:
void RedBlackTree::deleteRB(Node *&ptr)
{

}

//The function to find a predecessor:
Node *RedBlackTree::predecessor(const Node *ptr) 
{
  
}

//The function to find a successor:
Node *RedBlackTree::successor(const Node *ptr)
{

}

//The function to find a minimum node:
Node *RedBlackTree::getMinimum() 
{

}

//The function to find a maximum node:
Node *RedBlackTree::getMaximum()
{

}

//The function to search for a node with given data
Node *RedBlackTree::search(int data)
{
   
}

int main()
{
    RedBlackTree rbTree;
    return 0;
}
