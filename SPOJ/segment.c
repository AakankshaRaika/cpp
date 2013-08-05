#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int siz;

int minm(int a,int b){
    return ((a<b)?a:b);
}

int constructTreeUtil(int arr[],int ss,int se,int *st,int index){
    if(se==ss){
        st[index]=arr[ss];
        return arr[ss];
    }
    int m = ss+(se-ss)/2;
    st[index] = minm(constructTreeUtil(arr,ss,m,st,2*index+1),constructTreeUtil(arr,m+1,se,st,2*index+2));
    return st[index];
}

int* constructTree(int arr[],int n){
    int x = (int)(ceil(log2(n)));
    siz = 2*(int)pow(2,x)-1;
    int *st = (int*)malloc(sizeof(int)*siz);
    constructTreeUtil(arr,0,n-1,st,0);
    return st;
}

int main(){
    int arr[] = {2,5,1,4,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructTree(arr,n);
    int i=0;
    for(;i<siz;i++)
        printf("%d . ",st[i]);
}
