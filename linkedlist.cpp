#include<iostream>
#define max 15
using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedlist
{
public:
    node* root;
    linkedlist();
    void list_insert(int);
    void disp();
};

linkedlist::linkedlist()
{
    root = NULL;
}
void linkedlist::list_insert(int d)
{
    if(root==NULL)
    {
        root = new node;
        root->data = d;
        root->next = NULL;
    }
    else
    {
        node* t = new node;
        t->data = d;
        t->next = root;
        root = t;
    }
}
void linkedlist::disp()
{
    node *tmp = root;
    if(root==NULL)
    {
        cout<<"empty\n";
        return;
    }
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

int main()
{
    linkedlist l;
    l.list_insert(1);
    l.disp();
    l.list_insert(3);
    l.disp();
    l.list_insert(5);
    l.disp();
}
