/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Mediocre Exercise 3 (M12.3): Validate, through a pointer
 * 
 * Task Description:
 * Write void read_positive(int *np) which keeps prompting until the user
 * types a number greater than zero, then puts it in the caller's variable.
 * Use a do-while loop (Lab 10's statement for input validation).
 */

#include <stdio.h>

/* Function prototype */
void read_positive(int *np);

int main(void)
{
    int positive_num = 0;

    printf("=== Lab 12 Task M12.3: Validate Through a Pointer ===\n");
    
    /* Call function with address of positive_num */
    read_positive(&positive_num);

    printf("\nSuccess! The caller's variable received: %d\n", positive_num);

    return 0;
}

/* Function definition using do-while validation loop */
void read_positive(int *np)
{
    int temp;
    do {
        printf("Enter a positive number (> 0): ");
        scanf("%d", &temp);
        if (temp <= 0) {
            printf("Invalid input! Value must be strictly greater than 0. Try again.\n");
        }
    } while (temp <= 0);

    /* Assign validated result to caller's variable through pointer */
    *np = temp;
}
