#include <stdio.h>

int sz, k;

int partition(long *ar, int start, int fin){
	int pivot = ar[fin-1];
	int index = start - 1, j, tmp, k;
	for(j=start;j<fin;j++){
		if(ar[j]<pivot){
			index++;
			tmp = ar[index];
			ar[index] = ar[j];
			ar[j] = tmp;
		}
	}
	tmp = ar[index+1];
	ar[index+1] = ar[fin-1];
	ar[fin-1] = tmp;
	return index+1;
}

void quicksort(long *ar, int first, int last){
	if(first < last){
		int pivot = partition(ar, first, last);
		quicksort(ar, first, pivot);
		quicksort(ar, pivot+1, last);
	}
}

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	long k, price[n];
	scanf("%ld", &k);
	int i, count=-1;
	for(i=0;i<n;i++){
		scanf("%ld", &price[i]);
	}
	quicksort(price, 0, n);
	for(i=0;i<n && k>=0;i++){
		k-=price[i];
		count++;
	}
	printf("%d\n", count);
	return 0;
}