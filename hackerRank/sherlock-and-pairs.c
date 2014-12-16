#include <stdio.h>
#include <string.h>
#define S(n) (scanf("%d",&n))

int arr[1000001];

int main(int argc, char **argv) {
	int t, n, i, j, an;
	long long tcount;
	S(t);
	while(t--){
		S(n);
		memset(arr, 0, sizeof(arr));
		tcount = 0;
		for(i=0;i<n;i++){
			S(an);
			arr[an]++;
		}
		for(i=0;i<=1000001;i++){
			if(arr[i]>=2){
				tcount += (long long)(arr[i])*(long long)(arr[i]-1);
			}
		}
		printf("%lld\n", tcount);
	}
	return 0;
}