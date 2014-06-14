#include <stdio.h>
#include <stdlib.h>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

int main(int argc, char **argv)
{
	int i,t,n,j,ai,je,mn;
	int *arr;
	S(n);
	S(t);
	arr = (int*)malloc(sizeof(int)*n);
	FOR(i,n){
		S(*(arr+i));
	}
	while(t--){
		S(ai);
		S(je);
		mn = *(arr+ai);
		for(i=ai;i<=je;i++){
			mn = Min(mn, *(arr+i));
		}
		printf("%d\n", mn);
	}
	return 0;
}