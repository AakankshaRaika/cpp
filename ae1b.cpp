#include <iostream>
#include <cstdio>
#include <algorithm>

#define max 1001

using namespace std;

int main(){
	int n,k,s,a[max];
	scanf("%d %d %d",&n,&k,&s);
	int tot = k*s;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int temp,count;
	count = temp = 0;
	for(int i=n-1;i>=0;i++){
		temp+=a[i];
		count++;
		if(temp>=tot)
			break;
	}
	printf("%d\n",count);
}
