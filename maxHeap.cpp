#include<iostream>
#define max 10
using namespace std;

void my_swap(int &a,int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}

void max_heapify(int a[],int index, int heap_size)
{
    int left,right,largest;
    left = 2*index+1;
    right = 2*index+2;
    if(left <= (heap_size-1) && a[left]>a[index])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    if(right <= (heap_size-1) && a[right]>a[largest])
    {
        largest = right;
    }
    if(largest != index)
    {
        my_swap(a[index],a[largest]);
        max_heapify(a,largest,heap_size);
    }
}

void build_max_heap(int a[],int heap_size)
{
    for(int i=(heap_size-1)/2;i>=0;i--)
    {
        max_heapify(a,i,heap_size);
    }
}

void min_heapify(int a[],int index, int heap_size)
{
    int left,right,smallest;
    left = 2*index+1;
    right = 2*index+2;
    if(left <= (heap_size-1) && a[left]<a[index])
    {
        smallest = left;
    }
    else
    {
        smallest = index;
    }
    if(right <= (heap_size-1) && a[right]<a[smallest])
    {
        smallest = right;
    }
    if(smallest != index)
    {
        my_swap(a[index],a[smallest]);
        min_heapify(a,smallest,heap_size);
    }
}

void build_min_heap(int a[],int heap_size)
{
    for(int i=(heap_size-1)/2;i>=0;i--)
    {
        min_heapify(a,i,heap_size);
    }
}

void heapsort(int a[],int heap_size)
{
    build_max_heap(a,heap_size);
    for(int i=heap_size-1;i>=1;i--)
    {
        my_swap(a[0],a[i]);
        heap_size--;
        max_heapify(a,0,heap_size);
    }
}

void heap_increase_key(int a[],int ele,int key,int heap_size)
{
    if(key<a[ele])
    {
        cout<<"Less key.\n";
        return;
    }
    a[ele] = key;
    while(ele>0)
    {
        //cout<<ele<<" ";
        if(a[ele]>a[(ele-1)/2])
        {
            my_swap(a[ele],a[(ele-1)/2]);
        }
        ele = (ele-1)/2;
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    build_max_heap(a,max);
    for(int i=0;i<max;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    int k,e;
    cin>>e>>k;
    heap_increase_key(a,e,k,max);
    //heapsort(a,max);
    for(int i=0;i<max;i++)
    {
        cout<<a[i]<<" ";
    }
}
