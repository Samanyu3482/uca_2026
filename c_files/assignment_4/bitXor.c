#include<stdio.h>

int bitXor(int a, int b);

int main(){
	int a;
	int b;
	printf("Enter a : ");
	scanf("%d", &a);
	printf("Enter b : ");
	scanf("%d", &b);
	
	printf("a ^ b is %d\n", bitXor(a, b));
	
	return 0;
}

int bitXor(int a, int b){
	int x = ~a & b;
	int y = a & ~b;

	return ~(~x & ~y);
}
