#include <stdio.h>

int main(int argc, char const *argv[])
{
	int t, rem;
	long num, divider, tmp;
	scanf("%d",&t);
	int r[10], i, j, sum;
	while(t--){
		for(i=0;i<10;i++){
			r[i] = 0;
		}
		sum = 0;
		scanf("%ld", &num);
		tmp = num;
		while(tmp){
			rem = tmp % 10;
			tmp /= 10;
			if(!rem){
				continue;
			}
			if(num % rem == 0){
				r[rem]++;
			}
		}
		for(i=0;i<10;i++){
			sum+=r[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}