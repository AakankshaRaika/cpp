#include <stdio.h>

#define S(n) (scanf("%d",&n))

int main(int argc, char **argv) {
	char a[10001], b[10001];
	int amap[26] = {0}, bmap[26] = {0};
	scanf("%s", a);
	scanf("%s", b);
	int i,j;
	for(i=0;a[i]!='\0';i++){
		amap[a[i]-'a']++;
	}
	for(i=0;b[i]!='\0';i++){
		bmap[b[i]-'a']++;
	}
	int cnt=0, tmp;
	for(i=0;i<26;i++){
		tmp = amap[i]-bmap[i];
		if(tmp<0){
			cnt += (-1*tmp);
		}else{
			cnt += tmp;
		}
	}
	if(cnt<0){
		printf("%d\n", -1*cnt);
	}else{
		printf("%d\n", cnt);
	}
	return 0;
}