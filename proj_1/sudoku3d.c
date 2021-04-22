#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function
int solveSudoku(int***);

//Helper functions. You can define any functions that can help your solve the problem
//------------------------------------------------------------------------------

int row(int*** blocks,int a, int k, int num){
	
	int i, j;

	if(a <= 2){
		a = 0;
		for(i = a; i <= 2; i++){
			for(j = 0; j <= 2; j++){
				if( *(*(*(blocks+i)+k)+j) == num){
					return 1;
				}
			}
		}
	}
	if(a >= 3 && a <= 5){
		a = 3;
		for(i = a; i <= 5; i++){
			for(j = 0; j < 3; j++){
				if( *(*(*(blocks+i)+k)+j) == num){
					return 1;
				}
			}
		}
	} 
	if(a >= 6 && a <= 8){
		a = 6; 
		for(i = a; i <= 8; i++){
			for(j = 0; j < 3; j++){
				if( *(*(*(blocks+i)+k)+j) == num){
					return 1;
				}
			}
		}
	}
	return 0;
}

int col(int*** blocks, int i, int j, int num){
	int k;
    if(i % 3 == 0){
        i = 0;
    }
    else if(i % 3 == 1){
        i = 1;
    }
    else{
        i = 2;
    }
        
    for(i = i; i < 9; i+=3){
        for(k = 0; k < 3; k++){
            if( (*(*(*(blocks+i)+k)+j)) == num){
              return 1;
            }
        }
    }
    return 0;
}

int block(int*** blocks, int i, int num){
    for(int k = 0; k< 3; k++){
        for(int j = 0; j<3; j++){
            if( *(*(*(blocks+i)+k)+j) == num  ){
                return 1;
            }
        }
    }
    return 0;
}

int legal(int*** blocks, int i, int k, int j, int num){
	if( row(blocks, i, k, num) == 0 && col(blocks, i, j, num) == 0 && block(blocks, i, num) == 0 ){
		return 1;
	}
	else{
		return 0;
	}
}

//------------------------------------------------------------------------------


/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    int ***blocks = (int***)malloc(9 * sizeof(int**));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open File!\n");
        return 0;
    }

	// Read 9x9 blocks into 2D arrays
    for(i=0; i<9; i++)
    {
        *(blocks+i) = (int**)malloc(3 * sizeof(int*));
        printf("Reading numbers in block %d... \n", i+1);
        for(j=0; j<3; j++)
        {
            *(*(blocks+i)+j) = (int*)malloc(3 * sizeof(int));

                fscanf(fptr, "%d %d %d", *(*(blocks+i)+j), *(*(blocks+i)+j)+1, *(*(blocks+i)+j)+2);
                printf("%d %d %d\n", *(*(*(blocks+i)+j)), *(*(*(blocks+i)+j)+1), *(*(*(blocks+i)+j)+2));
        }
    }
	
	// Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);


	// Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if(solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}


void printSudoku(int*** arr){
	// This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions. 	
	
	// Your implementation here
//------------------------------------------------------------------------------
  
  int i, j = 0;
  int line = 0;
  
  for(i = 0; i < 9; i++){
      for(j = 0; j < 3; j++){
          printf("%d %d %d |", *(*(*(arr+i)+j)), *(*(*(arr+i)+j)+1), *(*(*(arr+i)+j)+2) );
          printf("%d %d %d |", *(*(*(arr+i+1)+j)), *(*(*(arr+i+1)+j)+1), *(*(*(arr+i+1)+j)+2) );
          printf("%d %d %d |", *(*(*(arr+i+2)+j)), *(*(*(arr+i+2)+j)+1), *(*(*(arr+i+2)+j)+2) );
          printf("\n");
      }
      if(line != 2){
          printf("---------------------\n");
          line++;
      }
      i = i+2;
  }  
}
//------------------------------------------------------------------------------



int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
	// YOU MUST NOT USE ANY ARRAY NOTATION ([])!
	
	//Your implementation here
//------------------------------------------------------------------------------

	for(int i = 0; i < 9; i++){
		for(int j = 0; j <3; j++){
			for(int k = 0; k <3; k++){							// goes to each square(number)
				if( (*(*(*(blocks+i)+j)+k)) == 0 ){
					for(int num = 1; num <= 9; num++){
						if(legal(blocks, i, j, k, num) ){
							(*(*(*(blocks+i)+j)+k)) = num;
							if(solveSudoku(blocks)){			// if the number isnt the same as those in its col, row, or block then true
								return 1;
							}
						}
					}
					(*(*(*(blocks+i)+j)+k)) = 0;
					return 0;				// otherwise its sets to 0 again and returns false
				}
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------





/*
1.	- define the columns and the rows to be able to compare later
    - If the number is the same as a number in the block, column, or row, then it adds 1.

2.  - If the number is still the same then it goes back and changes it.

3.	- If the number cannot solve the row or column or block then it goes back to change the previous number


*/

