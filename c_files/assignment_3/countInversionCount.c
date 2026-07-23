#include<stdio.h>


int count;
void init();
void countInversions(int arr[], int l, int m, int r);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int countInversionsUtil(int arr[], int size);
int countInversionsUtilOptimised(int arr[], int size);


void init(){
	count = 0;
}

int main(){
	int arr[] = {1, 2, 4, 1, 3, 5};
	
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("The inversions through unoptimised code : %d\n", countInversionsUtil(arr, size));

	printf("The inversions through optimised code : %d\n", countInversionsUtilOptimised(arr, size));

	return 0;
}

int countInversionsUtil(int nums[], int size){
	init();
	for (int i = 0; i < size - 1; i++){
		for (int j = i + 1; j < size; j++){
			if (nums[i] > nums[j]) count++;
		}
	}
	return count;	
}

void countInversions(int nums[], int l, int m, int r){
	
	int j = m + 1;
	for (int i = l; i <= m; i++){
		while (j <= r && nums[i] > nums[j]) j++;
		count += j - (m + 1);
	}

}

void merge(int nums[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;

	int k = l;
	
	int left[n1];
	int right[n2];

	for (int i = 0; i < n1; i++) left[i] = nums[k++];
	for (int i = 0; i < n2; i++) right[i] = nums[k++];

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
	

	while (i < n1) nums[k++] = left[i++];
	while (j < n2) nums[k++] = right[j++];

}

void mergeSort(int nums[], int l, int r){
	if (l >= r) return;
	int mid = l + (r - l) / 2;
	
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);
	countInversions(nums, l, mid, r);
	merge(nums, l, mid, r);
}



int countInversionsUtilOptimised(int nums[], int size){
	init();
	mergeSort(nums, 0, size - 1);
	return count;
}




