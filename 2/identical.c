#include <stdio.h>
#include <stdlib.h>

int identical (int a[], int b[], unsigned int len){

	for (int i =0;i <len;i++){

		if (a[i]!=b[i]){
			//checks to see if a = b
			printf("a and b are NOT identical\n");
			return 0;
		}
		
	}
	printf("a and b are identical\n");
	return 1;
	if (len = 0){
		return 1;
	}
}