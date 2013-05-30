#include<iostream>
#include<cstdio>
#include<algorithm>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{

}

bool is_common(string x,string y)
{
    int c = 0;
    int v[y.size()];
    fill(&v[0],&v[0]+y.size(),0);
    int j=0;
    while(j<y.size() && c<x.size())
    {
        if(y[j]==x[c++])
        {
            v[j]=1;
            j++;
        }
    }
    FOR(i,y.size())
    {
        if(v[i]==0)
            return false;
    }
    return true;
}

int main()
{
    _initialize();
    int t;
    string x,y;
    S(t);
    while(t--)
    {
        cin>>x>>y;
        if(x.size()>y.size())
        {
            if(is_common(x,y))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            if(is_common(y,x))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}
