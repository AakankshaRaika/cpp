#include<iostream>
#include<cstdio>
#include<algorithm>

#define MAX 2001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int dp[MAX][MAX];

void _initialize(int n,int m)
{
}

int edist(string x,string y)
{
    int l,t,c;
    FOR(i,x.size()+1)
        dp[i][0] = i;
    FOR(i,y.size()+1)
        dp[0][i]=i;
    for(int i=1;i<x.size()+1;i++)
    {
        for(int j=1;j<y.size()+1;j++)
        {
            l = dp[i][j-1]+1;
            t = dp[i-1][j]+1;
            c = dp[i-1][j-1];
            if(x[i-1]!=y[j-1])
                c+=1;
            dp[i][j] = Min(l,Min(t,c));
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    return dp[x.size()][y.size()];
}

int main()
{
    //_initialize();
    int t;
    string x,y;
    S(t);
    while(t--)
    {
        cin>>x>>y;
        cout<<edist(x,y)<<endl;
    }
}
