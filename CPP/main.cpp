/* 
 * File:   main.cpp
 * Author: Beetoo
 * LCS Example
 * Created on April 29, 2013, 10:33 AM
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <strings.h>
#define MAX 21
#define max(a,b) ((a>b)?a:b)
using namespace std;

int L[MAX],R[MAX];

void ar_merge(int a[],int first,int mid,int last){
    int l1 = mid-first+1;
    int l2 = last-mid;
    for(int i=0;i<l1;i++)
        L[i]=a[first+i];
    for(int i=0;i<l2;i++)
        R[i]=a[mid+1+i];
    int a1 = first, a2 = mid+1;
    while((a1<(first+l1)) && (a2<(mid+1+l2))){
        
    }
    for(int i=0;i<l1;i++)
        cout<<L[i]<<" ";
    cout<<endl;
    for(int i=0;i<l2;i++)
        cout<<R[i]<<" ";
    cout<<endl;
}
void mergesort(int a[],int first,int last){
    if(first<last){
        int mid = (first+last)/2;
        mergesort(a,first,mid);
        mergesort(a,mid+1,last);
        ar_merge(a,first,mid,last);
    }
}

int main(int argc, char** argv) {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}

