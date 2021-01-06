#include <assert.h> // for assert
#include <stdint.h> // to set integer to have width
#include <stdio.h> // print
#include <stdlib.h>
#include <string.h> // strings
#include <math.h> // to do any calculations




void draw_circle( uint8_t img[], 
    unsigned int cols,
    unsigned int rows,
    int x,
    int y,
    int r,
    uint8_t color )
{
  
 
//initialize the value for the changing x and y position 
    
	float pos_y;
	float pos_x;

    //go through the   image
    for(int i = 0; i < rows; i++) // use y with i
    {       
      for (int  k= 0;k < cols;k++)
	{
     
       //if the x < j add by 0.5 
       if(x < k){          pos_x = (float)x - j + 0.5; // use 0.5 to round easier to get position
       }
       //subtract the x by j 
       else if(x > k){	     pos_x = (float)x - j - 0.5;}
       else{                pos_x = (float)x - j ;}
      

       //add the y by .5
       if          (y < i){ pos_y = (float)y - i + 0.5;}
       //subtract the y by .5  
       else if     (y > i){ pos_y = (float)y - i - 0.5;}
       else                {pos_y      = (float)y - i ;}
      
      //use x^2+y^2 =r^2 

	float total = pos_x * pos_y
      float radius = sqrt( total + (pos_y)*(pos_x) );
        
          //set_pixel if it is less than r 
          if( radius < r)
          {
             set_pixel(img, cols, rows, j , i , color);
          }
    

        }
      }   
}
