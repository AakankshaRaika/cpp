#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 6102
#define max(a,b) ((a>b)?a:b)

int c[MAX][MAX];
string x,y;

int lcs_length()
{
    for(int i=0;i<x.size();i++)
        c[i][0] = 0;
    for(int i=0;i<y.size();i++)
        c[0][i] = 0;
    for(int i=1;i<=x.size();i++)
    {
        for(int j=1;j<=y.size();j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
            }
            else
            {
                c[i][j] = max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    return c[x.size()][x.size()];
}

int main()
{
    int t;
    cin>>t;
   while(t--)
   {
       cin>>x;
       y = x;
       reverse(y.begin(),y.end());
       cout<<x.size()-lcs_length()<<endl;
   }
}
