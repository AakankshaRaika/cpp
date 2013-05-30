#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int c[26];

void _initialize()
{
    FOR(i,26) c[i]=0;
}

string filter(string s)
{
    string f="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z')
            f+=s[i];
        else if(s[i]>='A' && s[i]<='Z')
            f+=(s[i]+32);
    }
    for(int i=0;i<f.size();i++)
        c[f[i]-'a']++;
    return f;
}

int odds()
{
    int od=0;
    FOR(i,26)
    {
        if(c[i]%2!=0)
            od++;
    }
    return od;
}

int even()
{
    int ev=0;
    FOR(i,26)
    {
        if(c[i]%2==0 && c[i]!=0)
            ev++;
    }
    return ev;
}

int main()
{
    _initialize();
    string s,tmp;
    while(getline(cin,s))
    {
        _initialize();
        tmp = filter(s);
        if(tmp.size()==0)
        {
            cout<<"1\n";
            continue;
        }
        int o = odds();
        if(o>1)
        {
            cout<<"0\n";
            continue;
        }
        else if(o==1)
        {
            int ev = even();
            cout<<ev<<"\n";
        }
        else
        {
        }
    }
}
