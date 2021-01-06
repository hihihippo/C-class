#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename )
{
	
	
    // make sure filename or IA are not null	
	if (filename == NULL || ia == NULL)
	{
     return 1; 
	}	

     else if( ia != NULL)
     {
		FILE * file_a = fopen(filename, "w+"); // opens another file
		
		fprintf(file_a, "[");
			
		//set the elements in the array to 0
		int elementInArray = 0;
		
		while (elementInArray < ia -> len)
		{
		   //print the numbers in the file 		
			fprintf(file_a, "%d", ia -> data[elementInArray]);
             
            //print the commas in the array until len -1 
			if (elementInArray != ia -> len - 1)
			{
				fprintf(file_a, ",");
					
			}
			//go to the next element 
		  elementInArray++;
		}
		//end the process with a closed bracket 	
		fprintf(file_a, "]");
		//close the file and return 0
		fclose(file_a);
		return 0;
	}
	return 1;
	
	
}			

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{
	char ch;
	int buff;
	int total; // counts commas
	
	if (filename == NULL)
	{
	  return NULL; 
	}	
		
	else
	{	
		// need file to be open
		FILE * file = fopen (filename, "r+");
				
		if (file != NULL)
		{
			total = 0;

			intarr_t *arr = malloc(sizeof(intarr_t));
			
			//go through the file to get each array elements 
			while (!feof(file)) // open file possible
			{
		          
				ch = getc(file); //type file characters into ch
				//this counts the number of commas in the array 
				if (ch == ',')
				{
					total++;
				}
			}
			
			

             //go through the file 
			fseek(file,0,SEEK_SET);
			

			if (total == 0)
			{
				//if there are no commas then the length is zero and the data is null 
				arr->len = 0;
				arr->data = NULL;
				return arr;
			}
			

			else
			{
				// array length is commas +1
				arr->len = total + 1;
				//allocate the data arr
				arr->data = malloc(sizeof(int)*arr->len);
			}
          
   
             //go through the array's elements 
			for (int i = 0; i < arr->len; i++)
			{
				while (fscanf(file, "%d", &buff) != 1) // as long as you can scan number/buffer then go through
				{
					fseek(file,1,SEEK_CUR);
				}
				arr->data[i] = buff;
			}
			
			fseek(file,0,SEEK_END);
			fclose(file);
			return arr;
		}
	}
		

}
			 
