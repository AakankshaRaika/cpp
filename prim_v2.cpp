#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 5
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{
}

int minKey(int key[],bool mstSet[])
{
    int mn = INT_MAX,minkey;
    for(int i=0;i<MAX;i++)
    {
        if(!mstSet[i] && key[i]<mn)
            mn = key[i],minkey = i;
    }
    return minkey;
}

void primMST(int graph[MAX][MAX])
{
    bool mstSet[MAX];
    int key[MAX],parent[MAX];
    FOR(i,MAX)
    {
        mstSet[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;
    FOR(i,MAX-1)
    {
        int u = minKey(key,mstSet);
        mstSet[u] = true;
        FOR(v,MAX)
        {
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    //for(int i=0;i<MAX;i++)
    //    cout<<mstSet[i]<<" ";
    cout<<"\n";
    for(int i=1;i<MAX;i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<graph[i][parent[i]]<<"\n";
    }
}

int main()
{
    _initialize();
    int   graph[MAX][MAX]   =  {{ 0 ,   2 ,   0 ,   6 ,   0 } ,
                                { 2 ,   0 ,   3 ,   8 ,   5 } ,
                                { 0 ,   3 ,   0 ,   0 ,   7 } ,
                                { 6 ,   8 ,   0 ,   0 ,   9 } ,
                                { 0 ,   5 ,   7 ,   9 ,   0 }};
    primMST(graph);
}
