#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 21
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)

using namespace std;

int dp[MAX][MAX];
int edit_cost,del_cost,replace_cost;

void _initialize()
{
    edit_cost=del_cost=replace_cost=1;
    /*FOR(i,MAX)
    {
        FOR(j,MAX)
            dp[i][j]=(-1);
    }*/
}

void edit_distance(string x,string y)
{
    int l,t,c;
    FOR(i,x.size()+1)
        dp[i][0] = i;
    FOR(i,y.size()+1)
        dp[0][i]=i;
    for(int i=1;i<x.size()+1;i++)
    {
        for(int j=1;j<y.size()+1;j++)
        {
            l = dp[i][j-1]+edit_cost;
            t = dp[i-1][j]+del_cost;
            c = dp[i-1][j-1];
            if(x[i-1]!=y[j-1])
                c+=replace_cost;
            dp[i][j] = Min(l,Min(t,c));
        }
    }
}

int main()
{
    string x,y;
    cin>>x>>y;
    _initialize();
    edit_distance(x,y);
    cout<<dp[x.size()][y.size()]<<"\n";
    /*FOR(i,x.size()+1)
    {
        FOR(j,y.size()+1)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    */
}
