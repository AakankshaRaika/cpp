#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 9
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

struct key
{
    int key,val;
};

struct node
{
    int dest,wt;
};

class primHeap
{
private:
    int *pos;
    int size,current;
    key* heap;
    void heapify(int);
    void swapKey(key&,key&);
public:
    bool empty();
    primHeap(int s);
    key top(void);
    key pop(void);
    void push(key);
    void update(key);
    bool isPresent(int v);
    int weight(int v);
    void updateWieght(int v);
    void print();
};

primHeap::primHeap(int s)
{
    this->size = s;
    this->current = s;
    this->heap = new key[s];
    this->pos = new int[s];
    this->pos[0] = 0;
    this->heap[0].key = 0;
    this->heap[0].val = 0;
    for(int i=1;i<this->size;i++)
    {
        this->pos[i] = i;
        this->heap[i].key = i;
        this->heap[i].val = INT_MAX;
    }
}

bool primHeap::empty()
{
    return this->current==0;
}

key primHeap::top()
{
    return heap[0];
}

void primHeap::swapKey(key &k1,key &k2)
{
    key t;
    t = k1;
    k1 = k2;
    k2 = t;
}

key primHeap::pop()
{
    key root;
    root.key=-1;
    root.val=-1;
    if(this->current <= 0)
        return root;
    root = this->heap[0];
    this->heap[0] = this->heap[this->current-1];
    this->pos[root.key] = this->current-1;
    this->pos[this->heap[0].key] = 0;
    this->current--;
    heapify(0);
    return root;
}

void primHeap::push(key k)
{
    if(this->current >= this->size)
        return;
    heap[this->current] = k;
    this->current++;
}

void primHeap::heapify(int i)
{
    int left,right,smallest=i;
    left  = 2*i+1;
    right = 2*i+2;
    if(left<this->current && this->heap[left].val<heap[i].val)
        smallest = left;
    if(right<this->current && this->heap[right].val<heap[smallest].val)
        smallest = right;
    if(smallest!=i)
    {
        this->pos[this->heap[smallest].key] = i;
        this->pos[this->heap[i].key] = smallest;
        swapKey(this->heap[smallest],this->heap[i]);
        heapify(smallest);
    }
}

void primHeap::update(key k)
{
    int i = this->pos[k.key];
    this->heap[i].val = k.val;
    while(i && this->heap[i].val<this->heap[(i-1)/2].val)
    {
        this->pos[this->heap[i].key] = (i-1)/2;
        this->pos[this->heap[(i-1)/2].key] = i;
        swapKey(this->heap[i],this->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void primHeap::print()
{
    for(int i=0;i<this->current;i++)
        cout<<this->heap[i].key<<" "<<this->heap[i].val<<"\n";
    for(int i=0;i<this->size;i++)
        cout<<this->pos[i]<<" ";
    cout<<endl;
}

bool primHeap::isPresent(int v)
{
    if(this->pos[v]<this->current)
        return true;
    return false;
}

int primHeap::weight(int v)
{
    return this->heap[this->pos[v]].val;
}

vector<node> adj[MAX];
int v,e;
bool mstSet[MAX];
int parent[MAX];

void primMST()
{
    int parent[v];
    primHeap prim(v);
    while(!prim.empty())
    {
        key k = prim.pop();
        int u = k.key;
        for(vector<node>::iterator it = adj[u].begin();it!=adj[u].end();it++)
        {
            int V = it->dest;
            if(prim.isPresent(V) && it->wt<prim.weight(V))
            {
                key k1;
                k1.key = V;
                k1.val = it->wt;
                parent[V] = u;
                prim.update(k1);
            }
        }
    }
    for (int i = 1; i < v; ++i)
        printf("\n%d - %d", parent[i], i);
}

void dijkstra(int s){
    int parent[v];
    primHeap prim(v);
    while(!prim.empty()){
        key k = prim.pop();
        int u = k.key;
        for(vector<node>::iterator it = adj[u].begin();it!=adj[u].end();it++){
            int V = it->dest;
            if(prim.isPresent(V) && (it->wt+prim.weight(u))<prim.weight(V)){
                key k1;
                k1.key = V;
                k1.val = it->wt+prim.weight(u);
                parent[V] = u;
                prim.update(k1);
            }
        }
    }
    for (int i = 1; i < v; ++i)
        printf("\n%d - %d", parent[i], i);
    FOR(i,v)
    cout<<prim.weight(i)<<" ";
}

void _initialize()
{
}

int main()
{
    _initialize();
    cin>>v>>e;
    int s,d,w;
    node tmp;
    FOR(i,e)
    {
        cin>>s>>d>>w;
        tmp.dest = d;
        tmp.wt = w;
        adj[s].push_back(tmp);
        tmp.dest = s;
        adj[d].push_back(tmp);
    }
    primMST();
}
