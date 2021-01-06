#include <stdio.h>
#include <math.h>
int main(void) {
  
    
  int count=0;

  float number;
  scanf("%f",&number);// required for first statement
  float smallest = number;
  float largest = number;
  float total = number; //all added together
  
  
  for (int i =0; i <2; i ++){
  count++;  
  int a = scanf("%f",&number);
  
  if (a == EOF){
    float middle = (total) /count;
    printf("%.2f %.2f %.2f\n",smallest,largest, middle);

    return 0;
  } 
  total = total + number;
   
  if (smallest>number){ //smallest turns into number if larger
    smallest = number;
  }
  if (largest < number){ // largest turns into number if smaller
    largest = number;
  }
  i =0;
  
}
  
  
}