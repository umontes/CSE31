#include <stdio.h>

int main(void) {
    
    int num;
    
    int ave_pos = 0;
    int ave_neg = 0;
    //int pos_tot = 0;
    //int neg_tot = 0;
    int pos = 0;
    int neg = 0;
    
    int i = 1;
    
    while (i != 0){
        printf("Please enter an integer: ");
        scanf("%d", &num);
        
        if (num > 0){
            pos = pos + num;
            ave_pos++;
        }
        if (num < 0){
            neg = neg + num;
            ave_neg++;
        }
        if (num == 0){
            i = num;
        }
    }
    
    if (ave_pos > 0){
        ave_pos = (pos / ave_pos);
        printf("Positive average: %d\n", ave_pos);
    }
    if (ave_neg > 0){
        ave_neg = (neg / ave_neg);
        printf("Negative average: %d", ave_neg);
    }
}





