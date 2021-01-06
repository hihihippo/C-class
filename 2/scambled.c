#include <stdio.h>

int scrambled (unsigned int a[], unsigned int b[], unsigned int len){
	int answer;
	int iter = 0;
	for (int i = 0; i < len;){
		
		if (a[i] != b[iter]){

			i++; //checks to see if a[i] is the same until the end of iteration
			if (i == len-1 && a[i] != b[iter]){ //if they arent the same last and first of a and b
				 answer = 0;
				
			}
			if (i == len-1 && a[i] == b[iter]){
				answer =0;
			}
		}

			// this statement basically tells checks to see if any of a matches b
		
		if (a[i] == b[iter]){
			iter ++;
			if (iter == len-1){
				 answer = 1;
				 //checks to see if they are the same
			}
		}
	
	}	
	return answer;
}

