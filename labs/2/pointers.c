
#include <stdio.h>

int main(){
	int x, y, *px, *py;
	int arr[10];

	x = 2;
	y = 10;
	arr[0] = 8;


	printf("%d\n",x); //prints value of x
	printf("%d\n",y); //prints value of y
	printf("%p\n",&x); //prints address of x
	printf("%p\n",&y); //prints address of y
	
  
  px = &x; //points to address of x
  py = &y; //points to address of y
  printf("%p\n",px); //prints pointer px
  printf("%p\n",py); //prints pointer py
  printf("%p\n",&px); //prints address of px
  printf("%p\n",&py); //prints address of py

  printf("%d\n",arr[0]); //prints value at arr[0]
  printf("%p\n",&arr[0]); //prints address at arr[0]

  printf("\n");
  
  int i = 0;
  while (i < 10){         
    printf("%p\n",arr);
    i++;
  }

	return 0;
}