#include <stdio.h>
#include <stdlib.h>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

void _initialize()
{
}

int main(int argc, char **argv)
{
	_initialize();
	int n,i,j,k,t;
	int shifts = 0;
	int *arr;
	S(n);
	arr = (int*)malloc(sizeof(int)*n);
	
	for (i = 0; i < n; ++i){
		S(*(arr+i));
	}

	for(i=1;i<n;i++){
		j = i;
		while(j > 0 && (*(arr+j-1) > *(arr+j))){
			t = *(arr+j-1);
			*(arr+j-1) = *(arr+j);
			*(arr+j) = t;
			shifts++;
			j--;
		}
	}
	printf("%d", shifts);
	return 0;
}