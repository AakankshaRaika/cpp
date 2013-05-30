#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 15
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) scanf("%d",&n)

using namespace std;

long dp[MAX];
/* WRONG */
void MBEEWALK()
{
    dp[1] = 0;
    for(int i=2;i<=14;i++)
    {
        if(i%2==0)
            dp[i] = pow(i-1,2)*6;
        else
            dp[i] = pow(i,2)*6;
    }
}

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n;
        S(n);
        MBEEWALK();
        cout<<dp[n]<<endl;
    }
}
