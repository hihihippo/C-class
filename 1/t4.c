#include <stdio.h>
#include <math.h>

int main ( void )
{
	float b = 0.0;
	int a = 0;


	

	

	
    
    a = scanf("%f",&b);

    

    if (a == 1){
    	int i_floor = floorf(b); 
    	int i_round = roundf(b);
    	int i_ceil = ceilf(b);
    	printf("%d %d %d\n",i_floor, i_round,i_ceil);

    }

    else {
    	printf("scanf error: (%d)\n",a);
    }
    return 0;
}
