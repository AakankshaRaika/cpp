#include<iostream>
using namespace std;
#define max 10

struct node
{
    int data;
    node *left,*right;
};

node* root;

void ins(node* x,node* v)
{
    if(x==NULL)
    {
        x = v;
    }
    else if((x->data)<(v->data))
    {
        ins(x->left,v);
    }
    else
    {
        ins(x->right,v);
    }
}

void inorder(node* x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        cout<<x->data<<" ";
        inorder(x->right);
    }
    else
    {
        cout<<"huha";
    }
}

int main()
{
    root = NULL;
    for(int i=0;i<10;i++)
    {
        node* v = new node;
        v->data = 2;
        v->left = v->right = NULL;
        ins(root,v);
    }
    //cout<<root->data;
    inorder(root);
}
