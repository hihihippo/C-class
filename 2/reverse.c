#include <stdio.h>

void reverse( int a[], unsigned int len )


{
//go through half the list and reverse it by putting the each element in temp while swapping with each element at the len of the array
 for (int i = 0; i < len/2; ++i)
    {
        int temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
 return 0;
 }


