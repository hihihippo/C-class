#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "intarr.h"


/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename )
{
	//making sure the filename is not null  
	if (filename == NULL)
	{
     return 1; 
    }		
   
    else
    {
        
		if (ia != NULL)
		{ // need to write file if not NULL
			FILE *file = fopen(filename, "w");
	        //write the data until len 
			if (fwrite(ia -> data, sizeof(int), ia -> len, file) == ia -> len)
			{
		     
				fclose(file);//fclose (file ) closes the file and return 0
				return 0;
			}	
			else
			{
				//emergency file close to ensure no corrution or file is possible
				fclose(file);
				return 1;
			}
		}
		return 1; 
	}
    	
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename )
{	
	
	if (filename == NULL)
	{
     return NULL; 
    } 
    
    else
    {
    	 
		FILE *file = fopen(filename, "r"); // fopen (filename,"r") opens filename in read mode
	
		if (file != NULL)
		{ 
		  	
			fseek(file,0,SEEK_END);
			//get the length of the array
			int arr = ftell(file)/sizeof(int);
			
            //set the file pointer to 0
			fseek(file,0,SEEK_SET);
			
			//allocate array
			intarr_t *array = malloc(sizeof(intarr_t));

			array -> len = arr;
			//malloc the data of the array 
			array -> data = malloc(sizeof(int)*array->len);
			
			if ((fread(array -> data, sizeof(int), arr, file)) != array -> len)
			{
				
				fclose(file);
			}
			else
			{
				fclose(file);
				return array;
			}
		
		}
	}
	

}
