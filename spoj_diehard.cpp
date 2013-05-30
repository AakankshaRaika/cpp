#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

//int dp[1001][1001][3];

void _initialize()
{
}

int max_time(int h,int a)
{
    //_initialize();
    int ans = 0;
    while(h>0 && a>0)
    {
        h=h+3;
        a=a+2;
        ans++;
        if(h-5>0 && a-10>0)
        {
            h=h-5;
            a=a-10;
        }
        else
        {
            h=h-20;
            a=a+5;
        }
        if(h>0 && a>0)
            ans+=1;
    }
    return ans;
}

int main()
{
    _initialize();
    int t,h,a;
    S(t);
    while(t--)
    {
        S(h);
        S(a);
        cout<<max_time(h,a)<<"\n";
    }
}
