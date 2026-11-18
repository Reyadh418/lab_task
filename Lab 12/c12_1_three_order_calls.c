/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Challenging Exercise 1 (C12.1): Three calls, and the one that does nothing
 * 
 * Task Description:
 * Write void order(double *smp, double *lgp) which swaps the two numbers
 * it is given only if the first is the larger (*smp > *lgp).
 * Then, from main, with n1 = 7.5, n2 = 9.6, n3 = 5.5, call it three times:
 *   Call 1: order(&n1, &n2)
 *   Call 2: order(&n1, &n3)
 *   Call 3: order(&n2, &n3)
 * printing all three values after each call.
 *
 * Analysis:
 * - Call 1 (order(&n1, &n2)): compares 7.5 and 9.6. Since 7.5 <= 9.6, NO swap occurs.
 *   This is the call that changes nothing!
 * - Call 2 (order(&n1, &n3)): compares 7.5 and 5.5. 7.5 > 5.5 -> Swapped!
 *   n1 becomes 5.5, n3 becomes 7.5.
 * - Call 3 (order(&n2, &n3)): compares 9.6 and 7.5. 9.6 > 7.5 -> Swapped!
 *   n2 becomes 7.5, n3 becomes 9.6.
 * Result:
 *   n1 = 5.50, n2 = 7.50, n3 = 9.60.
 *   Achieves a 3-element ascending sort (sorting network).
 */

#include <stdio.h>

/* Function prototype */
void order(double *smp, double *lgp);

int main(void)
{
    double n1 = 7.5, n2 = 9.6, n3 = 5.5;

    printf("=== Lab 12 Task C12.1: Three Calls to order() ===\n");
    printf("Initial values: n1 = %.2f, n2 = %.2f, n3 = %.2f\n\n", n1, n2, n3);

    /* Call 1: (&n1, &n2) */
    order(&n1, &n2);
    printf("After Call 1 - order(&n1, &n2):\n");
    printf("  n1 = %.2f, n2 = %.2f, n3 = %.2f  [NO CHANGE: 7.5 <= 9.6]\n\n", n1, n2, n3);

    /* Call 2: (&n1, &n3) */
    order(&n1, &n3);
    printf("After Call 2 - order(&n1, &n3):\n");
    printf("  n1 = %.2f, n2 = %.2f, n3 = %.2f  [SWAPPED: 7.5 > 5.5]\n\n", n1, n2, n3);

    /* Call 3: (&n2, &n3) */
    order(&n2, &n3);
    printf("After Call 3 - order(&n2, &n3):\n");
    printf("  n1 = %.2f, n2 = %.2f, n3 = %.2f  [SWAPPED: 9.6 > 7.5]\n\n", n1, n2, n3);

    printf("Final sorted values: n1 = %.2f <= n2 = %.2f <= n3 = %.2f\n", n1, n2, n3);
    printf("Achievement: The sequence of three calls completely sorted the 3 numbers in ascending order.\n");

    return 0;
}

/* Function definition: swaps values only if *smp > *lgp */
void order(double *smp, double *lgp)
{
    if (*smp > *lgp)
    {
        double temp = *smp;
        *smp = *lgp;
        *lgp = temp;
    }
}
