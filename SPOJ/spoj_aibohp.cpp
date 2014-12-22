#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 6102
#define min(a,b) ((a<b)?a:b)

int min_pal(string s,int len)
{
    int dp[len][len],l,h,gap;
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            dp[i][j]=0;
    for(gap=1;gap<len;gap++)
    {
        for(l=0,h=gap;h<len;h++,l++)
        {
            dp[l][h] = (s[l]==s[h])?dp[l+1][h-1]:(min(dp[l][h-1],dp[l+1][h])+1);
        }
    }
    return dp[0][len-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        cout<<min_pal(x,x.size())<<endl;
    }
}
