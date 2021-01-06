#include <stdio.h>
#define RANGE 100 // because 0-99 inclusive





int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{

 int first[RANGE]= {0};
 int second[RANGE] = {0};
 
     //if the a[i] matches the index of buffer then increase that index by one
    for (int i=0; i < len; i++)
       {
          first[a[i]]++;   
          second[b[i]]++;
       }
   

    
  for(int i = 0; i < RANGE ; i++)
  {
 
   if(first[i] != second[i])
    {
         return 0;
    }
  }

   return 1;
}





