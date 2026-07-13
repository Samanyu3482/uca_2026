#include<stdio.h>

int main(){
	printf("%zu\n", sizeof(12));
	printf("%zu\n", sizeof(12.90));

	
	printf("%zu\n", sizeof('c'));

	char v = 'v';

	printf("%zu\n", sizeof(v));
	printf("%zu\n", sizeof("Sam"));
	printf("%zu\n", sizeof(12.99990909090909));
	
	char a = 65;

	printf("%c\n",a);
	return 0;
}
