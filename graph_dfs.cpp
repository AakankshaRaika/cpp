#include<iostream>
#include<list>
#include<cstdio>
#include<algorithm>

#define MAX 15
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

list<int> adj[MAX];
bool visited[MAX];
int v,e;

void addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void dfs_recurs(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(!visited[*it])
            dfs_recurs(*it);
    }
}

void dfs(int v)
{
    for(int i=0;i<v;i++)
        visited[i]=false;
    dfs_recurs(v);
}

int main()
{
    int ve,we;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        cin>>ve>>we;
        addEdge(ve,we);
    }
    dfs(3);
}
