#include <stdio.h>
#include <limits.h>

#define S(n) (scanf("%d",&n))

int main(int argc, char **argv) {
	int n, i;
	S(n);
	int arr[n];
	for(i=0;i<n;i++){
		S(arr[i]);
	}
	int mn, tcount;
	while(1){
		mn = INT_MAX;
		tcount = 0;
		for(i=0;i<n;i++){
			if(arr[i]<mn && arr[i]!=0){
				mn = arr[i];
			}
		}
		if(mn == INT_MAX)
			break;
		for(i=0;i<n;i++){
			if(arr[i]>=mn){
				arr[i]-=mn;
				tcount++;
			}
		}
		printf("%d\n", tcount);
	}
	return 0;
}