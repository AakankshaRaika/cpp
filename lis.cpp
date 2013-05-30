#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 15
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)

using namespace std;

int dp[MAX];

/*
NOT USEFUL
void print_lis(int a[],int n)
{
    if(n<0)
        return;
    int m = dp[0];
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>m)
            m = dp[i];
    }
    if(dp[n]==m)
    {
        print_lis(a,n-1);
        cout<<a[n]<<" ";
    }
}
*/

void lis(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && dp[i]<dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
    }
}

int main()
{
    int a[] = {10,22,9,33,21,50,41,60,59};
    int n = 9;
    lis(a,n);
    int m = dp[0];
    //cout<<m<<" ";
    for(int i=1;i<n;i++)
    {
        //cout<<dp[i]<<" ";
        if(dp[i]>m)
            m=dp[i];
    }
    cout<<m<<"\n";
    //print_lis(a,n-1);
}
