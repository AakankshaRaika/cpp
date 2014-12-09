#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void partition(int ar_size, int *ar) {
}

int main(void) {
   	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
	   scanf("%d", &_ar[_ar_i]); 
	}
	partition(_ar_size, _ar);
	for(_ar_i=0;_ar_i<_ar_size;_ar_i++){
		printf("%d\n", _ar[_ar_i]);
	}
   	return 0;
}
