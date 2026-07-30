#include<stdio.h>

int andBit(int a, int b);

int main(){
	int a, b;
	printf("Enter a : ");
	scanf("%d", &a);
	printf("Enter b : ");
	scanf("%d", &b);
	
	printf("After Executing Binary And a = %d\n", andBit(a, b));
	
	return 0;
}


int andBit(int a, int b){
	return  ~((~a) | (~b));
}
