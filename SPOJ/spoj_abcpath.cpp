#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int i,j;
};

char maze[51][51];
bool v[51][51];
int h,w,co[51][51],mx,gl,cn;

void initialize(){
    gl = mx = cn = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            v[i][j] = false;
            co[i][j] = 0;
        }
    }
}

bool isLimit(int i,int j){
    if(i>=0 && j<h && j>=0 && j<w)
        return true;
    return false;
}

void bfs(int x,int y){
    queue<pos> q;
    pos po;
    po.i = x, po.j = y;
    q.push(po);
    v[po.i][po.j] = true;
    co[po.i][po.j] = 1;
    while(!q.empty()){
        cn++;
        pos pt = q.front();
        q.pop();
        for(int i=pt.i-1;i<=pt.i+1;i++){
            for(int j=pt.j-1;j<=pt.j+1;j++){
                if(!v[i][j] && isLimit(i,j) && maze[i][j]==maze[pt.i][pt.j]+1){
                    pos pu;
                    pu.i = i,pu.j = j;
                    q.push(pu);
                    co[pu.i][pu.j] = co[pt.i][pt.j]+1;
                    if(co[pu.i][pu.j]>mx)
                        mx = co[pu.i][pu.j];
                    v[i][j] = true;
                }
            }
        }
    }
    if(gl<mx)
        gl = mx;
}

void travel(vector<pos> p){
    for(vector<pos>::iterator it = p.begin();it!=p.end();++it){
        if(!v[it->i][it->j])
            mx = 1, bfs(it->i,it->j);
    }
}

int main(int argc, char** argv) {
    static int iter=1;
    while(cin>>h>>w && h!=0 && w!=0){
        initialize();
        vector<pos> p;
        for(int i=0;i<h;i++)
            cin>>maze[i];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                pos po;
                po.i = i,po.j = j;
                if(maze[i][j]=='A')
                    p.push_back(po);
            }
        }
        if(p.size()>0)
            travel(p);
        else
            mx = 0;
        printf("Case %d: %d\n",iter,gl);
        ++iter;
    }

    return 0;
}

