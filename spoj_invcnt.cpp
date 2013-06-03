#include<iostream>
#include<vector>
#include<cstdio>
#define max 200001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define S(n) (scanf("%d",&n))

using namespace std;

int L[max/2],R[max/2];
long long int tot;

void ar_merge(long long int a[],int f,int q,int l)
{
    int n1 = q-f+1,n2=l-q,i1=0,j1=0,k=f;
    for(int i=0;i<n1;i++) L[i] = a[i+f];
    for(int i=0;i<n2;i++) R[i] = a[q+1+i];
    while(i1<n1 && j1<n2) if(L[i1]<=R[j1]) a[k++] = L[i1++]; else a[k++] = R[j1++],tot++;
    if(i1>=n1) while(j1<n2) a[k++] = R[j1++],tot++;
    else while(i1<n1) a[k++] = L[i1++];
}

void mergesort(long long int a[],int first,int last)
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
    long long int a[max];
    int t,n;
    S(t);
    while(t--){
        S(n);
        tot = 0;
        FOR(i,n) S(a[i]);
        mergesort(a,0,n-1);
        printf("%lld\n",tot);
    }
}
