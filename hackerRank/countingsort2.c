#include <stdio.h>
#include <stdlib.h>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

void _initialize(int arr[],int sz)
{
	int i=0;
	for(;i<sz;i++){
		arr[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int arr[101];
	_initialize(arr, 101);
	int i,j,n,num;
	S(n);
	for(i=0;i<n;i++){
		S(num);
		arr[num]++;
	}
	for(i=0;i<101;i++){
		for(j=1;j<=arr[i];j++){
			printf("%d ", i);
		}
	}
	return 0;
}