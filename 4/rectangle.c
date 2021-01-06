

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




//check if in width

int in_width(int b, int x, int rect_width, int cols, int rows)
{
   if(b > 0 && b<cols)            {return 2; } //x+rect_width; 
   else  if(b > cols)             {return 1 ;     } //cols-1;
   else                           {return 0;            } 
   
}

// check if in height
int in_height(int a, int y, int rect_height, int cols, int rows)
{

   if(a>0 && a<rows)          {return 1;}  // y+rect_height;
   else if(a < 0)             {return 0;} 
   else                       {return 2;} //rows-1
   
}  
//check if x in image

int x_image(int x, int cols)
{
  if(x > 0 && x < cols)       {return 1;} //*x
  else if(x < 0 )                  {return 0; }
  else           {return 2; } //*cols-1; 

}

//check if y in image
int y_image(int y,int rows)
{
  if(y > rows)                 {return 2 ;}  
  else if(y > 0 && y < rows)        {return 1;} 
  else               {return 0;} 
    
}



  void draw_rectangle( uint8_t array[],  unsigned int cols, unsigned int rows,  int x,int y,int rect_width, int rect_height, uint8_t color )


{      
 

//making sure that my buffer conditions are satisfied 
int c,d, ybuffer, xbuffer;
int a = y+rect_height;
int b = x+rect_width;
 
if(y_image(y,rows) == 1){ ybuffer = y;}
if(y_image(y,rows) == 2){ ybuffer = rows-1; }
if(y_image(y,rows) == 0){ ybuffer = 0;    }

if(x_image(x,cols) == 1){ xbuffer = x; }
if(x_image(x,cols) == 2){ xbuffer = cols-1;}
if(x_image(x,cols) == 0){ xbuffer = 0; }



if(in_height(a, y, rect_height, cols, rows) == 1){c = y+rect_height;}
if(in_height(a, y, rect_height, cols, rows) == 2){c = rows -1;}
if(in_height(a, y, rect_height, cols, rows) == 0){c = 0;}

if(in_width(b, x, rect_width, cols, rows) == 1){ d = cols-1;}
if(in_width(b, x, rect_width, cols, rows) == 2){ d = x+rect_width;}
if(in_width(b, x, rect_width, cols, rows) == 0){ d= 0; }



  //making sure the rect_width and rect_height is in image 
  if((x >= cols && x + rect_width > cols) || (x <= 0 && x + rect_width < 0) || ( y>= rows && y+rect_height >= rows) || (y <= 0 && y+rect_height < 0 )){exit(0);}

  

   


//case 1 when rect_width > 0 and rect_height >0

             if(rect_width > 0 && rect_height > 0)
             {

                for(int row = ybuffer; row < c; row++)
               {
            
                  for(int col = xbuffer; col < d; col++)
                  {  
                                                 
                       if( col == x ||  col == x+rect_width-1 || row == y+rect_height-1 || row == y) 
                  
                        set_pixel(array, cols, rows, col, row, color); 
                     
                   }
                }
              }  
  //case 2 when rect_width is less than 0 and rect_height > 0            
            
             if(rect_width < 0 && rect_height >0)
             {
                for(int row = ybuffer; row < c; row++)
                {
                  for(int col = xbuffer; col < d ; col++)
                  {      

                    if( col == x || col == x+rect_width+1 || row == y+rect_height-1 || row == y) 
                    
                     set_pixel(array, cols, rows, col, row, color); 
                  }
                }
            }
             
         
//case 3 when rect_height is less than 0 and rect_width is greater than 0 
             if(rect_height < 0  && rect_width >0)
             {
                for(int row = ybuffer; row > c; row--)
                {

                    for(int col = xbuffer; col < d; col++)
                    {
                      
                        
                      if( col == x || col == x+rect_width-1 || row == y+rect_height+1 || row == y) 
                 
                        set_pixel(array, cols, rows, col, row, color); 
                    }
                }
             
             } 
    //case 4 when rect_height is < 0 and rect_width is less than 0

              if(rect_height<0 && rect_width<0)
                {
                    
                  for(int row = ybuffer; row > c; row--)
                  {

                    for(int col = xbuffer; col > d; col--)
                    {
                   
                       if(col== x || col == x+rect_width+1 || row == y+rect_height+1 || row == y ) 
                        set_pixel(array, cols, rows, col, row, color);
                    }
                  }
             

               }
      }   
