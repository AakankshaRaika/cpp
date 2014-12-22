#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 101
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)

using namespace std;
int a[MAX][MAX],dp[MAX][MAX];

int problem(int r,int c)
{
    //for(int i=0;i<c;i++)
    //    dp[r-1][i]=a[r-1][i];
    for(int i=r-2;i>=0;i--)
        for(int j=c-1;j>=0;j--)
        {
            if(j==c-1)
            {
                a[i][j] = a[i][j] + Max(a[i+1][j],a[i+1][j-1]);
            }
            else if(j==0)
            {
                a[i][j] = a[i][j] + Max(dp[i+1][j],a[i+1][j+1]);
            }
            else
            {
                a[i][j] = a[i][j] + Max(Max(a[i+1][j-1],a[i+1][j]),a[i+1][j+1]);
            }
        }
    int m = a[0][0];
    for(int i=1;i<c;i++)
        if(a[0][i]>m)
            m = a[0][i];
    return m;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        cout<<problem(r,c)<<"\n";
    }
}
