#include <stdio.h>
#include <limits.h>	 //allows me to use charbit and names to get the value
int main( void )

{
	printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", sizeof(char)*CHAR_BIT, sizeof(unsigned char)*CHAR_BIT, sizeof(int)*CHAR_BIT, sizeof(unsigned int)*CHAR_BIT, sizeof(long)*CHAR_BIT, sizeof(unsigned long)*CHAR_BIT, sizeof(float)*CHAR_BIT, sizeof(double)*CHAR_BIT, sizeof(long double)*CHAR_BIT);
    return 0;
}