#include <stdio.h>

#define MX 30

int main(int argc, char const *argv[]){
	/* code */
	int n[MX][MX] = {0};
	int i,j,k,l;
	n[0][0] = 1;
	for(i=1;i<MX;i++){
		for(j=0;j<=i;j++){
			if(j==0 || j==i){
				n[i][j] = 1;
			}else{
				n[i][j] = n[i-1][j-1]+n[i-1][j];
			}
		}
	}
	for (i = 0; i < MX; ++i){
		for(j=0; j<MX; j++){
			if(n[i][j]>0)
			printf("%d ", n[i][j]);
		}
		printf("\n");
	}
	return 0;
}