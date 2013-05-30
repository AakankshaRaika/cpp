#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))
//#define SS {(int n;scanf("%d",&n);n)}

using namespace std;
int n,m;
int ht[101][101];

void _initialize()
{
}

void water()
{

}

int main()
{
    _initialize();
    int t;
    S(t);
    while(t--)
    {
        S(n),S(m);
        FOR(i,n)
            FOR(j,m)
                S(ht[i][j]);
        water();
    }
}
