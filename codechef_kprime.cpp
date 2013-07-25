#include<iostream>
#include<cstdio>
#include<cstring>
#define max 100001

int P[max];// isPrime[max] = {true};//,c[5][max];
int R[6][max];// = {0};

void initialize(){
    for(int i=0;i<=100000;i++) P[i] = 0;
    for(int i=2;i<=100000;i++) if(P[i] == 0)
        for(int j=i;j<=100000;j+=i) P[j]++;
    for(int t=1;t<=5;t++) {
        R[t][0] = R[t][1] = 0;
        for(int i=2;i<=100000;i++) {
            R[t][i] = R[t][i-1];
            if(P[i] == t) R[t][i]++;
        }
    }
}

int main(){
    int t,a,b,k,i;
    initialize();
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&k);
        printf("%d\n",R[k][b]-R[k][a-1]);
    }
}
