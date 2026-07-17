#include<stdio.h>

void reverse_string( char *str );

int main(){
	char string[] = "Mayank";
	reverse_string( string );
	printf("%s\n", string);
	return 0;
}

void reverse_string( char *str ){
	int len = 0;
	while ( str[len] != '\0' ) 
		len++;

	int p1 = 0;
	int p2 = len - 1;

	while ( p2 > p1 ){
		char temp = *( str + p1 );
		*(str + p1) = *(str + p2);
		*(str + p2 ) = temp;
		p1++;
		p2--;
	}
}
