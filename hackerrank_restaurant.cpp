#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<set>
#include<map>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;
int GCD(int a,int b)
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

void _initialize()
{
}

int main()
{
    _initialize();
    int t,l,b,res;
    S(t);
    while(t--){
        res = 1;
        S(l),S(b);
        res = GCD(l,b);
        res = (l*b)/(res*res);
        printf("%d\n",res);
    }
}
