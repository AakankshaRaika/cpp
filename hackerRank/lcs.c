#include <stdio.h>

#define S(n) (scanf("%d",&n))
#define max(a,b) ((a>b)?a:b)

int x[101], y[101], c[101][101];
int m, n;

void print_lcs(int i,int j){
    if(i==0 || j==0)
        return;
    if(x[i-1]==y[j-1]) {
        print_lcs(i-1,j-1);
        printf("%d ", x[i-1]);;
    }
    else if(c[i][j]==c[i-1][j])
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}

void lcs_length(int n, int m) {
	int i, j;
    for(i=0;i<n;i++)
        c[i][0] = 0;
    for(i=0;i<m;i++)
        c[0][i] = 0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i-1]==y[j-1]) {
                c[i][j] = c[i-1][j-1]+1;
            }
            else {
                c[i][j] = max(c[i][j-1],c[i-1][j]);
            }
        }
    }
}

int main(int argc, char **argv) {
	S(n), S(m);
	int i,j;
	for(i=0;i<n;i++){
		S(x[i]);
	}
	for(i=0;i<m;i++){
		S(y[i]);
	}
	lcs_length(n, m);
	print_lcs(n, m);
	return 0;
}