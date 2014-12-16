#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int *ar, int start, int last){
	int pivot = ar[last-1], index = start-1, j, tmp;
	for(j=start; j<last; j++){
		if(ar[j]<pivot){
			index++;
			swap(&ar[j], &ar[index]);
		}
	}
	swap(&ar[index+1], &ar[last-1]);
	return index+1;
}

/*int quicksort(int *ar, int start, int last, int ost, int oen){
	if(start < last){
		int point = partition(ar, start, last);
		if(point == (oen-ost)/2){
			return ar[point];
		}
		quicksort(ar, start, point, ost, oen);
		quicksort(ar, point+1, last, ost, oen);
	}
}*/

int main(int argc, char **argv) {
	int n,i;
	scanf("%d", &n);
	int ar[n];
	for(i=0;i<n;i++){
		scanf("%d", &ar[i]);
	}
	int point;
	int start, end;
	start = 0, end = n;
	while(1){
		point = partition(ar, start, end);
		if(point == (n/2)){
			printf("%d\n", ar[point]);
			return 0;
		}
		if(point > (n/2)){
			end = point;
		}else if(point<n/2){
			start = point+1;
		}
	}
	return 0;
}