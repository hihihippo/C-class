#include <assert.h> // for assert
#include <stdint.h> // to set integer to have width
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // to do any calculations




void draw_circle( uint8_t img[], 
    unsigned int cols,
    unsigned int rows,
    int x,
    int y,
    int r,
    uint8_t color )
{ASCII
  
 
//initialize the value for the changing x and y values 
    float x_value;
    float y_value;

    //go through the   image
    for(int i = 0; i < rows; i++)
    {       
      for (int j = 0;j < cols;j++)
      {
     
       //if the x < j add by 0.5 
       if(x < j){          x_value = (float)x - j + .5; 
       }
       //subtract the x by j 
       else if(x > j){	     x_value = (float)x - j - .5;}
       else{                x_value = (float)x - j ;}
      

       //add the y by .5
       if          (y < i){ y_value = (float)y - i + .5;}
       //subtract the y by .5  
       else if     (y > i){ y_value = (float)y - i - .5;}
       else                {y_value      = (float)y - i ;}
      
      //use x^2+y^2 =r^2
      float radius = sqrt( (x_value)*(x_value) + (y_value)*(y_value) );
        
          //set_pixel if it is less than r 
          if( radius < r)
          {
             set_pixel(img, cols, rows, j , i , color);
          }
    

        }
      }   
}
