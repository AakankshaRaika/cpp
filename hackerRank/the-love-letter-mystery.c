#include <stdio.h>
#include <string.h>

#define MAX 2550
#define Min(a,b) ((a<b)?a:b)
#define Abs(a) ((a>=0)?a:(-1*a))
#define FOR(i,n) for(int i=0;i<(n);i++)
#define S(n) (scanf("%d",&n))

void _initialize()
{
}

int main(int argc, char **argv)
{
	_initialize();
	int t,i,n,sm;
	char s[10000];
	S(t);
	while(t--){
		scanf("%s",s);
		n = strlen(s);
		sm = 0;
		for(i=0;i<n/2;i++){
			if(s[i] != s[n-i-1]){
				sm += Abs(s[n-i-1] - s[i]);
			}
		}
		printf("%d\n", sm);
	}
	return 0;
}