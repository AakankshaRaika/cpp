#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

#define MAX 10001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int g[MAX][MAX]={0};
bool ind[MAX] = {false};
bool track[MAX] = {false};
int indeg[MAX]={0};
queue<int> q;

void _initialize()
{
}

int main()
{
    _initialize();
    int flag = 0;
    char c,d;
    while(cin>>c)
    {
        track[c-'a']=true;
        flag = 0;
        while(cin>>d)
        {
            if(d=='0')
            {
                if(flag==0)
                    ind[c-'a']=true;
                break;
            }
            flag++;
            track[d-'a']=true;
            g[d-'a'][c-'a']=1;
        }
    }
    for(int i=0;i<MAX && track[i];i++)
    {
        for(int j=0;j<MAX && track[j];j++)
        {
            if(g[i][j])
                indeg[j]++;
        }
    }
    FOR(i,MAX)
    {
        if(track[i] && !indeg[i] && ind[i])
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;
        for(int j=0;j<MAX && track[j];j++)
        {
            if(g[cur][j])
            {
                indeg[j]--;
                if(indeg[j]==0)
                    q.push(j);
            }
        }
    }
    //FOR(i,26)
    //    cout<<indeg[i]<<" "<<track[i]<<" "<<ind[i]<<"\n";
    cout<<cnt;
}
