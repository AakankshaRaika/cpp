#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<set>
#include<map>
#include<cstring>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int dp[13][100];
int n,k;

int Count(int n,int k){
    if(n==0)
        return 0;
    if(k==0)
        return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    int val = 0;
    for(int i=0;i<n && k-i>=0;i++)
        val += Count(n-1,k-i);
    dp[n][k] = val;
    return dp[n][k];
}

int main()
{
    int t;
    S(t);
    while(t--){
        S(n),S(k);
        memset(dp,-1,sizeof dp);
        int val = Count(n,k);
        printf("%d\n",val);
    }
}
