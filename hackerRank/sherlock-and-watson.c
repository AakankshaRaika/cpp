#include <stdio.h>
#define S(n) (scanf("%d",&n))

int main(int argc, char **argv) {
	int i, n, k, q, tq;
	int arr[100005];
	S(n), S(k), S(q);
	int start, fin;
	for(i=0;i<n;i++){
		S(arr[i]);
	}
	k = k%n;
	while(q--){
		S(tq);
		printf("%d\n",arr[(n-k+tq)%n]);
	}
	return 0;
}