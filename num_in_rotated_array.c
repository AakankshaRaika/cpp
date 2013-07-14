#include<stdio.h>

int binary_srch(int *arr,int low,int high,int num){
    int mid = low + (high-low)/2;
    if(high<low)
        return -1;
    if(arr[mid]==num)
        return mid;
    if(num>arr[mid])
        return binary_srch(arr,mid+1,high,num);
    return binary_srch(arr,low,mid-1,num);
}

int find_pivot(int *arr,int low,int high){
    if(high<low) return -1;
    if(high==low) return low;
    int mid = low + (high-low)/2;
    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
    if(mid>low && arr[mid]<arr[mid-1])
        return (mid-1);
    if(arr[low]>=arr[mid])
        return find_pivot(arr,low,mid-1);
    else
        return find_pivot(arr,mid+1,high);
}

int find_num(int *arr,int siz,int num){
    int pivot = find_pivot(arr,0,siz-1);
    if(pivot==-1)
        return binary_srch(arr,0,siz-1,num);
    if(arr[pivot]==num)
        return pivot;
    if(arr[0]<=num)
        return binary_srch(arr,0,pivot-1,num);
    else
        return binary_srch(arr,pivot+1,siz-1,num);
}

int main(){
    int arr[] = {3,4,5,6,7,8,9,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num;
    scanf("%d",&num);
    int pos = find_num(arr,n,num);
    printf("%d\n",pos);
}
