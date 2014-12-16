#include <stdio.h>
#define S(n) (scanf("%d",&n))

int main(int argc, char **argv) {
	int i, j, t, n;
	long arr[100001], xor;
	S(t);
	while(t--){
		S(n);
		xor = 0;
		for(i=0;i<n;i++){
			scanf("%ld", &arr[i]);
		}
		if(n%2 == 0){
			printf("0\n");
		}else{
			for(i=0;i<n;i+=2){
				xor ^= arr[i];
			}
			printf("%ld\n", xor);
		}
	}
	return 0;
}