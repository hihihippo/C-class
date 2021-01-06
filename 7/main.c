#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "list.h"

int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  list_t* l1=list_create();
  list_t* l2=list_create();
  element_t* n1=list_index(l1,1);
  if (n1!=NULL)     //t1
  {
    return 1;
  }

  for( int i=0; i<5; i++ )    
    list_append( list, i );
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
  list_print( list );

  list_prepend(l2,5);      //t4
  if(l2->tail->val!=5)
  {
    return 1;
  }
  //printf("1\n");

  int index = 2;
  int k = 0;//t3
  element_t* el = list_index( list, index );
  element_t* n3 = list_index( list, k );   //t3
  //printf("2\n");     
  element_t* n6 = list_index( list, 11);     //t6
  //printf("3\n");
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  if (n3->val!=-4)      //t3 check for list_index when index=0
  {
    return 1;
  }
  if (n6!=NULL)      // t6 check when index for list_index > than list
  {
    return 1;
  }
  printf( "value at index %d is %d\n", index, el->val );
  element_t *n2=element_create(5);      // t2
  free(n2); 
  element_t *nn2=element_create(2);
  printf("%d\n",n2->val);
  if (n2==nn2)
  {
    return 4;
  }
 
  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list );
  list_destroy( l1 );
  return 0; // tests pass
}
//frees memory using destroy of list
void list_destroy( list_t* list ){
	if (list->head == NULL){
		return;
	}
	
	else{
		while{
	 	(list->head != NULL || list->tail != NULL)
	{
		
		/*
		list->head == NULL;
		list->tail == NULL;
*/		

		while (
	}//if you get rid of the head and tail then the memory becomes loss. Memory allocation problem???

// returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create( int i ){
	if (list->head != NULL)
	{
		return NULL;
	}
	else
	{
		while (list->head != i && list->next != NULL)
		{
			list->head = list->next;
		}
	return list->head;


// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i ){
	list_t * newnode = malloc(sizeof(list_t));
	if (newnode != NULL){
		newnode->data = i;
		newnode->next = NULL;
	}
	if (list_t->tail == NULL){
		assert(list_t-> head == NULL);

		list_t->head = newnode;
		list_t -> tail = newnode;

	else{
 		list_t->tail->next = newnode;
		list_t ->tail = newnode;
		}
	}	
}



// Prepends a new element containing integer i to the head of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i );

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range (i.e. larger
// than (number of list elements -1 ))
element_t* list_index( list_t* list, unsigned int i );

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list );
  
  return 0; // tests pass
}
