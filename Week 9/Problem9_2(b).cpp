#include <iostream>
#include <stack>

using namespace std;

//The binary tree
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//Singly Linked list
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

//The tree to linkedlist combination
ListNode* treeToLinkedList(TreeNode* root)
{
    if(!root)
    {
        return nullptr;
    }
    stack<TreeNode*> stack;
    TreeNode* current=root;
    ListNode* head=nullptr;
    ListNode* prev=nullptr;
    while(!stack.empty()||current)
    {
        while(current)
        {
            stack.push(current);
            current=current->left;
        }
        current=stack.top();
        stack.pop();
        if(!head)
        {
            head=new ListNode(current->val);
            prev=head;
        }else
        {
            prev->next= new ListNode(current->val);
            prev=prev->next;
        }
    }
    return head;
};

void printLinkedList(ListNode* head) 
{
    ListNode* current=head;
    while (current) 
    {
        cout<<current->val;
        current=current->next;
    }
    cout << endl;
}

int main() 
{ 
    TreeNode* root=new TreeNode(3);
    root->left =new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    ListNode* sortedLinkedListHead = treeToLinkedList(root);
    printLinkedList(sortedLinkedListHead);

    return 0;
}