#include <stdio.h>
#include <stdlib.h>

void partition(int ar_size, int *ar) {
	int pivot = ar[0], i=ar_size, j, tmp, k;
	int nar[ar_size];
	for(j=0;j<ar_size;j++){
		nar[j] = 0;
	}
	int cnt = 0;
	for(j=1;j<ar_size;j++){
		if(ar[j]<pivot){
			nar[cnt++] = ar[j];
		}
	}
	nar[cnt++] = pivot;
	for(j=1;j<ar_size;j++){
		if(ar[j]>=pivot){
			nar[cnt++] = ar[j];
		}
	}
	for(k=0;k<ar_size;k++){
		printf("%d ", nar[k]);
	}
	/*for(j=ar_size-1; j>0; j--){
		if(ar[j] > pivot){
			i = i-1;
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
			for(k=0; k<ar_size; k++){
				printf("%d ", ar[k]);
			}
			printf("\n");
		}
	}
	tmp = ar[i-1];
	ar[i-1] = ar[0];
	ar[0] = tmp;*/
}

int main(void) {
   	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]); 
	}
	partition(_ar_size, _ar);
	/*for(_ar_i=0;_ar_i<_ar_size;_ar_i++){
		if(_ar_i == _ar_size-1){
			printf("%d\n", _ar[_ar_i]);
		}else{
			printf("%d ", _ar[_ar_i]);
		}
	}*/
   	return 0;
}
