#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char * argv[]) {

   int len = strlen(argv[1]);
   int len_2 = strlen(argv[2]);

if (strstr(argv[1], argv[2]) == NULL){
	printf("false\n");

	}
else{
	printf("true\n"); // why does it go straight to 2nd answer???
	}
}
