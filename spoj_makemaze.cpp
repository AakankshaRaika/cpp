#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX 21
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
int v[MAX][MAX];

void _initialize(int m,int n)
{
    FOR(i,m)
        FOR(j,n)
        v[i][j]=0;
}

bool valid(int i,int j,int m,int n)
{
    if(i>=0 && i<m && j>=0 && j<n)
        return true;
    return false;
}

void bfs(int m,int n,pos f,pos l)
{
    _initialize(m,n);
    pos cur(0,0),tmp(0,0);
    queue<pos> q;
    q.push(f);
    v[f.i][f.j]=1;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(valid(cur.i-1,cur.j,m,n) && !v[cur.i-1][cur.j] && maze[cur.i-1][cur.j]=='.')
        {
            v[cur.i-1][cur.j]=1;
            tmp.i = cur.i-1,tmp.j = cur.j;
            if(tmp.i==l.i && tmp.j==l.j)
            {
                cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i+1,cur.j,m,n) && !v[cur.i+1][cur.j] && maze[cur.i+1][cur.j]=='.')
        {
            v[cur.i+1][cur.j]=1;
            tmp.i = cur.i+1,tmp.j = cur.j;
            if(tmp.i==l.i && tmp.j==l.j)
            {
                cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i,cur.j-1,m,n) && !v[cur.i][cur.j-1] && maze[cur.i][cur.j-1]=='.')
        {
            v[cur.i][cur.j-1]=1;
            tmp.i = cur.i,tmp.j = cur.j-1;
            if(tmp.i==l.i && tmp.j==l.j)
            {
                cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
        if(valid(cur.i,cur.j+1,m,n) && !v[cur.i][cur.j+1] && maze[cur.i][cur.j+1]=='.')
        {
            v[cur.i][cur.j+1]=1;
            tmp.i = cur.i,tmp.j = cur.j+1;
            if(tmp.i==l.i && tmp.j==l.j)
            {
                cout<<"valid\n";
                return;
            }
            q.push(tmp);
        }
    }
    cout<<"invalid\n";
}

int main()
{
    int t,m,n,c,first;
    pos f(0,0),l(0,0);
    S(t);
    while(t--)
    {
        c=first=0;
        S(m),S(n);
        FOR(i,m)
        {
            FOR(j,n)
            {
                cin>>maze[i][j];
                if((i==0 || j==0 || i==m-1 || j==n-1)&& maze[i][j]=='.')
                {
                    if(!first)
                    {
                        first++;
                        f.i=i,f.j=j;
                    }
                    else
                        l.i=i,l.j=j;
                    c++;
                }
            }
        }
        if(c!=2)
        {
            cout<<"invalid\n";
        }
        else
        {
            bfs(m,n,f,l);
        }
    }
}
