
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
//------------------------------------------------------
  int **matC = (int**)malloc(size * sizeof(int*));
  int i, j, k;

  for(i=0; i<size; i++){
    *(matC+i) = (int*)malloc(size * sizeof(int));

    for(j=0; j<size; j++){
      *(*(matC+i)+j) = 0;

      for(k=0; k<size; k++){
        //*(*(matC+i)+j) = *(*(a+i)+k) * (*(*(b+k)+j));
        *(*(matC+i)+j) = *(*(matC+i)+j) + *(*(a+i)+k) * (*(*(b+k)+j));
      }
    }
  }
return matC;
//------------------------------------------------------
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
//------------------------------------------------------
  int i, j = 0;
  int **matD = arr;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
    printf("%d ", *(*(matD+i)+j));
    }
printf("\n");
}
//------------------------------------------------------
}

int main() {
	int n = 5;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
//------------------------------------------------------
  int i, j;

  matA = (int**)malloc(n * sizeof(int*));
  matB = (int**)malloc(n * sizeof(int*));
  matC = (int**)malloc(n * sizeof(int*));

for(i=0; i<n; i++){
  *(matA+i) = (int*)malloc(n * sizeof(int));
  for(j=0; j<n; j++){
    *(*(matA+i)+j) = i+j;
  }
}
for(i=0; i<n; i++){
  *(matB+i) = (int*)malloc(n * sizeof(int));
  for(j=0; j<n; j++){
    *(*(matB+i)+j) = i+j;
  }
}
for(i=0; i<n; i++){
  *(matC+i) = (int*)malloc(n * sizeof(int));
  for(j=0; j<n; j++){
    *(*(matC+i)+j) = 1;
  }
}
//------------------------------------------------------

	// (3) Call printArray to print out the 2 arrays here.
//------------------------------------------------------
  printf("Array 1: \n");
  printArray(matA, n);
  printf("Array 2: \n");
  printArray(matB, n);
//------------------------------------------------------
	
	//(5) Call matMult to multiply the 2 arrays here.
//------------------------------------------------------
  matC = matMult(matA, matB, n);
//------------------------------------------------------
	
	//(6) Call printArray to print out resulting array here.
//------------------------------------------------------
  printf("Array 3: \n");
  printArray(matC, n);
//-----------------------------------------------------
    return 0;
}
