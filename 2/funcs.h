// returns the larger of the two arguments
int max( int x, int y)
{
  int larger = y;
  if( x > y ) 
  {
    larger = x;
  } 
  return larger;
}

// returns the smaller of the two arguments
int min( int x, int y)
{
  int smaller = y;
  if( x < y ) 
  {
    smaller = x;
  } 
  return smaller;
}
