#include <stdio.h>
#include <stdlib.h>


int InRectangle( float pt[2], float rect[4] )
{
  
  {
    
    //all the different combination to check whether the point in inside the rectangle or not 
   
   if (rect[1]>rect[3] && rect[0]<rect[2] )
    {
      // first condition 
      if (pt[0]>=rect[0] && pt[0]<=rect[2] && pt[1]>=rect[3] && pt[1]<=rect[1])
      {
      
        return 1;
      }
      else
      {
        return 0;
      }
    
    }


    // second condition
   if (rect[0]<rect[2] && rect[1]<rect[3])
    {
      if (pt[1]<=rect[3] && pt[0]<=rect[2] && pt[1]>=rect[1] && pt[0]>=rect[0])
      {

        return 1;
      }
      else
      {
        return 0;
      }
    }
        
     //third condition
    if (rect[1]<rect[3] && rect[2]<rect[0])
    {
      if (pt[0]>=rect[2] && pt[1]<=rect[3] && pt[1]>=rect[1] && pt[0]<=rect[0])
      {

        return 1;
      }
      else
      {
        return 0;
      }
    }
        

    //fourth condition
    if (rect[2]<rect[0] && rect[1]>rect[3])
    {
      if (pt[0]>=rect[2] && pt[0]<=rect[0] && pt[1]>=rect[3] && pt[1]<=rect[1])
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    
    
  }
}