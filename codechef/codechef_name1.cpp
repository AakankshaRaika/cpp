#include<iostream>
#include<cstdio>
#include<algorithm>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int pc[26],cc[26];

void _initialize()
{
    FOR(i,26)
    {
        pc[i]=cc[i]=0;
    }
}

bool isValid(string p,string c)
{
    _initialize();
    FOR(i,p.size())
    {
        pc[p[i]-'a']+=1;
    }
    FOR(i,c.size())
    {
        cc[c[i]-'a']+=1;
    }
    for(int i=0;i<26;i++)
    {
        if(cc[i]>pc[i])
            return false;
    }
    return true;
}

int main()
{
    int t,n;
    string child,tm,par1,par2;
    S(t);
    while(t--)
    {
        child = "";
        cin>>par1>>par2;
        par1 += par2;
        S(n);
        FOR(i,n)
        {
            cin>>tm;
            child+=tm;
        }
        if(isValid(par1,child))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
