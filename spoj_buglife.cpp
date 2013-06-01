#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>

#define max 2001

using namespace std;
vector<int> adj[max];
int n , e ;
char v[max] ;

void init()
{
    for(int i=0; i < max ; i++)
    {
        //for(int j=0;j<n;j++)
        //{
            adj[i].clear();
        //}
    }

    for(int i=0; i < 2001  ;i++)
    {
        v[i]='g';
    }

}

bool check(int start)
{
    int current;
    queue<int> q;
    v[start]='b';
    q.push(start);
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        for(int i=0;i<adj[current].size();i++)
        {
            if( v[adj[current][i]]=='g')
            {
                if(v[current]=='b')
                {
                    v[adj[current][i]]='w';
                }
                else if(v[current]=='w')
                {
                    v[adj[current][i]]='b';
                }
                q.push(adj[current][i]);
            }
            else if(v[adj[current][i]]!='g')
            {
                if(v[current]==v[adj[current][i]])
                {
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int i,j,t,c=1,a,b,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&e);
        init();
        for(i=0;i<e;i++)
        {
            scanf("%d %d",&a,&b);
            if(i==0)
            {
                s=a-1;
            }
            adj[a-1].push_back(b-1) ;
            adj[b-1].push_back(a-1);
        }
        printf("Scenario #%d:\n",c);
        c=c+1;
		for(int i = 0 ; i < n ; i++ )
		{
		if( v[i] == 'g' )
		{
        if(!check(i))
        {
            printf("Suspicious bugs found!\n");
			goto LABEL ;
        }}}
        //else
        {

            printf("No suspicious bugs found!\n");
        }
		LABEL : ;
    }
}

