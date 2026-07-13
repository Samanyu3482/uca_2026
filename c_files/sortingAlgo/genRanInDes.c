#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort( int arr [], int length );
void print( int arr [], int length );
int main(){
        srand(time(NULL));

        int arr [10];
        int *ptr = arr;

        for ( int i = 0; i < 10; i++ ){
                int num = rand();
                *(ptr + i) = num;
        }

        int length = sizeof(arr) / sizeof(arr[0]);

        // bubble sort to sort

        sort ( arr, length );

        // print 

        print( arr, length );
}

void sort( int arr [], int length ){


        for ( int i = 0; i < length - 1; i++ ){
                for ( int j = 0; j < length - i - 1; j++ ){
                        if ( arr[j+1] > arr[j] ){
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}

void print( int arr [], int length ){

        for ( int i = 0; i < length; i++ ){
		printf("%d\n", arr[i]);
	}
}
                                                                                                                             
