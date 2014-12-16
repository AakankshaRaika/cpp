#include <stdio.h>

#define MAX 1000
#define MOD 1000000000
#define S(n) (scanf("%d",&n))

long c[MAX][MAX];

int main(int argc, char **argv) {
	int i, j;
	c[0][0] = 1;
	c[1][0] = c[1][1] = 1;
	for(i=2;i<MAX;i++){
		for(j=0;j<=i;j++){
			if(j==0){
				c[i][j] = 1;
			}else{
				c[i][j] = (c[i-1][j-1]+c[i-1][j]) % MOD;
			}
		}
	}
	int t, n;
	S(t);
	while(t--){
		S(n);
		for(i=0;i<=n;i++){
			if(i==n){
				printf("%ld\n", c[n][i]);
			}else{
				printf("%ld ", c[n][i]);
			}
		}
	}
	return 0;
}