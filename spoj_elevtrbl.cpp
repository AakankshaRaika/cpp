#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX 1000001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;
int g[MAX][2],dist[MAX],v[MAX];

void _initialize()
{
}

int main()
{
    _initialize();
    queue<int> q;
    int f,s,gr,u,d;
    cin>>f>>s>>gr>>u>>d;
    if(s==gr)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=f;i++)
    {
        v[i]=0;
        dist[i]=0;
        if(i==1)
        {
            g[i][0] = i+u;
            g[i][1] = 0;
        }
        else if(i==f)
        {
            g[i][0] = 0;
            g[i][1] = i-d;
        }
        else
        {
            if(i>d)
                g[i][1] = i-d;
            else
                g[i][1] = 0;
            if(i+u>f)
                g[i][0] = 0;
            else
                g[i][0] = i+u;
        }
    }
    int cur;
    q.push(s);
    dist[s] = 0;
    v[s] = 1;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for(int i=0;i<=1;i++)
        {
            if(!v[g[cur][i]] && g[cur][i])
            {
                v[g[cur][i]] = 1;
                q.push(g[cur][i]);
                dist[g[cur][i]]= 1 + dist[cur];
                if(g[cur][i]==gr)
                {
                    cout<<dist[gr];
                    return 0;
                }
            }
        }
    }
    cout<<"use the stairs";
}
