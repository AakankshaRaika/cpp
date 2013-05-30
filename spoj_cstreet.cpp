#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 1001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int adj[MAX][MAX];
int p,n,m;
long long cost;
int key[MAX],parent[MAX];
bool mstSet[MAX];

void _initialize()
{
    FOR(i,n) FOR(j,n) adj[i][j] = 0;
}

int minKey()
{
    int mn = INT_MAX,minkey;
    for(int i=0;i<n;i++)
    {
        if(!mstSet[i] && key[i]<mn)
            mn = key[i],minkey = i;
    }
    return minkey;
}

void primMST()
{
    cost = 0;
    for(int i=1;i<n;i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<n-1;i++)
    {
        int u = minKey();
        mstSet[u] = true;
        FOR(v,n)
        {
            if(adj[u][v] && !mstSet[v] && adj[u][v]<key[v])
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        cost = cost + adj[parent[i]][i];
    }
    cost*=p;
}

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int a,b,c;
        S(p),S(n),S(m);
        _initialize();
        FOR(i,m)
        {
            S(a),S(b),S(c);
            adj[a-1][b-1] = adj[b-1][a-1] = c;
        }
        primMST();
        cout<<cost<<"\n";
    }
}
