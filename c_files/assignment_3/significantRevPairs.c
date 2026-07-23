#include<stdio.h>


int maxPairs(int arr[], int size);

int maxPairsOptimised(int arr[], int size);

void mergeSort(int arr[], int l, int r);

void merge(int arr[], int l, int m, int r);

void countPairs(int arr[], int l, int m, int r);

int count = 0;

int main(){
	
	int arr[] = {1, 3, 2, 3, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("%d\n", maxPairsOptimised(arr, size));

	return 0;
}

int maxPairs(int nums[], int size){

	int cnt = 0;	

	for (int i = 0; i < size - 1; i++){
		for (int j = i + 1; j < size; j++){
			if (nums[i] > 2 * nums[j])
				cnt++;
		}
	}
	
	return cnt;
}

void countPairs(int nums[], int l, int m, int r){
	int j = m + 1;
	for (int i = l; i <= m; i++){
		while (j <= r && (long)nums[i] > 2L * nums[j]){
			j++;
		}
		count += j - (m + 1);
	}
}

void merge(int nums[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int k = l;
	
	int left[n1];
	int right[n2];
	
	for (int i = 0; i < n1; i++){
		left[i] = nums[k++];
	}
	for (int i = 0; i < n2; i++){
		right[i] = nums[k++];
	}

	int i = 0;
	int j = 0;
	k = l;
	
	while (i < n1 && j < n2){
		if (left[i] <= right[j]){
			nums[k++] = left[i++];
		}else{
			nums[k++] = right[j++];
		}
	}
	while (i < n1){
		nums[k++] = left[i++];
	}
	while (j < n2){
		nums[k++] = right[j++];
	}
}
	
	
	

void mergeSort(int arr[], int l, int r){
	if ( l >= r) return;
	int mid = l + (r - l) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	countPairs(arr, l, mid, r);
	merge(arr, l, mid, r);
}

int maxPairsOptimised(int arr[], int size){
	mergeSort(arr, 0, size - 1);
	return count;
}


