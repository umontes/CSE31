#include <stdio.h>

int main(void) {
    
    int num;
    int typo;
    
    printf("Enter the number of lines for the punishment: ");
    scanf("%d", &num);
    
    if (num <= 0){
        printf("You enter an incorrect value for the number of lines!");
        return 0;
    }
    
    printf("Enter the line for which we want to make a typo: ");
    scanf("%d", &typo);
    
    if (typo > num || typo <= 0) {
        printf("You entered an incorrect value for the line typo!");
        return 0;
    }
    
    int i = 1;
    
    while (i <= num){
        if (i == typo){
            printf("C programming is the bet!\n");
        }
        else {
            printf("C programming is the best!\n");
        }
        i++;
    }
}
