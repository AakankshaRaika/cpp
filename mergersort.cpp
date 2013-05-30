#include<iostream>
#include<vector>
#define max 8
using namespace std;

int L[max/2],R[max/2];

void ar_merge(int a[],int f,int q,int l)
{
    int n1,n2,i1=0,j1=0,k=f;
    n1 = q-f+1;
    n2 = l-q;
    for(int i=0;i<n1;i++)
    {
        L[i] = a[i+f];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = a[q+1+i];
    }
    while(i1<n1 && j1<n2)
    {
        if(L[i1]<=R[j1])
        {
            a[k] = L[i1];
            i1 = i1+1;
        }
        else
        {
            a[k] = R[j1];
            j1 = j1+1;
        }
        k = k+1;
    }
    if(i1>=n1)
    {
        while(j1<n2)
        {
            a[k++] = R[j1++];
        }
    }
    else
    {
        while(i1<n1)
        {
            a[k++] = L[i1++];
        }
    }
}

void mergesort(int a[],int first,int last)
{
    if(first<last)
    {
        int q = (first+last)/2;
        mergesort(a,first,q);
        mergesort(a,q+1,last);
        ar_merge(a,first,q,last);
    }
}

int main()
{
    int a[] = {2,8,1,7,3,5,6,4};
    mergesort(a,0,max-1);
    for(int i=0;i<max;i++)
    {
        cout<<a[i]<<" ";
    }
}
