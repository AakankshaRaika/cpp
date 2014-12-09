#include <stdio.h>

int main(int argc, char **argv) {
	int t, i;
	int count;
	char c[1000001], prev;
	scanf("%d", &t);
	getchar();
	while(t--){
		i = count = 0;
		fgets(c, 100000, stdin);
		prev = c[0];
		for(i=1; c[i]!='\0'; i++){
			if(c[i] == prev){
				count++;
			}
			prev = c[i];
		}
		printf("%d\n", count);
	}
	return 0;
}