#include <stdio.h>
#include <stdlib.h>

#define S(n) (scanf("%d",&n))

typedef struct _node {
	int data;
	struct _node *next;
} Node;

typedef struct _stack {
	Node *top;
	int size;
} Stack;

Node *create_node(int d){
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	node->data = d;
	node->next = NULL;
	return node;
}

Stack *create_stack(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	s->size = 0;
}

int empty_stack(Stack *s){
	return (s->size==0);
}

void push(Stack *s, int val){
	Node *node = create_node(val);
	if(empty_stack(s)){
		s->top = node;
	}else{
		node->next = s->top;
		s->top = node;
	}
	s->size++;
}

int pop(Stack *stck){
	if(empty_stack(stck))
		return -1;
	Node *tmp = stck->top;
	int d = tmp->data;
	stck->size--;
	stck->top = stck->top->next;
	free(tmp);
	return d;
}

int top(Stack *stck){
	if(empty_stack(stck))
		return -1;
	return stck->top->data;
}

Node **create_list_vertices(int v){
	Node **list;
	list = (Node **)(malloc(v*sizeof(Node*)));
	int i;
	for(i=0;i<v;i++){
		list[i] = NULL;
	}
	return list;
}

typedef struct _adj_list {
	Node **list;
	int vertices, edges;
} Adj_List;

Adj_List *create_adj_list(int v, int e){
	Adj_List *adlist;
	adlist = (Adj_List*)malloc(sizeof(Adj_List));
	adlist->list = create_list_vertices(v);
	adlist->vertices = v;
	adlist->edges = e;
	return adlist;
}

void add_edge(Adj_List *lst, int from, int to){
	Node *node = create_node(to);
	Node *start = lst->list[from];
	if(lst->list[from] == NULL){
		lst->list[from] = node;
	}else{
		node->next = lst->list[from];
		lst->list[from] = node;
	}
}

void dfs(Adj_List *lst, int start,int *visited, Stack *stck){
	visited[start] = 1;
	Node *begin = *(lst->list + start);
	printf("%d\n", start);
	for(; begin!=NULL; begin=begin->next){
		if(!visited[begin->data]){
			dfs(lst, begin->data, visited, stck);
		}
	}
	push(stck, start);
}

Stack *dfs_traverse(Adj_List *lst){
	int *visited = (int*)malloc(lst->vertices*sizeof(int));
	int i;
	Stack *stck = create_stack();
	for(i=0;i<lst->vertices;i++){
		visited[i] = 0;
	}
	for(i=0;i<lst->vertices;i++){
		if(!visited[i]){
			dfs(lst, i, visited, stck);
		}
	}
	free(visited);
	return stck;
}

int main(int argc, char **argv) {
	Adj_List *lst;
	lst = create_adj_list(7, 11);
	add_edge(lst, 0, 5);
	add_edge(lst, 0, 2);
	add_edge(lst, 0, 1);
	add_edge(lst, 3, 6);
	add_edge(lst, 3, 5);
	add_edge(lst, 3, 4);
	add_edge(lst, 5, 4);
	add_edge(lst, 6, 4);
	add_edge(lst, 6, 2);
	add_edge(lst, 3, 2);
	add_edge(lst, 1, 4);
	int i;
	Node *strt;
	for(i=0;i<lst->vertices;i++){
		printf("%d - ", i);
		strt = lst->list[i];
		while(strt!=NULL){
			printf("%d, ", strt->data);
			strt = strt->next;
		}
		printf("\n");
	}
	printf("-----\n");
	Stack *topo_stack = dfs_traverse(lst);
	printf("------\n");
	while(!empty_stack(topo_stack)){
		printf("%d\n", pop(topo_stack));
	}
	return 0;
}