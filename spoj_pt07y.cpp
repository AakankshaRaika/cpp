#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int n,e;
vector<int> adj[10000];
vector<bool> v(10000,0);

void bfs(int start)
{
    int current;
    queue<int> q;
    v[start]=1;
    q.push(start);
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        for(int i=0;i<adj[current].size();i++)
        {
            if(!v[adj[current][i]])
            {
                q.push(adj[current][i]);
                v[adj[current][i]]=1;
            }
        }
    }

}

int main()
{
    int i,a,b,start;
    cin>>n>>e;
    if(e!=n-1)
    {
        cout<<"NO";
        return 0;
    }
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        if(i==0)
        start=a-1;
    }
    bfs(start);
    for(i=0;i<n;i++)
    {
        if(!v[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
