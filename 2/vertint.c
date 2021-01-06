#include <stdio.h>
int main(void)
{
 //initialize array, highest humber in array, and length of array//
 int arr[81]={0};// 81 because theres 80 possible + 0
 int j = 0;
 int a;
 int largest_number = arr[0]; // i need this to get largest number of array to reverse the thing
 int i = 0;

//keep scaning until EOF
while( a != EOF){

 a = scanf("%d",&arr[j]);
 j++;

}//just gets me my elements in array unless EOF

for(int element_in_arr = 0; element_in_arr <= j; element_in_arr++){
//finds largest number in array
  if (arr[element_in_arr] > largest_number){
   	largest_number = arr[element_in_arr];
   }
}
//this nested 'for loop' creates a matrix with conditional statements
for(int column = 1; column <= largest_number; column++){

  for(int row = 0; row <= j-1; row++){
//prints a space if there is difference
		if((largest_number - arr[row]) > i){
  			printf(" ");// space first to reverse
				}
		else{
  			printf("#");
				}
		}
	printf("\n");
	i+=1;

	}
return 0;
} 
