#include<stdio.h>

int main(){
	// bubble sort code
	int arr [] = { 5, 4, 3, 2, 1};

	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 5 - i - 1; j++ ){
		       if ( arr[j] > arr[j+1] ){
		       		int temp = arr[j];
		 		arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
       		}
	}

	

	// printing the array after sorting
	
	
	for ( int i = 0; i < 5; i++ ){
		printf("%d\n", arr[i]);
	}

	return 0;
}

