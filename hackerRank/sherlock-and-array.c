#include <stdio.h>
#define S(n) (scanf("%d",&n))

long long pre[100005];

int main(int argc, char **argv) {
	int t, n, x;
	S(t);
	int i,j, flag;
	while(t--){
		S(n);
		flag = pre[0] = 0;
		for(i=1;i<=n;i++){
			S(x);
			pre[i] = pre[i-1] + x;
		}
		for(i=1;i<=n;i++){
			if(pre[i-1] == (pre[n]-pre[i])){
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
		}
	}
	return 0;
}