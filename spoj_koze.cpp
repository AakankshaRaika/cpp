#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 251
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

struct pos{
    int i,j;
};

char maze[MAX][MAX];
bool v[MAX][MAX];
int n,m,csheep,cfox;
vector<pos> sheep,fox;

bool isValid(int i,int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

void _initialize()
{
    csheep = cfox = 0;
    FOR(i,n)
        FOR(j,m){
            pos k;
            k.i = i,k.j = j;
            if(maze[i][j]=='k') {
                sheep.push_back(k);
            }else if(maze[i][j]=='v'){
                fox.push_back(k);
            }
            v[i][j] == false;
        }
}

void bfs(pos k){
    pos cur;
    queue<pos> q;
    q.push(k);
    v[k.i][k.j]=true;
    int cs,cf;
    cs = cf = 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        pos p;
        if(maze[cur.i][cur.j]=='k')
            cs++;
        else if(maze[cur.i][cur.j]=='v')
            cf++;
        for(p.i=cur.i-1,p.j=cur.j;p.i<=cur.i+1;p.i=p.i+2){
            if(isValid(p.i,p.j) && !v[p.i][p.j] && maze[p.i][p.j]!='#'){
                v[p.i][p.j]=true;
                q.push(p);
            }
        }
        for(p.i=cur.i,p.j=cur.j-1;p.j<=cur.j+1;p.j=p.j+2){
            if(isValid(p.i,p.j) && !v[p.i][p.j] && maze[p.i][p.j]!='#'){
                v[p.i][p.j]=true;
                q.push(p);
            }
        }
    }
    //cout<<cs<<" "<<cf<<"\n";
    if(cs>cf)
        csheep+=cs;
    else
        cfox+=cf;
}

int main()
{
    S(n),S(m);
    FOR(i,n)
    cin>>maze[i];
    _initialize();
    FOR(i,sheep.size()){
        if(!v[sheep[i].i][sheep[i].j])
            bfs(sheep[i]);
    }
    FOR(i,fox.size()){
        if(!v[fox[i].i][fox[i].j])
            bfs(fox[i]);
    }
    cout<<csheep<<" "<<cfox;
}
