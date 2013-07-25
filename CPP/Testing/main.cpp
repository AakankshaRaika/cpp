/* 
 * File:   main.cpp
 * Author: Beetoo
 *
 * Created on July 16, 2013, 4:19 PM
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int i,j;
    pos(void){
    }
    pos(int x,int y){
        i = x, j = y;
    }
};

/*
 * 
 */
char maze[51][51],current;
bool v[51][51];
int h,w,count;
vector<pos> p;

void initialize(){
    p.clear();
    count = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            v[i][j] = false;
            pos po;
            po.i = i, po.j = j;
            if(maze[i][j]=='A')
                p.push_back(po);
        }
    }
    current = 'A';
}

bool isLimit(int i,int j){
    if(i>=0 && j<h && j>=0 && j<w)
        return true;
    return false;
}

void bfs(int x,int y){
    cout<<".."<<x<<" "<<y<<endl;
    queue<pos> q;
    pos po;
    po.i = x, po.j = y;
    q.push(po);
    v[po.i][po.j] = true;
    int c;
    while(!q.empty()){
        pos pt = q.front();
        q.pop();
        for(int i=pt.i-1;i<=pt.i+1;i++){
            for(int j=pt.j-1;j<=pt.j+1;j++){
                if(!v[i][j] && isLimit(i,j) && maze[i][j]==maze[pt.i][pt.j]+1){
                    q.push(new pos(i,j));
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
}

void travel(){
    for(vector<pos>::iterator it = p.begin();it!=p.end();++it){
        if(!v[it->i][it->j])
            bfs(it->i,it->j);
    }
}

int main(int argc, char** argv) {
    
    while(cin>>h>>w && h!=0 && w!=0){
        initialize();
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
        travel();
    }
    
    return 0;
}

