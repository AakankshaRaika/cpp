#include <stdio.h>
#include <stdlib.h>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

unsigned long long int get_sum(unsigned long long int  n,unsigned long long int m){
	int sm = 1;
	if(n%2==0){
		sm = n/2;
		sm *= (n+1);
	}else{
		sm = (n+1)/2;
		sm *=n;
	}
	return sm;
}

int main(int argc, char **argv)
{
	int t;
	unsigned long long int i,n,m,sm,q,r;
	S(t);
	while(t--){
		scanf("%llu",&n);
		scanf("%llu",&m);
		if(n == m)
			n = n-1;
		if(n<m){
			sm = get_sum(n,m);
		}else{
			q = n/m;
			r = n%m;
			sm = get_sum(m-1,m)*q + get_sum(r,m);
		}
		printf("%llu\n", sm);
	}
	return 0;
}