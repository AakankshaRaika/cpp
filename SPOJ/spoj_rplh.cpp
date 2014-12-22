#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<cmath>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{
}

int main()
{
    float pi = 2*acos(0.0);
    const float g = 9.806;
    int t,ta,sp;
    S(t);
    float d,ang;
    for(int i=1;i<=t;i++){
        S(ta),S(sp);
        d = (ta*g)/(sp*sp);
        if(d>1){
            printf("Scenario #%d: -1\n",i);
            continue;
        }
        ang = asin(d)/2;
        ang = 180*ang/pi;
        printf("Scenario #%d: %.2f\n",i,ang);
    }
}
