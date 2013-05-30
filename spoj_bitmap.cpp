#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX 183
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

struct pos
{
    int i,j;
    pos(int x,int y)
    {
        i=x,j=y;
    }
};

using namespace std;
char maze[MAX][MAX];
int v[MAX][MAX],dist[MAX][MAX];

void _initialize(int m,int n)
{
    FOR(i,m)
        FOR(j,n)
        {
            v[i][j]=0;
            if(maze[i][j]=='0')
                dist[i][j]=1;
            else
                dist[i][j]=0;
        }
}

bool valid(int i,int j,int m,int n)
{
    return (i>=0 && i<m && j>=0 && j<n);
}

int abs(int x)
{
    if(x<0)
        return -1*x;
    return x;
}

void bfs(int x,int y,int m,int n)
{
    cout<<"new\n";
    pos start(x,y),cur(0,0),tmp(0,0);
    queue<pos> q;
    q.push(start);
    v[x][y] = 1;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cout<<cur.i<<" "<<cur.j<<"\n";
        if(valid(cur.i-1,cur.j,m,n) && !v[cur.i-1][cur.j] && maze[cur.i-1][cur.j]=='0')
        {
            v[cur.i-1][cur.j]=1;
            tmp.i = cur.i-1,tmp.j = cur.j;
            dist[cur.i][cur.j] += 1;//abs(cur.i-tmp.i)+abs(cur.j-tmp.j);
            if(maze[tmp.i][tmp.j]=='1')
            {
                dist[cur.i][cur.j] += 1;
                //cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i+1,cur.j,m,n) && !v[cur.i+1][cur.j] && maze[cur.i+1][cur.j]=='0')
        {
            v[cur.i+1][cur.j]=1;
            tmp.i = cur.i+1,tmp.j = cur.j;
            dist[cur.i][cur.j] += 1;//abs(cur.i-tmp.i)+abs(cur.j-tmp.j);
            if(maze[tmp.i][tmp.j]=='1')
            {
                dist[cur.i][cur.j] += 1;
                //cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i,cur.j-1,m,n) && !v[cur.i][cur.j-1] && maze[cur.i][cur.j-1]=='0')
        {
            v[cur.i][cur.j-1]=1;
            tmp.i = cur.i,tmp.j = cur.j-1;
            dist[cur.i][cur.j] += 1;//abs(cur.i-tmp.i)+abs(cur.j-tmp.j);
            if(maze[tmp.i][tmp.j]=='1')
            {
                dist[cur.i][cur.j] += 1;
                //cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i,cur.j+1,m,n) && !v[cur.i][cur.j+1] && maze[cur.i][cur.j+1]=='0')
        {
            v[cur.i][cur.j+1]=1;
            tmp.i = cur.i,tmp.j = cur.j+1;
            dist[cur.i][cur.j] += 1;//abs(cur.i-tmp.i)+abs(cur.j-tmp.j);
            if(maze[tmp.i][tmp.j]=='1')
            {
                dist[cur.i][cur.j] += 1;
                //cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
    }
}

int main()
{
    int t,n,m;
    S(t);
    while(t--)
    {
        S(n),S(m);
        //int flag=0;
        FOR(i,n)
        {
            cin>>maze[i];
        }
        _initialize(n,m);
        FOR(i,n)
        {
            FOR(j,m)
            {
                if(maze[i][j]=='0' && !v[i][j])
                {
                    //dist[i][j] = 1;
                    bfs(i,j,n,m);
                }
            }
        }
        FOR(i,n)
        {
            FOR(j,m)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
