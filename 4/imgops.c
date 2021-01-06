/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows ); 
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert(y < rows); // as long as r is less than rows we will not get an error in stdin
    assert(x < cols ); 
   
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
     unsigned int cols,
     unsigned int rows )
{
  for( int y=0; y< rows; y++)
   {
     for(int x=0; x < cols; x++)
     {
       set_pixel( array, cols, rows, x, y, 0);
     }
   }

}

// Returns y+rect_height pointer to y+rect_height freshly allocated array that contains the
// same values as the original array, or y+rect_height null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  int total = cols *rows;
  uint8_t * same = malloc( total* sizeof(uint8_t)); // returns cols & row as a pointer called same
  if(same == NULL){
    return NULL;
  for( int y = 0; y < rows; y++)
  {   
      for (int x =0; x < cols; x++)
        {
           uint8_t color = get_pixel( array, cols, rows, x, y);
           set_pixel( same, cols, rows, x, y, color);
        }
      }     
 return same;
        
    }
}

/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
       unsigned int cols, 
       unsigned int rows )
{

  // your code here
  int darkest = array[0];
  int total = (rows *cols); //need to scan through entire array
  for (int i = 0; i <total; i++){
    if (darkest < array[i]){
      darkest = array[i];
    }
  }
  return darkest; // gets darkest colour of array and returns it
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
     unsigned int cols, 
     unsigned int rows )
{
  int lightest = array[0];
  int total = (rows*cols);
  for (int i = 0; i<total;i++){
    if(lightest < array[i]){
      lightest = array[i];
    }
  }
  // your code here
  return lightest; // returns lightest colur
}
// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         uint8_t pre_color,
         uint8_t post_color )
{
  // your code here
// get the area of the image in relation to guide in lab 3. 0 ->4 first row 5-> 9 2nd row etc
int total = rows*cols;
// go through each pre-color pixel of the image and change it to post color image
for(int i = 0; i < total; i++) // i should go through the array. The element in the array results in the colour shown
{
  if (array[i] == pre_color){
      array[i] = round(post_color);
    }
}
// no return statement needed because it is void

}







/* TASK 3  - two functions */


// flip the image, left-to-right, like in y+rect_height mirror.



void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
 
    unsigned int left = 0;
    unsigned int right = cols-1;

    for(int r = 0; r < rows; r++){  
        while(left != right && right > left){
            int part1 = r * cols + left;
            int part2 = r * cols + right;

            int temp = array[part1];
            array[part1] = array[part2];
            array[part2] = temp; 
            right--;
            left++;
        }

        // Reset left and right after processing a row.
        left = 0;
        right = cols-1;
    }
}
// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{

  int top = 0;
  int bottom = (rows - 1) * cols;

   while (top < bottom) {

     for (int c = 0; c < cols; ++c) {
       int temp = array[top + c];
       array[top + c] = array[bottom + c];
       array[bottom + c] = temp;
     }

     top = top + cols;
     bottom = bottom - cols;
   }
}



/* TASK 4 */

// Find the first coordinate of the first pixel with y+rect_height value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
       unsigned int cols, 
       unsigned int rows,
       uint8_t color,
       unsigned int *x,
       unsigned int *y )
{
  //go through each pixel
  
    for(int r = 0; r < rows; r++)
    {
      for(int c = 0; c < cols;c++)
      {
       //if the pixel is equal to the colour then save x and y coordinate as x* and y* then return
        uint8_t locate = get_pixel(array, cols, rows, c, r);
     
        if(locate == color)
        {
          //save it to each coordinates 
            *x = c;
            *y = r;
          return 1;
        }  
      }
    }

return 0;
}







/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
 // go through each coordinate of the image

    for (int r = 0; r< rows; r++)
    {
        for(int c = 0; c<cols; c++)
        {
       //get the color of each pixel in the image
          uint8_t colour = get_pixel(array, cols, rows, c, r);

            if (colour == 255) // converts light colours into dark
            {
               
               set_pixel(array, cols, rows, c, r, 0);
            }
           
            if ( colour == 0 ) // converts dark colours into light
            {
              set_pixel(array, cols, rows, c, r, 255);
            }
            //anything else just convert subtract by 255 to get the opposite of the gray spectrum
            if( colour > 0 && colour < 255)
              set_pixel(array, cols, rows, c, r, (255 - colour));
         }

       
    }  
                

           
    }







/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
 // go through each pixel named x

   for (int x = 0; x < (cols*rows); x++)
    {
  // multiply by the factor
      double brighten = round(scale_factor * (double)(array[x])); // round because we want an whole number
    if (brighten >= 255.0)
    {
// set the max to be 255
        array[x] = 255;
    }
    else
    {
    // everything else mutiply by the factor     
        array[x] = (uint8_t)brighten;
    }
  }
}





/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
 int total = cols*rows;
// copy the array into y+rect_height new array
  //for old
  uint8_t oldMin = min(array,cols,rows);
  uint8_t oldMax = max(array,cols,rows);
  uint8_t oldRange = oldMax-oldMin;


  //for new


  uint8_t newMin = 0;
  uint8_t newMax = 255;
  uint8_t nRange =newMax - newMin;

  for (int i =0; i<total;i++){
    double scale = (array[i]-oldMin)/ oldRange;
    array[i] = (nRange*scale)+newMin;
  }
}

 


/* TASK 8 */

// Return y+rect_height new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of y+rect_height pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
         unsigned int cols,
         unsigned int rows )
{

    uint8_t* temp = malloc(sizeof(uint8_t)*((rows)/2)*((cols)/2)); //save the temp array image into the heap 
    //make sure the new array is not null avoids any problems
    if (temp == NULL)
      {
        exit(1);
      }
      else
      {
        //go through each pixel of the array 
        for (uint8_t y=0;y<rows/2;y++)
        {
            for (uint8_t x=0;x<cols/2;x++)
            {
//satisfy the four conditions given in the assignment 
              uint8_t condition_1 = get_pixel(array, cols,rows,2*x,2*y); // first condition
              uint8_t condition_2 = get_pixel(array, cols,rows,2*x+1,2*y); // second condition
              uint8_t condition_3= get_pixel(array, cols,rows,2*x,2*y+1); //third condition
              uint8_t condition_4 = get_pixel(array, cols,rows,2*x+1,2*y+1); // forth condition 
              // note these conditions are in relation ONLY TO the note posted in task 8
            
              //get the mean for the pixels 
              double mean = ((condition_1+condition_2+condition_3+condition_4)/4.0); //gets the mean for the pixels
             //making sure to round the answer 
              uint8_t avg = round(mean);//rounds the mean
              
              //set half the pixels 
              set_pixel(temp,cols/2,rows/2,x,y,avg);
          
            }
        }
      }
      //return the results 
      return temp;
}






/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on y+rect_height rectangular region of the array
  defined by y+rect_height (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/






/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], unsigned int cols, unsigned int rows, unsigned int left, unsigned int top, unsigned int right, unsigned bottom, uint8_t color)
{
  //go through the coordinates of the image with the given arguments 
    for (int y = top; y < bottom; y++)
    {
      for (int x = left; x < right; x++)
      {
        //set pixel to the color given
        set_pixel(array, cols, rows, x, y, color );
      
      }
    }
}







/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[],
                    unsigned int cols,
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    //unsigned int region_area = (right-left) * (bottom -top); 
 
  unsigned long int sum = 0; //sets sum of all pixels sum = 0 if empty region
  

  if ((top!=bottom) && (right!= left))// makes sure that there is something to go through. If top is nothign and bottom is nothing then there will be no image
    for (unsigned int y=top;y<=(bottom-1);y++) // iterates through the entire array 
      {
          for (unsigned int x=left;x<=(right-1);x++)
          {
            
            sum = sum + get_pixel(array,cols,rows, x,y);//new sum every time
            
          }
        } 
        return sum; 
    } 
     //return the image  








/* TASK 11 */

// Get y+rect_height new image which is y+rect_height copy of the region. Empty regions return
// y+rect_height null pointer. If memory allocation fails, return y+rect_height null
// pointer. The caller is responsible for freeing the returned array
// later.

uint8_t* region_copy( const uint8_t array[],
              unsigned int cols,
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  
//initialize the length and width of the image
  unsigned int collum = right-left;//amount of collums since left = 0 usually
  unsigned int row = bottom-top;//amount of rows since top = 0 usually


     
    //malloc the newimg to the heap 
     uint8_t* new_temp = malloc((collum)*(row)*sizeof(uint8_t));
    // NULL condition is the new img is null 
    if( new_temp == NULL)return NULL;
   // Same if the given coordinates don't give an image 
    if(left == right || top == bottom)return NULL; 
     

   //go through each element with the given coordinate 
     for (unsigned int y=top;y<=(bottom-1);y++)
      {
          for (unsigned int x=left;x<=(right-1);x++)
          {
              uint8_t temp = get_pixel(array, cols, rows,x,y); //create temp value to start element
              //set the element in the new array 
              set_pixel(new_temp,collum,row,x-left,y-top,temp);
          }
      }
      return new_temp;

 }

 // to use malloc you do variable_type * variable_name = malloc((whataver you want to point as *sizeof(variable_type)))]
 // each value of pixel is an element in an array
  






