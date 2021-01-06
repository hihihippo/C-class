#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
	intarr_t * testarray = intarr_create(5);
	intarr_set(testarray, 3, 7 );
	int i = 3;
		printf("%d %d\n",testarray->data[i],i);
	}
