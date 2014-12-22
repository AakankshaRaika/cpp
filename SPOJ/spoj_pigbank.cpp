#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

unsigned int dp[10001];
//int INF = 1<<30;

void _initialize()
{
}

int min_den(int v[501],int w[501],int tot_weight,int n)
{
    dp[0] = 0;
    fill(&dp[1],&dp[1]+tot_weight+1,INT_MAX);
    for(int i=0; i<n; i++)
	{
		for(int j=0; j<=tot_weight-w[i]; j++)
        {
            if(dp[j]!=INT_MAX && dp[j+w[i]] > dp[j]+v[i])
			{
			    dp[j+w[i]] = dp[j] + v[i];
                //cout<<j<<" "<<j+w[i]<<" "<<dp[j+w[i]]<<". ";
			}
			cout<<j<<" "<<j+w[i]<<" "<<dp[j+w[i]]<<". ";
        }
        cout<<"\n\n";
    }
    if(dp[tot_weight]!=INT_MAX)
        return dp[tot_weight];
    return -1;
}

int main()
{
    _initialize();
    int t,ini,fin,n;
    int w[501],v[501];
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
        int val = min_den(v,w,fin-ini,n);
        if(val==-1)
            cout<<"This is impossible.\n";
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<val<<".\n";
    }
}
