#include<iostream>
#include<climits>
using namespace std;

int m[100][100]={0};
int s[100][100]={0};

void matrix_order(int p[],int n)
{
    for(int i=1;i<=n;i++)
        m[i][i] = 0;
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parenth(int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i<<" ";
    }
    else
    {
        cout<<"(";
        print_optimal_parenth(i,s[i][j]);
        print_optimal_parenth(s[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    int p[100],n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>p[i];
    matrix_order(p,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<m[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<=n;j++)
            cout<<s[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n"<<m[1][n]<<"\n";
    print_optimal_parenth(1,n);
}
