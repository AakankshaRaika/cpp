#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int n, half, tmp;
	char stmp[11];
	scanf("%d", &n);
	half = n/2;
	int ar[half];
	char str[half][11];
	int arr[100] = {0}, helper[100] = {0}, bhalf[100] = {0};
	int i, j, k, l;
	for(i=0;i<n;i++){
		scanf("%d %s", &tmp, stmp);
		if(i>=half){
			ar[i-half] = tmp;
			strcpy(str[i-half],stmp);
		}else{
			bhalf[tmp]++;
		}
		arr[tmp]++;
	}
	helper[0] = arr[0];
	for(i=1;i<100;i++){
		helper[i] = arr[i] + helper[i-1];
	}
	/*for(i=0;i<100;i++){
		printf("%d - %d - %d\n", i, bhalf[i], arr[i]);
	}*/
	for(j=0;j<100;j++){
		if(bhalf[j]>0){
			for(k=0;k<bhalf[j];k++){
				printf("- ");
			}
		}
		if(arr[j]>0 && (arr[j]-bhalf[j]) > 0){
			for(l=0;l<half; l++){
				if(ar[l] == j){
					printf("%s ", str[l]);
				}
			}
		}
		if(helper[j]>=n){
			break;
		}
	}
	return 0;
}