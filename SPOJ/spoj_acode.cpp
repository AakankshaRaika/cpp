#include<iostream>
#define MAX(a,b) ((a>b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)

using namespace std;

long long int dp[5001];

bool two(char u,char l)
{
    int n;
    n = (u-'0')*10 + (l-'0');
    if(n>9 && n<27)
        return true;
    return false;
}

void ACODE(string s)
{
    dp[0]=1;
    if(s[1]-'0')
        dp[1]=1;
    else
        dp[1]=0;
    if(two(s[0],s[1]))
        dp[1]++;
    for(int i=2;i<s.size();i++)
    {
        if(s[i]-'0')
            dp[i] = dp[i-1];
        else
            dp[i] = 0;
        if(two(s[i-1],s[i]))
            dp[i]+=dp[i-2];
    }
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s.size()==1 && s[0]=='0')
            break;
        if(s.size()<2)
        {
            cout<<"1\n";
            continue;
        }
        ACODE(s);
        cout<<dp[s.size()-1]<<"\n";
    }
}
