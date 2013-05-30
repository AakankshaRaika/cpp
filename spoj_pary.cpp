#include<iostream>
#include<cstdio>
#include<cstring>
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

int dp[101][501],inc[101][501],cost[101],fun[101];

void _initialize(int n,int b)
{
    FOR(i,n)
        FOR(j,b)
        {
            inc[i][j]=dp[i][j]=0;
        }

}

int main(){
int b,n;
while(cin>>b>>n){
    if(b==0 && n==0)
        break;
    FOR(i,n)
    {
        S(cost[i]),S(fun[i]);
    }
    _initialize(n+1,b+1);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(cost[i-1]<=j)
            {
                dp[i][j] = Max(fun[i-1]+dp[i-1][j-cost[i-1]],dp[i-1][j]);
                if(dp[i][j]==fun[i-1]+dp[i-1][j-cost[i-1]])
                    inc[i][j]=1;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int j = b,wt = 0;;
    for(int i=n;i>=1;i--)
    {
        if(inc[i][j])
        {
            wt+=cost[i-1];//<<" ";
            j-=cost[i-1];
        }
    }
    cout<<wt<<" "<<dp[n][b]<<"\n";
}
}
