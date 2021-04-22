
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert extra code here
//------------------------------------------------------------------

  printf("%d\n",num); //content of num
  printf("%p\n",&num); //address of num
  printf("\n");

  printf("%p\n",ptr); //content of ptr 
  printf("%p\n",&ptr); //address of ptr
  printf("\n");

  printf("%p\n",handle); //content of handle
  printf("%p\n",&handle); //address of handle

//------------------------------------------------------------------
  

	return 0;
} 

