#include <iostream>
#include <stack>

using namespace std;

//The single linked list:
struct  ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//The binary tree:
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Finding the middle element:
ListNode* findMiddle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=nullptr;
    while(fast && fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev)
    {
        prev->next=nullptr;
    }
    return slow;
}

TreeNode* sortedList(ListNode* head)
{
    if(!head)return nullptr;
    ListNode* mid=findMiddle(head);
    TreeNode* root=new TreeNode(mid->val);
    if(head==mid)
    {
        return root;
    }
    root->left=sortedList(head);
    root->right=sortedList(mid->next);
    return root;
}
int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    TreeNode* root=sortedList(head);
    return 0;
}
