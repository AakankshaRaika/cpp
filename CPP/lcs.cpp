/* 
 * File:   main.cpp
 * Author: Beetoo
 * LCS Example
 * Created on April 29, 2013, 10:33 AM
 */

#include <iostream>
#define MAX 21
#define max(a,b) ((a>b)?a:b)
using namespace std;

string x,y;
int c[MAX][MAX];

void print_lcs(int m,int n){
    if(m==0 || n==0)
        return;
    else if(x[m-1]==y[n-1]){
        print_lcs(m-1,n-1);
        cout<<x[m-1];
    }
    else if(c[m][n]==c[m-1][n])
        print_lcs(m-1,n);
    else
        print_lcs(m,n-1);
}

void lcs(){
    for(int i=0;i<x.size();i++){
        c[i][0] = 0;
    }
    for(int i=0;i<y.size();i++){
        c[0][i] = 0;
    }
    for(int i=1;i<=x.size();i++){
        for(int j=1;j<=y.size();j++){
            if(x[i-1]==y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
            }
            else{
                c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
        }
    }
}

/*int main(int argc, char** argv) {
    cin>>x>>y;
    lcs();
    cout<<c[x.size()][y.size()]<<endl;
    print_lcs(x.size(),y.size());
}*/

