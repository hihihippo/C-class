#include <stdio.h>
#include <math.h>

int main ( void )
{
	float b = 0.0;

	
    scanf("%f",&b);

    int i_floor = floorf(b); 
    int i_round = roundf(b);
    int i_ceil = ceilf(b);

    


    printf("%d %d %d\n", i_floor, i_round, i_ceil); //i would use %f if they didnt ask for single digit
    return 0;
}
