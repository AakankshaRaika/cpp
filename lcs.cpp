#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 20
#define max(a,b) ((a>b)?a:b)

int c[MAX][MAX],b[MAX][MAX];
string x,y;

void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(x[i-1]==y[j-1])
    {
        print_lcs(i-1,j-1);
        cout<<x[i-1];
    }
    else if(c[i][j]==c[i-1][j])
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}

void lcs_length()
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
}

int main()
{
    /*
    *LCS testing
    cin>>x>>y;
    lcs_length();
    cout<<c[x.size()][y.size()]<<endl;
    print_lcs(x.size(),y.size());
    */

    /*
    --MINIMUM op for palindrome
    cin>>x;
    y = x;
    reverse(y.begin(),y.end());
    lcs_length();
    int l = c[x.size()][y.size()];
    cout<<x.size()-l;
    */
}
