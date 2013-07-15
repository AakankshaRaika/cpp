#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getSuitableIndex(int *arr,int num,int l,int h){
    int index;
    while(h-l>1){
        index = (l+h)/2;
        if(arr[index]>=num){
            h = index;
        }else
            l = index;
    }
    return index;
}

int lis(int *arr,int n){
    int *last = (int*)malloc(sizeof(int)*n);
    memset(last,0,sizeof(last[0])*n);
    last[0] = arr[0];
    int len = 1;
    int i;
    for(i=1;i<n;i++){
        if(arr[i]<last[0])
            last[0] = arr[i];
        else if(arr[i]>last[len-1]){
            last[len++] = arr[i];
        }else{
            printf("index: %d\n",getSuitableIndex(arr,0,len-1,arr[i]));
            last[getSuitableIndex(arr,-1,len-1,arr[i])] = arr[i];
        }
    }
}

int main(){
    int arr[] = {10,22,9,33,21,50,41,60,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length: %d\n",lis(arr,n));
}
