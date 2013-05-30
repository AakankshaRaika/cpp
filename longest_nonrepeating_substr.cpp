#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 101
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int visited[256];

void _initialize()
{
    FOR(i,256)
    {
        visited[i] = -1;
    }
}

int non_r_substr(string s)
{
    int cur,mx,prev;
    visited[s[0]]=0;
    cur = mx = 1;
    for(int i=1;i<s.size();i++)
    {
        prev = visited[s[i]];
        if(prev == -1 || (i-cur)>prev)
            cur++;
        else
        {
            if(cur>mx)
            {
                mx = cur;
            }
            cur = i-prev;
        }
        visited[s[i]]=i;
    }
    if(cur>mx)
        mx = cur;
    return mx;
}

int main()
{
    _initialize();
    string s;
    cin>>s;
    cout<<non_r_substr(s)<<"\n";
}
