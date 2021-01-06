#include <stdio.h>
#include <string.h>

int main(char word){  
  char c;
  float letters[26]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // 26 for each letter in alphabet
  float count = 0;


while((c = getchar())!= EOF){// takes in characters until u get EOF

        if( c >='a' && c <='z')// if they are between a and z for ascii u add to letter and add 1 to count
        {
            letters[c - 97]++;
            count = count +1;
  } 
        else{

         if(c >='A' && c <='Z') // if letters are capitcal add then add to count similar to top one
        {
            letters[c - 65]++;
            count = count + 1;
        }
      }
   }
	 	for(int i=0; i<26; i++)
        {
  
  	         if(letter[i] != 0)// need to divide by each letter to get frequency
   
             {
                float freqNumber = freq[i]/count;	
 		 
 		        printf("%c %.4f\n", (i + 97), freqNumber);
             }
        }
return 0;
}

