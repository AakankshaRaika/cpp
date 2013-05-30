#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int mx[MAX][MAX],mn[MAX][MAX];

void _initialize()
{
}

void LISA(int num[MAX],string op,int n)
{
    for(int i=0;i<n;i++)
    {
        mx[i][i]=mn[i][i]=num[i];
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j = i+l-1;
            mx[i][j] = 0;
            mn[i][j] = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q1,q2;
                char o = op[k];
                if(o=='+')
                {
                    q1 = mx[i][k]+mx[k+1][j];
                    q2 = mn[i][k]+mn[k+1][j];
                }
                else
                {
                    q1 = mx[i][k]*mx[k+1][j];
                    q2 = mn[i][k]*mn[k+1][j];
                }
                if(q1>mx[i][j])
                    mx[i][j]=q1;
                if(q2<mn[i][j])
                    mn[i][j]=q2;
            }
        }
    }
}

int main()
{
    _initialize();
    int t,j,c;
    S(t);
    string s,op;
    int num[MAX];
    while(t--)
    {
        cin>>s;
        j=0;
        c=0;
        op="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0'>=0 && s[i]-'0'<=9)
                num[j++]=s[i]-'0';
            else
                op+=s[i];
        }
        LISA(num,op,j);
        cout<<mx[0][j-1]<<" "<<mn[0][j-1]<<"\n";
    }
}
