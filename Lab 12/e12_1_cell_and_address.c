/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Easy Exercise 1 (E12.1): A cell and its address
 * 
 * Task Description:
 * Declare an int holding your N (digits 4 to 7 of your student ID).
 * Print, on four labelled lines:
 *   1. Its value
 *   2. Its address with %p
 *   3. The value again through a pointer
 *   4. The address of the pointer itself
 * Then change the variable through the pointer only and print it again.
 */

#include <stdio.h>

int main(void)
{
    /* N is digits 4 to 7 of your student ID (e.g., ID 2411234 gives N = 1234) */
    int n = 1234;  /* Replace with your own 4-digit N if desired */
    int *p = &n;

    printf("=== Lab 12 Task E12.1: A Cell and Its Address ===\n");
    
    /* 1. Value of the variable */
    printf("1. Value of n                     : %d\n", n);

    /* 2. Address of the variable with %p and (void *) cast */
    printf("2. Address of n (&n)              : %p\n", (void *)&n);

    /* 3. Value of the variable reached through pointer (*p) */
    printf("3. Value through pointer (*p)     : %d\n", *p);

    /* 4. Address of the pointer variable itself (&p) */
    printf("4. Address of pointer itself (&p) : %p\n", (void *)&p);

    /* Change the variable through the pointer only */
    *p = 5678;

    /* Print the variable again to verify it changed */
    printf("\nAfter modifying via *p = 5678:\n");
    printf("Updated value of n                : %d\n", n);
    printf("Value verified through *p         : %d\n", *p);

    return 0;
}
