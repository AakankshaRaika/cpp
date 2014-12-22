#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;
int dp[10001];

void _initialize(int w)
{
    dp[0]=0;
    fill(&dp[1],&dp[1]+w+1,INT_MAX);
}

int pigbank(int w[501],int v[501],int tot,int n)
{
    _initialize(tot);
    FOR(i,n)
    {
        for(int j=0;j<=tot-w[i];j++)
        {
            if(dp[j]!=INT_MAX && dp[j+w[i]]>(dp[j]+v[i]))
                dp[j+w[i]]=dp[j]+v[i];
        }
    }
    return dp[tot];
}

int main()
{
    //_initialize();
    int t,w[501],v[501],ini,fin,n;
    S(t);
    while(t--)
    {
        S(ini);
        S(fin);
        S(n);
        FOR(i,n)
        {
            S(v[i]);
            S(w[i]);
        }
        int m = pigbank(w,v,fin-ini,n);
        if(m==INT_MAX)
            cout<<"This is impossible.\n";
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<m<<".\n";
    }
}
