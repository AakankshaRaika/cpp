#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<set>
#include<map>

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

int main()
{
    _initialize();
    int a[4][5] = {{1,2,3,4,1},
                   {6,7,8,9,1},
                   {11,12,13,14,1},
                   {16,17,18,19,1}};
    int m=4,n=5;
    int xl =0,yl = 0;
    int xu = m-1, yu = n-1;
    int c = 0;
    while(xl<=xu && yl<=yu){
        //if(c==(m*n))
        //    break;
        for(int i=yl;i<=yu;i++){
            cout<<a[xl][i]<<" ";
            //c++;
        }
        cout<<endl;
        xl++;
        for(int i=xl;i<=xu;i++){
            cout<<a[i][yu]<<" ";
            //c++;
        }
        cout<<endl;
        yu--;
        for(int i=yu;i>=yl;i--){
            cout<<a[xu][i]<<" ";
            //c++;
        }
        cout<<endl;
        xu--;
        for(int i=xu;i>=xl;i--){
            cout<<a[i][yl]<<" ";
            //c++;
        }
        cout<<endl;
        yl++;
    }
}
