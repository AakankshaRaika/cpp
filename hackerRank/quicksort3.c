#include <stdio.h>

int sz, k, swapped;

int partition(int *ar, int start, int fin){
	int pivot = ar[fin-1];
	int index = start - 1, j, tmp, k;
	swapped = 0;
	for(j=start;j<fin;j++){
		if(ar[j]<pivot){
			index++;
			tmp = ar[index];
			ar[index] = ar[j];
			ar[j] = tmp;
			if(index != j){
				swapped = 1;
			}
		}
	}
	tmp = ar[index+1];
	ar[index+1] = ar[fin-1];
	ar[fin-1] = tmp;
	if(index+1 != fin-1)
		swapped = 1;
	/*for(k=0;k<sz;k++){
		printf("%d ", ar[k]);
	}
	printf("\n");*/
	return index+1;
}

void quicksort(int *ar, int first, int last){
	if(first < last){
		int pivot = partition(ar, first, last);
		if(swapped){
			for(k=0;k<sz;k++){
				printf("%d ", ar[k]);
			}
			printf("\n");
		}
		quicksort(ar, first, pivot);
		quicksort(ar, pivot+1, last);
	}
}

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	sz = n;
	int ar[n], i;
	for(i=0;i<n;i++){
		scanf("%d", &ar[i]);
	}
	quicksort(ar, 0, n);
	return 0;
}