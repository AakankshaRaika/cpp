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
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{
}

int minKey(int dist[],bool sptset[]){
    int mn = INT_MAX,ind;
    FOR(i,MAX)
        if(!sptset[i] && dist[i]<=mn)
            mn = dist[i],ind = i;
    return ind;
}

void dijkstra(int graph[MAX][MAX],int src){
    int dist[MAX],parent[MAX];
    bool sptset[MAX];
    FOR(i,MAX){
        dist[i] = INT_MAX;
        parent[i] = -1;
        sptset[i] = false;
    }
    parent[src] = -1;
    dist[src] = 0;
    for(int c = 0;c<MAX-1;c++){
        int u = minKey(dist,sptset);
        sptset[u] = true;
        for(int j=0;j<MAX;j++)
            if(!sptset[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
                dist[j] = dist[u]+graph[u][j],parent[j]=u;
    }
    FOR(i,MAX){
        cout<<i<<" - "<<dist[i]<<"\n";
    }
    REP(i,1,MAX){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
}

int main()
{
    _initialize();
    int graph[MAX][MAX] = {{0,4,0,0,0,0,0,8,0},
                           {4,0,8,0,0,0,0,11,0},
                           {0,8,0,7,0,4,0,0,2},
                           {0,0,7,0,9,14,0,0,0},
                           {0,0,0,9,0,10,0,0,0},
                           {0,0,4,0,10,0,2,0,0},
                           {0,0,0,14,0,2,0,1,6},
                           {8,11,0,0,0,0,1,0,7},
                           {0,0,2,0,0,0,6,7,0}
                        };
    dijkstra(graph,0);
}
