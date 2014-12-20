#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

#define TYPE int

typedef struct _node {
	TYPE key, val, color;
	struct _node *left, *right;
} Node;


Node *queue[80];
int front=-1, back=-1;

typedef struct _tree {
	Node *root;
} Tree;

int isRed(Node *node){
	if(node == NULL || node->color == BLACK)
		return BLACK;
	return RED;
}

Node *new_node(TYPE key, TYPE val, TYPE color) {
	Node *tmp = (Node*)(malloc(sizeof(Node)));
	tmp->key = key;
	tmp->val = val;
	tmp->color = color;
	tmp->left = tmp->right = NULL;
	return tmp;
}

Tree *init_tree(){
	Tree *tmp = (Tree*)malloc(sizeof(Tree));
	tmp->root = NULL;
	return tmp;
}

Node *rotateLeft(Node *node){
	Node *x = node;
	if(isRed(node->right)){
		x = node->right;
		node->right = x->left;
		x->left = node;
		x->color = node->color;
		node->color = RED;
	}
	return x;
}

Node *rotateRight(Node *node){
	Node *x = node;
	if(isRed(node->left)){
		x = node->left;
		node->left = x->right;
		x->right = node;
		x->color = node->color;
		node->color = RED;
	}
	return x;
}

void flipColors(Tree *tree, Node *node){
	if(node == NULL || node->left==NULL || node->right==NULL)
		return;
	if(!isRed(node) && isRed(node->left) && isRed(node->right)){
		if(tree->root != node)
			node->color = RED;
		node->left->color = node->right->color = BLACK;
	}
}

Node *put(Tree *tree, Node *node, TYPE key, TYPE val){
	if(tree->root == node && node==NULL){
		return new_node(key, val, BLACK);
	}
	if(node == NULL){
		return new_node(key, val, RED);
	}
	if(key < node->key){
		node->left = put(tree, node->left, key, val);
	}else if(key > node->key){
		node->right = put(tree, node->right, key, val);
	}else{
		node->val = val;
	}
	if(isRed(node->right) && !isRed(node->left)){
		node = rotateLeft(node);
	}
	if(isRed(node->left) && isRed(node->left->left)){
		node = rotateRight(node);
	}
	if(isRed(node->left) && isRed(node->right)){
		flipColors(tree, node);
	}
	return node;
}

TYPE get(Tree *tree, TYPE key){
	Node *tmp = tree->root;
	while(tmp != NULL){
		if(tmp->key == key){
			return tmp->val;
		}else if(tmp->key < key){
			tmp = tmp->left;
		}else{
			tmp = tmp->right;
		}
	}
	return -1;
}

void preorder(Node *node){
	if(node!=NULL){
		printf("%d - %d, ", node->key, node->color);
		preorder(node->left);
		preorder(node->right);
	}
}
void inorder(Node *node){
	if(node!=NULL){
		inorder(node->left);
		printf("%d ", node->key);
		inorder(node->right);
	}
}
void postorder(Node *node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->key);
	}
}


void enqueue(Node *node){
	if(front==back && back==-1){
		front = back = 0;
	}else{
		back++;
	}
	queue[back] = node;
}

int isEmpty(){
	if(front==back && back==-1){
		return 1;
	}
	if(front>back)
		return 1;
	return 0;
}

Node *dequeue(){
	if(isEmpty()){
		return NULL;
	}
	int tmp = front;
	front++;
	if(front>back){
		front = back = -1;
	}
	return queue[tmp];
}

void levelOrder(Node *node){
	Node *tmp;
	if(node!=NULL){
		enqueue(node);
		while(!isEmpty()){
			tmp = dequeue();
			printf("%d %d\n", tmp->key, tmp->color);
			if(tmp->left!=NULL){
				enqueue(tmp->left);
			}
			if(tmp->right!=NULL){
				enqueue(tmp->right);
			}
		}
	}
}


int main(int argc, char const *argv[]) {
	Tree *tree = init_tree();
	tree->root = put(tree, tree->root, 1, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 2, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 3, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 4, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 5, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 6, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 7, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 8, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 9, 1);
	printf("\n");
	preorder(tree->root);
	tree->root = put(tree, tree->root, 10, 1);
	printf("\n");
	preorder(tree->root);
	printf("\n");
	postorder(tree->root);
	printf("\n");
	inorder(tree->root);
	printf("\n");
	levelOrder(tree->root);
	return 0;
}