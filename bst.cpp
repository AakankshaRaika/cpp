#include<iostream>
using namespace std;
#define max 10

struct node
{
    int data;
    node *left,*right;
};

class bst
{
public:
    node *root;
    bst();
    void bst_insert(node*,int);
    //void bst_delete(node*,int);
    void inorder(node*);
    //void maximum(node*);
    //void minimum(node*);
};

bst::bst()
{
    root = NULL;
}

void bst::bst_insert(node* root,int d)
{
    if(root==NULL)
    {
        node* tmp = new node;
        tmp->data = d;
        tmp->left = NULL;
        tmp->right = NULL;
        root = tmp;
        //cout<<root->data<<" ";
    }
    else if(d<=root->data)
    {
        bst_insert(root->left,d);
    }
    else
    {
        bst_insert(root->right,d);
    }
}

void bst::inorder(node* x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        cout<<x->data<<" ";
        inorder(x->right);
    }
}

int main()
{
    bst b;
    b.bst_insert(b.root,3);
    b.bst_insert(b.root,2);
    b.inorder(b.root);
}
