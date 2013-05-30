/*
TEST CASE

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 3 7
2 5 4
2 8 2
8 6 6
3 5 14
3 4 9
6 5 2
5 4 10

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/



#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

struct Edge
{
    int src,dst,wt;
};

struct subset
{
    int parent,rank;
};

Edge mst[20];

void _initialize()
{
}

int Find(subset s[],int i)
{
    if(s[i].parent!=i)
        s[i].parent = Find(s,s[i].parent);
    return s[i].parent;
}

void Union(subset s[],int x,int y)
{
    int xroot = Find(s,x);
    int yroot = Find(s,y);

    if(s[xroot].rank<s[yroot].rank)
        s[xroot].parent = yroot;
    else if(s[xroot].rank>s[yroot].rank)
        s[yroot].parent = xroot;
    else
    {
        s[yroot].parent = xroot;
        s[xroot].rank++;
    }
}

void bubblesort(Edge e[],int ed)
{
    Edge tmp;
    FOR(i,ed)
    {
        for(int j=0;j<ed-i-1;j++)
        {
            if(e[j].wt>e[j+1].wt)
            {
                tmp = e[j];
                e[j] = e[j+1];
                e[j+1] = tmp;
            }
        }
    }
}

void kruskalMST(Edge e[],subset s[],int v,int ed)
{
    int mi = 0;
    for(int i=0;i<ed;i++)
    {
        int x = Find(s,e[i].src);
        int y = Find(s,e[i].dst);
        if(x!=y)
        {
            mst[mi++] = e[i];
            Union(s,x,y);
        }
    }
}

int main()
{
    _initialize();
    Edge* e;
    subset* s;
    int v,ed;
    cin>>v>>ed;
    e = new Edge[ed];
    s = new subset[v];
    FOR(i,ed)
    {
        cin>>e[i].src>>e[i].dst>>e[i].wt;
    }
    bubblesort(e,ed);
    FOR(i,v)
    {
        s[i].parent = i;
        s[i].rank = 0;
    }
    kruskalMST(e,s,v,ed);
    cout<<endl;
    FOR(i,v-1)
    {
        cout<<mst[i].src<<" "<<mst[i].dst<<" "<<mst[i].wt<<"\n";
    }
    cout<<endl;
    FOR(i,v)
    {
        cout<<s[i].parent<<" "<<s[i].rank<<endl;
    }
}
