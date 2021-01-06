void point_array_init( point_array_t* pa ){
	pa->reserve = 0;

	pa->len = 0;
	pa->points  = malloc(sizeof(point_t));

	pa->points = NULL;
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.


void point_array_reset( point_array_t* pa ){
	free(pa->points);
	pa->reserve = 0;
	pa->len = 0;
}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){

	if (pa ==NULL || p == NULL){
		return 1;
	}

	if (pa->len != 0){
		pa -> points = realloc(pa->points, sizeof(point_t)* (pa->len +1 )) // realloc(what you want to realloc, sizeof node * new size)
		
		pa->points[pa->len].x =p->x;
		pa->points[pa->len].y = p->y;
		pa->points[pa->len].z = p->z;
		pa->len = pa->len + 1;

		
	}
	else{

		pa->len = 1;
		pa->points = realloc(pa->points,sizeof(point_t)* 2);
		pa->points[1].x = p->x;
		pa->points[1].y = p->y;
		pa->points[1].z = p->z;
	}
	if(pa -> reserved == pa -> len){
		pa -> reserved = pa -> reserved * 2; // reserve double the space
		pa -> points = realloc(pa -> points, sizeof(point_t)*pa->reserved); // give a lot more space.
	}	
	return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1; 
int point_array_remove( point_array_t* pa, unsigned int i ){

	if (i >= pa -> len || pa -> len == 0){
		return 1;
	}
	//swap index i with last element then get rid of last element

	pa -> points[i].x = pa -> points[pa -> len - 1].x;
	pa -> points[i].y = pa -> points[pa -> len - 1].y;
	
	pa -> points[i].z = pa -> points[pa -> len - 1].z;
	
	pa -> points[pa->len-1].x = 0;
	
	pa -> points[pa->len-1].y = 0;
	pa -> points[pa->len-1].z = 0;
	
	pa -> len = pa -> len - 1;

	return 0;
}