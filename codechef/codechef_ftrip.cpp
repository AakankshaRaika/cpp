#include<iostream>
#include<cstdio>
#include<algorithm>

#define MAX 1002
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

double ncr[MAX][MAX]={0};

void _initialize()
{
    FOR(i,MAX)
    {
        ncr[i][0]=1.000000;
    }
    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}

int main()
{
    _initialize();
    int s,n,m,k,t;
    double nm;
    S(t);
    while(t--)
    {
        scanf("%d %d %d %d",&s,&n,&m,&k);
        if(s==n || k==0)
        {
            cout<<"1.000000\n";
            continue;
        }
        if(n<=k)
        {
            cout<<"0.000000\n";
            continue;
        }
        nm = 0.000000;
        for(int i=k;i<Min(m,n);i++)
        {
            nm += ncr[m-1][i]*ncr[s-m][n-i-1];
        }
        nm = nm/ncr[s-1][n-1];
        printf("%.6lf\n",nm);
    }
}
