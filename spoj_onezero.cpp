#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

#define MAX 20001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

struct node{
    int s;
    char c;
};

bool v[MAX];
int Q[MAX],n;
node pre[MAX];

void _initialize(int n){
    FOR(i,n) v[i]=0;
}

void bfs(int s){
    int qt,qh,u,p[2];
    qt = qh = 0;
    pre[s].s=-1;
    pre[s].c='1';
    Q[qt++] = s;
    v[s] = 1;
    while(qh<qt){
        u = Q[qh++];
        p[0] = (u*(10%n))%n;
        p[1] = (p[0]+1)%n;
        FOR(i,2){
            if(!v[p[i]]){
                pre[p[i]].s = u;
                pre[p[i]].c = '0'+i;
                if(!p[i]) return;
                v[p[i]] = 1;
                Q[qt++] = p[i];
            }
        }
    }
}

void print(int u){
    if(u==-1) return;
    print(pre[u].s);
    printf("%c",pre[u].c);
}

int main(){
    int t;
    S(t);
    while(t--){
        S(n);
        if(n==1){
            printf("1\n");
            continue;
        }
        _initialize(n);
        bfs(1);
        print(0);
        printf("\n");
    }
}
