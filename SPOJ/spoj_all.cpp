#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize(int indeg[],int n)
{
    for(int i=0;i<n;i++)
        indeg[i]=0;
}

int main()
{
    int n1,n2,d;
    while(1)
    {
        S(n1),S(n2),S(d);
        if(n1==0 && n2==0 && d==0)
            break;
        if(d==0)
        {
            cout<<"3\n";
            continue;
        }
        int n = n1+n2+1;
        vector<int> g[n];
        int indeg[n];
        _initialize(indeg,n);
        int x,y,fl=0;
        FOR(i,d)
        {
            S(x),S(y);
            if((x<=n1 && y>n1)||(x>n1 && y<=n1))
            {
                g[y].push_back(x);
                indeg[x]++;
                fl=1;
            }
        }
        if(!fl)
        {
            cout<<"3\n";
            continue;
        }
        for(int i=1;i<n;i++)
        {
            //cout<<indeg[i]<<" ";
            cout<<i<<" ";
            if(g[i].size()>0)
            {
                for(vector<int>::iterator it = g[i].begin();it!=g[i].end();it++)
                {
                    cout<<*it<<" ";
                }
            }
            cout<<endl;
        }
        for(int i=1;i<n;i++)
        {
            cout<<indeg[i]<<" ";
        }
        cout<<"\n";
    }
}
