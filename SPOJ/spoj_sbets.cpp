#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<climits>

#define MAX variable/whatever_req
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

void _initialize()
{
}
struct type{
    int win,loss;
};

int main()
{
    _initialize();
    int t;
    S(t);
    int c1,c2;
    string s1,s2;
    while(t--){
        map<string,type> team;
        FOR(i,16){
        cin>>s1>>s2;
        S(c1),S(c2);
        if(team.find(s1)==team.end())
            team[s1].win=team[s1].loss=0;
        if(team.find(s2)==team.end())
            team[s2].win=team[s2].loss=0;
        if(c1>c2){
            team[s1].win++;
            team[s2].loss++;
        }
        else{
            team[s1].loss++;
            team[s2].win++;
        }
        }
        for(map<string,type>::iterator it = team.begin();it!=team.end();it++){
            if(team[it->first].loss==0){
                cout<<it->first<<"\n";
                break;
            }
        }
    }
}
