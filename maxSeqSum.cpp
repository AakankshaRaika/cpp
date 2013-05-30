#include<iostream>
using namespace std;
#define max 7

int msum,st,ed;
int a[] = {-1,-22,3,-4,5,-6,-7};

void maxSeqSumN2()
{
    msum = 0;
    for(int i=0;i<max;i++)
    {
        int thisSum = 0;
        for(int j=i;j<max;j++)
        {
            thisSum += a[j];
            if(thisSum>msum)
            {
                msum = thisSum;
                st = i;
                ed = j;
            }
        }
    }
}

void maxSeqSumN3()
{
    msum = 0;
    for(int i=0;i<max;i++)
    {
        for(int j=i;j<max;j++)
        {
            int thisSum = 0;
            for(int k=i;k<=j;k++)
            {
                thisSum += a[k];
            }
            if(thisSum>msum)
            {
                msum = thisSum;
                st = i;
                ed = j;
            }
        }
    }
}

void maxSeqSumN()
{
    int thisSum = 0;
    msum = 0;
    for(int i=0,j=0;j<max;j++)
    {
        thisSum += a[j];
        if(thisSum>msum)
        {
            msum = thisSum;
            st = i;
            ed = j;
        }
        else if(thisSum<0)
        {
            i=j+1;
            thisSum = 0;
        }
    }
}

int main()
{
    maxSeqSumN();
    cout<<msum<<" "<<st<<" "<<ed<<endl;
    //maxSeqSumN3();
    //cout<<msum<<" "<<st<<" "<<ed;
}
