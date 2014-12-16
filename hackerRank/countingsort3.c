#include <stdio.h>
int main(int argc, char **argv) {
	int n;
	char ch[100];
	int arr[100] = {0};
	scanf("%d", &n);
	int i, t;
	for(i=0;i<n;i++){
		scanf("%d %s", &t, ch);
		arr[t]++;
	}
	/*for(i=0;i<100;i++){
		printf("%d ", arr[i]);
	}*/
	printf("%d ", arr[0]);
	for(i=1;i<100;i++){
		arr[i] = arr[i] + arr[i-1];
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}