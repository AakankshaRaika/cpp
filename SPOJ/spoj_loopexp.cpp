#include<iostream>
#include<cstdio>
#define S(n) (scanf("%d",&n))
using namespace std;
int main(){
    int n,t;
    double ans;
    S(t);
    while(t--){
        ans = 0.0;
        S(n);
        for(int i=1;i<=n;i++)
            ans = ans + (double)(1.0/i);
        printf("%.6f\n",ans);
    }
}
