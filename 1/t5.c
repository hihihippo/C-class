#include <stdio.h>
#include <math.h>

int main ( void )
{
	float b = 0.0;
	int a = 0;
	int i=0;

    for (i=0; i<1000;i++){

    	

    	a = scanf("%f",&b);
    if (a== EOF){
		printf("Done.\n");
		i = 1000;
		return 0;
	}

  

    if (a == 1){ 
    	int i_floor = floorf(b); 
    	int i_round = roundf(b);
    	int i_ceil = ceilf(b);
    	printf("%d %d %d\n",i_floor, i_round,i_ceil);
    	i = 0;
    	}
    }	
    return 0;	
	}
    
