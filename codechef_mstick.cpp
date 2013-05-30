#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<vector>
#include<climits>

#define MAX 100001
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

int b[MAX],stmi[5*MAX],st_max[5*MAX];

using namespace std;

void _initialize(int n)
{
    FOR(i,2*n+1)
    {
        stmi[i]=st_max[i]=(-1);
    }
}

int query_min(int a,int b,int i,int j,int node)
{
     if(a>b || a>j || b<i)return INT_MAX;
     if(a>=i && b<=j)return stmi[node];
     int p=query_min(2*node+1,a,(a+b)/2,i,j);
     int q=query_min(2*node+2,(a+b)/2+1,b,i,j);
     return min(p,q);
}
int query_max(int a,int b,int i,int j,int node)
{
     if(a>b || a>j || b<i)return INT_MAX;
     if(a>=i && b<=j)return st_max[node];
     int p=query_max(2*node+1,a,(a+b)/2,i,j);
     int q=query_max(2*node+2,(a+b)/2+1,b,i,j);
     return max(p,q);
}

/*void constructTree(int fst,int last,int in)
{
    if(fst>last)
        return;
    if(fst==last)
    {
        stmi[in] = b[fst];
        st_max[in] = b[fst];
        return;
    }
    constructTree(fst,(fst+last)/2,2*in+1);
    constructTree(((fst+last)/2)+1,last,2*in+2);
    stmi[in] = Min(stmi[2*in+1],stmi[2*in+2]);
    st_max[in] = Max(st_max[2*in+1],st_max[2*in+2]);
}*/

void min_tree(int f,int l,int i)
{
    if(f>l)
        return;
    if(f==l)
    {
        stmi[i]=b[f];
        return;
    }
    min_tree(f,(f+l)/2,2*i+1);
    min_tree((f+l)/2 + 1,l,2*i+2);
    stmi[i] = Min(stmi[2*i+1],stmi[2*i+2]);
}
void max_tree(int f,int l,int i)
{
    if(f>l)
        return;
    if(f==l)
    {
        st_max[i]=b[f];
        return;
    }
    max_tree(f,(f+l)/2,2*i+1);
    max_tree((f+l)/2 + 1,l,2*i+2);
    st_max[i] = Max(st_max[2*i+1],st_max[2*i+2]);
}

int main()
{
    int n,q,l,r;
    S(n);
    FOR(i,n)
        S(b[i]);
    min_tree(0,n-1,0);
    max_tree(0,n-1,0);
    S(q);
    while(q--)
    {
        S(l),S(r);
        double t1,t2,t3,t4,t5;
        t1 = query_max(0,n-1,0,l-1,0);
        t2 = query_max(0,n-1,l,r,0);
        t3 = query_min(0,n-1,l,r,0);
        t4 = query_max(0,n-1,r+1,n-1,0);
        t4 = Max(t1,t4);
        t5 = (t2+t3)/2.0;
        //cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<"\n";
        t5 = Max((t4+t3),t5);
        printf("%.1lf\n",t5);
    }
}
