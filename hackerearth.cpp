#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))
#define sum 1000

using namespace std;

int p,m,M[1000],tmp,tot,t2,c;
bool dp[1000][1000];

bool subset_sum()
{
    for(int i=0;i<=m;i++)
        dp[0][i]=true;
    for(int i=1;i<=sum;i++)
        dp[i][0]=false;
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = dp[i][j-1];
            if(i>=M[j-1])
                dp[i][j] = dp[i][j] || dp[i-M[j-1]][j-1];
        }
    }
}

int main()
{
    int t;
    S(t);
    while(t--)
    {
        c=1;
        tot=0;
        S(p),S(m);
        FOR(i,m)
            S(M[i]);
        S(tmp);
        subset_sum();
        for(int i=1;i<p;i++)
        {
            S(t2);
            if(t2==tmp)
            {
                c++;
                continue;
            }
            tmp=t2;
            if(dp[c][m])
            {
                tot++;
                c=1;
            }
        }
        cout<<tot<<"\n";
    }
}
