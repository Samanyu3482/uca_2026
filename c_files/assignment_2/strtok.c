#include<stdio.h>
#include<string.h>
int main(){
	char myStr[] = "C,C++,Java,Python,Rust";
	char * myPtr = strtok(myStr, ",");
	while(myPtr != NULL) {
  		printf("%s\n", myPtr );
  		myPtr = strtok(NULL,",");
	}	
	return 0;
}
