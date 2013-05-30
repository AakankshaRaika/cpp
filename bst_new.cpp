#include<iostream>
using namespace std;

struct node{
int data;
node *left;
node *right;
node *parent;
};

node *root=NULL,*temp;

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data;
    }
}

void search(node* root,int val){
if(root==NULL){
cout<<"False";
}
else{
if(root->data==val){
cout<<"true";
}
else if(val<root->data){
search(root->left,val);
}
else{
search(root->right,val);
}
}
}

void preorder(node *root){
    if(root!=NULL){
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void insert_recurs(node *root,node *temp){
    if(temp->data<=root->data){
        if(root->left==NULL){
            root->left=temp;
            temp->parent=root;
        }
        else{
            insert_recurs(root->left,temp);
        }
    }
    else{
        if(root->right==NULL){
            root->right=temp;
            temp->parent=root;
        }
        else{
            insert_recurs(root->right,temp);
        }
    }
}

void delete_node(node* root,int val){

}

node* insert(node *root,int d){
    temp = new node;
    temp->data=d;
    temp->right=temp->left=temp->parent=NULL;
    if(root==NULL)
    {
     return temp;
    }
    else{
        insert_recurs(root,temp);
    }
    return root;
}

int main(){
int d;
while(true){
    cin>>d;
    if(d==0)
        break;
    root=insert(root,d);
}
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
preorder(root);
cin>>d;
search(root,d);
cout<<endl;
}
