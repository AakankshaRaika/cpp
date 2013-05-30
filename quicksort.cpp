#include<iostream>
#define max 8
using namespace std;

void my_swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int qpartition(int a[],int s,int e)
{
    int x = a[e];
    int i = s-1;
    for(int j=s;j<e;j++)
    {
        if(a[j]<=x)
        {
            i = i+1;
            my_swap(a[i],a[j]);
        }
    }
    my_swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int a[],int first,int last)
{
    int pivot;
    if(first<last)
    {
        pivot = qpartition(a,first,last);
        quicksort(a,first,pivot-1);
        quicksort(a,pivot+1,last);
    }
}

int main()
{
    int a[]={2,8,7,1,3,5,6,4};
    quicksort(a,0,max-1);
    for(int i=0;i<max;i++)
    {
        cout<<a[i]<<" ";
    }
}
