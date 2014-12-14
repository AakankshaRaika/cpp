#include <stdio.h>

int main(int argc, char **argv) {
	int i,n,t;
	int arr[100] = {0};
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t);
		arr[t]++;
	}
	for(i=0;i<100;i++){
		if(i==99){
			printf("%d\n", arr[i]);
		}else{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}