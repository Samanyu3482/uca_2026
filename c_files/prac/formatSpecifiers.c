#include<stdio.h>

int main(){
	// format specifiers
	
	int age = 21;
	printf( "My age is %d\n", age);

	char gender = 'm';
	printf( "Gender %c\n", gender );

	float price = 15.99;
	printf( "the price of apple is %f\n", price );

	// all combined together
	
	printf( "My age is %d and gender %c and the price of the apple is %f\n", age, gender, price );
	
	printf("I %s also %s values %s storing %s into %s\n", "can", "print", "without", "them", "var");

	return 0;
}
