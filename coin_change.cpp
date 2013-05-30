#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 101
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{

}

int coin_change(int s[],int m,int n)
{
    int dp[n+1][m],x,y;
    FOR(i,m)
        dp[0][i]=1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i-s[j]>=0)
                x = dp[i-s[j]][j];
            else
                x=0;
            if(j>=1)
                y = dp[i][j-1];
            else
                y = 0;
            dp[i][j] = x+y;
        }
    }
    return dp[n][m-1];
}

int coin_change2(int s[],int m,int n)
{
    int dp[n+1];
    for(int j=0;j<=n;j++)
        dp[j]=0;
    dp[0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=s[i];j<=n;j++)
        {
            dp[j]+=dp[j-s[i]];
        }
    }
    return dp[n];
}

int main()
{
    _initialize();
    int s[20],n,m;
    cin>>m>>n;
    FOR(i,m)
    {
        cin>>s[i];
    }
    cout<<coin_change2(s,m,n)<<endl;
}
