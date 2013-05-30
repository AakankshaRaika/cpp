#include<cstdio>
#define ABS(x) (((x)<0)?-(x):(x))

int main()
{
	int n, i, a;
	long long res, tot;
	while(scanf("%d", &n)==1 && n)
	{
		res = tot = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			tot += a;
			res += ABS(tot);
		}
		printf("%lld\n", res);
	}
	return 0;
}