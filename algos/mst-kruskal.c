#include <stdio.h>
#include <stdlib.h>

#define S(n) (scanf("%d",&n))

typedef struct __edge {
	int from, to;
	float weight;
} Edge;

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

void free_set(Set *set, int v){
	int i;
	for(i=0;i<v;i++){
		free(set->list[i]);
	}
	free(set->list);
	free(set);
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


Edge *create_edge_list(int e){
	Edge *edge = (Edge*)malloc(sizeof(Edge)*e);
	return edge;
}

void min_heapify(Edge *edges, int root, int sz){
	int left = (root<<1)+1;
	int right = (root+1)<<1;
	int mn = root;
	if(left<sz && edges[left].weight < edges[mn].weight)
		mn = left;
	if(right<sz && edges[right].weight < edges[mn].weight)
		mn = right;
	Edge tmp;
	if(mn != root){
		tmp = edges[mn];
		edges[mn] = edges[root];
		edges[root] = tmp;
		min_heapify(edges, mn, sz);
	}
}

void convert_to_min_heap(Edge *edges, int e){
	int i;
	for(i=(e-1)/2;i>=0;i--){
		min_heapify(edges, i, e);
	}
}

Edge pop_min_fromheap(Edge *edges, int *sz){
	Edge tmp = edges[0];
	*sz -=1;
	if(*sz > 0){
		edges[0] = edges[*sz];
		min_heapify(edges, 0, *sz);
	}
	return tmp;
}

Edge *kruskal_mst(Edge *edges, int v, int e){
	Edge *mst = create_edge_list(v-1);
	int _ctr = 0;
	Set *set = create_set(v);
	int i, sz;
	sz = e;
	Edge tmp;
	for(i=0;i<e;i++){
		tmp = pop_min_fromheap(edges, &sz);
		if(find(set, tmp.from) != find(set, tmp.to)){
			unify(set, tmp.from, tmp.to);
			mst[_ctr++] = tmp;
		}
	}
	free_set(set, v);
	return mst;
}


int main(int argc, char const *argv[]){
	int v, e;
	S(v), S(e);
	int sz = e;
	Edge *edges = create_edge_list(e);
	Edge *mst;
	int i, j, frm, to;
	float weight;
	for(i=0;i<e;i++){
		scanf("%d %d %f", &frm, &to, &weight);
		edges[i].from = frm;
		edges[i].to = to;
		edges[i].weight = weight;
	}
	convert_to_min_heap(edges, e);
	mst = kruskal_mst(edges, v, e);
	for(i=0;i<v-1;i++){
		printf("%d - %d - %f\n", mst[i].from, mst[i].to, mst[i].weight);
	}
	free(edges);
	free(mst);
	return 0;
}