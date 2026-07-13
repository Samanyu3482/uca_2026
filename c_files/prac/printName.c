#include <stdio.h>

int main(){
	
	char name [5]  = "Sam";
	printf("Hello %s \n", name);

	// this is a single line comment in C
	/* this 
	 * is 
	 * a multi
	 * line 
	 * comment
	 */
	char comment[] = "comment";
	printf("demonstrated single and multi line %s\n", comment);

	printf("just giving a \t tab space here\n");
	printf("just inserting a backslash \\ \n");

	printf("inserting a double quote feels like \" \n");
	

	return 0;
}
