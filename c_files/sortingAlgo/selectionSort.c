#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort ( int arr [], int length );
void print ( int arr [], int length );
void genRan ( int arr [], int length );

int main(){
	printf("Enter the length of array to be generated : ");
	int length;
	scanf("%d", &length);

	int arr [length];

	genRan(arr, length);
	sort(arr, length);
	print(arr, length);

	return 0;
}

void sort( int arr [], int length ){
	for ( int  i = 0; i < length - 1; i++ ){
		int smallIdx = i;
		for ( int j = i +1; j < length; j++){
			if ( arr[j] < arr[smallIdx] ){
				smallIdx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[smallIdx];
		arr[smallIdx] = temp;
	}
}
void print( int arr [], int length ){
	for ( int i = 0; i < length; i++ ){
		printf("%d\n", arr[i]);
	}
}
void genRan ( int arr [], int length ){
	srand(time(NULL));
	for ( int i = 0; i < length; i++ ) {
		arr[i] = rand();
	}
}

