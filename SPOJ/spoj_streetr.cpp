#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 100001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

long long a[MAX];
long long GCD(int a,int b)
{
    if(a==b)
        return a;
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(~a&1){
        if(b&1)
            return GCD(a>>1,b);
        else
            return GCD(a>>1,b>>1)<<1;
    }
    if(~b&1)
        return GCD(a,b>>1);
    if(a>b)
        return GCD((a-b)>>1,b);
    return GCD((b-a)>>1,a);
}

int main()
{
    int n,c;
    S(n);
    long long gcd;
    FOR(i,n)
        S(a[i]);
    sort(a,a+n);
    gcd = a[1]-a[0];
    for(int i=1;i<n;i++){
        gcd = GCD(gcd,a[i]-a[i-1]);
    }
    c = 0;
    for(int i=1;i<n;i++){
        c = c + ((a[i]-a[i-1])/gcd)-1;
    }
    cout<<c;
}
