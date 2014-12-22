#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<cmath>

#define MAX 183
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

struct pos
{
    int i,j;
    pos(int x,int y)
    {
        i=x,j=y;
    }
    pos()
    {
    }
};

using namespace std;
char maze[MAX][MAX];
int v[MAX][MAX],dist[MAX][MAX];
int n,m;

void _initialize()
{
    FOR(i,n)
        FOR(j,m)
        {
            if(maze[i][j]=='0')
                dist[i][j] = INT_MAX;
            else
                dist[i][j]=0;
        }
}

bool valid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(pos s)
{
    pos cur(0,0),tmp(0,0);
    queue<pos> q;
    int d;
    q.push(s);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cout<<cur.i<<" "<<cur.j<<"\n";
        for(int i=cur.i-1;i<=cur.i+1;i++)
        {
            for(int j=cur.j-1;j<=cur.j+1;j++)
                if(valid(i,j))
                {
                    cout<<"b "<<i<<" "<<j<<"\n";
                    d = abs(i-s.i)+abs(j-s.j);
                    if(dist[i][j]>d)
                    {
                        tmp.i=i,tmp.j=j;
                        dist[i][j]=d;
                        q.push(tmp);
                    }
                }
        }
    }
}

int main()
{
    int t;
    pos p;
    S(t);
    while(t--)
    {
        S(n),S(m);
        FOR(i,n)
        {
            cin>>maze[i];
        }
        _initialize();
        FOR(i,n)
        {
            FOR(j,m)
            {
                if(maze[i][j]=='1')
                {
                    p.i=i,p.j=j;
                    bfs(p);
                }
            }
        }
        FOR(i,n)
        {
            cout<<dist[i][0];
            for(int j=1;j<m;j++)
            {
                cout<<" "<<dist[i][j];
            }
            cout<<endl;
        }
    }
}
