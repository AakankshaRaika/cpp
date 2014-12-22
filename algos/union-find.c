#include <stdio.h>
#include <stdlib.h>

typedef struct __set_node {
	int parent, rank;
} Node;

Node *create_node(int parent, int rank){
	Node *node = (Node*)malloc(sizeof(Node));
	node->parent = parent;
	node->rank = 0;
	return node;
}

typedef struct __set {
	Node **list;
	int size;
} Set;

Set *create_set(int vertices){
	Set *set = (Set*)malloc(sizeof(Set));
	Node **lst = (Node**)malloc(sizeof(Node*)*vertices);
	int i;
	for(i=0;i<vertices;i++){
		lst[i] = create_node(i,0);
	}
	set->list = lst;
	set->size = 0;
	return set;
}

int find(Set *set, int v){
	if(set->list[v]->parent != v){
		set->list[v]->parent = find(set, set->list[v]->parent);
	}
	return set->list[v]->parent;
}

void unify(Set *set, int x, int y){
	int xp = set->list[x]->parent;
	int yp = set->list[y]->parent;
	if(xp == yp){
		return;
	}
	if(set->list[xp]->rank < set->list[yp]->rank){
		set->list[xp]->parent = yp;
	}else if(set->list[xp]->rank > set->list[yp]->rank){
		set->list[yp]->parent = xp;
	}else{
		set->list[yp]->parent = xp;
		set->list[xp]->rank++;
	}
}

int main(){
	char c;
	int d;
	Set *set = create_set(11);
	unify(set, 1, 2);
	unify(set, 2, 3);
	unify(set, 3, 10);
	unify(set, 0, 1);
	unify(set, 9, 10);
	unify(set, 5, 6);
	unify(set, 1, 5);
	int i;
	for(i=0;i<11;i++){
		printf("%d - %d\n", i, find(set, i));
	}
	for(i=0;i<11;i++){
		free(set->list[i]);
	}
	free(set->list);
	free(set);
	return 0;
}