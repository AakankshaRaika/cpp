#include<iostream>
using namespace std;

int binSearch(int a[],int ele,int n)
{
    int st = 0,ed = n-1;
    int mid;
    while(st<=ed)
    {
        mid = (st+ed)/2;
        if(ele==a[mid])
        {
            return mid+1;
        }
        else if(ele<a[mid])
        {
            ed = mid-1;
        }
        else
        {
            st = mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    cout<<binSearch(a,5,8);
}
