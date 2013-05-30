#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void GCD(int a,int b)
{
}

int main()
{
    int n;
    S(n);
    long long a[n];
    long long d[n-1],gcd;
    FOR(i,n)
        S(a[i]);
    //sort(a,a+n);
    REP(i,1,n)
        d[i-1] = a[i]-a[i-1];
    //FOR()
    FOR(i,n-1)
    cout<<d[i]<<" ";
}
