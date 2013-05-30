#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<set>

#define MAX 10000
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

map<string,int> lib;
set<int> g[MAX];
bool ind[MAX]={false};
int indeg[MAX]={0};

void _initialize()
{

}

int main()
{
    _initialize();
    int flag,val=0;
    string c,d;
    while(cin>>c)
    {
        flag = 0;
        if(lib.find(c)==lib.end())
            lib[c]=val++;
        //cout<<lib[c]<<" ";
        while(cin>>d)
        {
            if(d=="0")
            {
                if(flag==0)
                    ind[lib[c]]=true;
                break;
            }
            flag++;
            if(lib.find(d)==lib.end())
            {
                lib[d]=val++;
            }
            g[lib[d]].insert(lib[c]);
        }
    }
    FOR(i,val)
    {
        //cout<<i<<" ";
        for(set<int>::iterator it=g[i].begin();it!=g[i].end();it++)
        {
            //cout<<*it<<" ";
            indeg[*it]++;
        }
        //cout<<"\n";
    }
    queue<int> q;
    FOR(i,val)
    {
        if(!indeg[i] && ind[i])
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;
        for(set<int>::iterator it = g[cur].begin();it!=g[cur].end();it++)
        {
            indeg[*it]--;
            if(indeg[*it]==0)
                q.push(*it);
        }
    }
    cout<<cnt;
}
