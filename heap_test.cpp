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

void _initialize()
{
}

int main()
{
    _initialize();
    priority_queue<int> q;
    FOR(i,10)
    q.push(i);
    cout<<q.top();
    q.pop();
    q.push(12);
    cout<<endl<<q.top();
}
