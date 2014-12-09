#include <stdio.h>

long long height[61];

void init(int ih){
	height[0] = ih;
	int i=0;
	for(;i<61;i++){
		if(i%2 == 1){
			height[i] = 2*height[i-1];
		}else {
			height[i] = height[i-1]+1;
		}
	}
}

int main(int argc, char **argv) {
	init(1);
	int t, n;
	scanf("%d", &t);
	int i = 0;
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", height[n]);
	}
	return 0;
}