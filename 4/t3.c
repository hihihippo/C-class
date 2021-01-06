 #include <stdint.h> 

void life(     uint8_t array[], 
  
             unsigned int cols, 
             unsigned int rows )
{



uint8_t *cp = copy(array, cols, rows); 


//go through the coordinates of the image

for (int y = 0; y < rows; y++) 
{
   for (int x = 0; x < cols; x++) 
  {
  //initialize where the pixel is going and the number around the pixel 
    int neighbors  = 0; 
    int horizontal = x-1; 
    int horizont   = x+1;

    int vertical  = y+1; 
    int vertic    = y-1; 
//this is the wrapping around statement 
    if( horizontal < 0 ){   horizontal  = cols-1;} 
    if( horizont > cols-1 ){ horizont    = 0;}  
    if( vertic < 0 ) {      vertic      = rows-1;}
    if( vertical > rows-1 ){vertical    = 0;  }
    
    //get the neighbours of x and y
           uint8_t top_1 = get_pixel(cp, cols, rows, horizontal, vertical);
           uint8_t top_2 = get_pixel(cp, cols, rows, x,          vertical);
           uint8_t top_3 = get_pixel(cp, cols, rows, horizont,   vertical);
           
           uint8_t mid_1 = get_pixel(cp, cols, rows, horizontal, y);
           uint8_t mid_2 = get_pixel(cp, cols, rows, x,          y);
           uint8_t mid_3 = get_pixel(cp, cols, rows, horizont,  y);
           
           uint8_t bot_1 = get_pixel(cp, cols, rows, horizontal, vertic);
           uint8_t bot_2 = get_pixel(cp, cols, rows, x,         vertic);
           uint8_t bot_3 = get_pixel(cp, cols, rows, horizont, vertic);

          //Top
          if (top_1 > 0) neighbors++;
          if (top_2 > 0) neighbors++;
          if (top_3 > 0) neighbors++;

          //Middle 
          if (mid_1 > 0) neighbors++;
          if (mid_3 > 0) neighbors++;
           
          //Bottom row of neighbors
          if (bot_1 > 0) neighbors++;
          if (bot_2 > 0) neighbors++;
          if (bot_3 > 0) neighbors++;
            
        //this is to print the new pixel if it meets the conditions for game of life 
          if ((mid_2 > 0 ) && (neighbors <  2))   set_pixel(array, cols, rows, x, y , 0 );
          if ((mid_2 > 0 ) && (neighbors >  3))   set_pixel(array, cols, rows, x, y ,  0 );
          if ((mid_2 == 0) && (neighbors == 3))   set_pixel(array, cols, rows, x, y , 255);
           
    
             
    }
              
             
}
           

}
