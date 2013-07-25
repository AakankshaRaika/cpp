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
    node *current,*r2;
    node* root;
    void rev_insert(node* tmp);
    void reverse(node*);
public:
    linkedlist();
    void insert(int);
    void disp();
    void reverse();
};

linkedlist::linkedlist()
{
    root = NULL;
}

void linkedlist::insert(int d)
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
    cout<<"\n";
    node *tmp = this->root;
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
    cout<<"\n";
}

void linkedlist::reverse(){
    r2 = root;
    current = NULL;
    this->reverse(root);
    r2 = current = NULL;
}

void linkedlist::reverse(node *h){
    if(h==NULL){
        return;
    }
    else{
        this->reverse(h->next);
        this->rev_insert(h);
    }
}

void linkedlist::rev_insert(node *h){
    if(h->next==NULL){
        current = root = h;
        root->next = NULL;
        return;
    }else if(h==r2){
        current->next = h;
        current->next->next = NULL;
        return;
    }else{
        current->next = h;
        current = current->next;
    }
}

int main()
{
    linkedlist l;
    l.disp();
    l.reverse();
    for(int i=1;i<=20;i++)
        l.insert(i);
    l.disp();
    l.reverse();
    l.disp();
    l.insert(50);
    l.disp();
    l.reverse();
    l.disp();
}
