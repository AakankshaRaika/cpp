#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 101
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int dp[MAX][MAX];

void _initialize()
{
}

void min_cost(int cost[MAX][MAX],int m,int n)
{
    dp[0][0] = cost[0][0];

    for(int i=1;i<m;i++)
    {
        dp[i][0] = cost[i][0]+dp[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        dp[0][i] = cost[0][i]+dp[0][i-1];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = cost[i][j] + Min(Min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
}

int main()
{
    int m,n,cost[MAX][MAX];
    S(m),S(n);
    FOR(i,m)
    {
        FOR(j,n)
        {
            S(cost[i][j]);
        }
    }
    min_cost(cost,m,n);
    cout<<dp[m-1][n-1]<<"\n";
}
