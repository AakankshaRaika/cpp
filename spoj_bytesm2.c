#include<stdio.h>
#define MAX 101
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)

int a[MAX][MAX],dp[MAX][MAX];

int problem(int r,int c)
{
    int i,j,m;
    for(i=0;i<c;i++)
        dp[r-1][i]=a[r-1][i];
    for(i=r-2;i>=0;i--)
        for(j=c-1;j>=0;j--)
        {
            if(j==c-1)
            {
                dp[i][j] = a[i][j] + Max(dp[i+1][j],a[i+1][j-1]);
            }
            else if(j==0)
            {
                dp[i][j] = a[i][j] + Max(dp[i+1][j],dp[i+1][j+1]);
            }
            else
            {
                dp[i][j] = a[i][j] + Max(Max(dp[i+1][j-1],a[i+1][j]),dp[i+1][j+1]);
            }
        }
    m = dp[0][0];
    for(i=1;i<c;i++)
        if(dp[0][i]>m)
            m = dp[0][i];
    return m;
}

int main()
{
    int t,i,j,r,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&a[i][j]);
        printf("%d\n",problem(r,c));
    }
}
