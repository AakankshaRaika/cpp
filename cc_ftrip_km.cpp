#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
double arr[1002][1002]={0};
void init()
{
     int i,j;
     for(i=0;i<=1000;i++)
     {
                         arr[i][0]=1.000000;
     }
     for(i=1;i<=1000;i++)
     {
                         for(j=1;j<=i;j++)
                         {
                                          arr[i][j]=(double)arr[i-1][j-1]+(double)arr[i-1][j];
                         }
     }
}

int main()
{
    int t,s,n,m,k,i;
    init();
    //help();
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d %d %d %d",&s,&n,&m,&k);
              if(s==n || k==0)
              {
                      printf("1.000000\n");
                      continue;
              }
              if(n<=k)
              {
                      printf("0.000000\n");
                      continue;
              }
              double denum=arr[s-1][n-1];
              double num=0.000000;
              for(i=k;i<min(m,n);i++)
              {
                                 //if((i>m-1) || (s-m<n-i-1))continue;
                                 num+=arr[m-1][i]*arr[s-m][n-i-1];
              }
              num=num/denum;
              printf("%.6lf\n",num);
    }
}
