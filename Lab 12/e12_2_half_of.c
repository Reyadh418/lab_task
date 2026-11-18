/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Easy Exercise 2 (E12.2): Hand one result back
 * 
 * Task Description:
 * Write void half_of(double x, double *resultp) which puts half of x 
 * into the caller's variable.
 * Call it twice from main, with your N and with 7.0, and print both answers.
 * main must not do the division.
 */

#include <stdio.h>

/* Function prototype with output parameter */
void half_of(double x, double *resultp);

int main(void)
{
    /* N is digits 4 to 7 of your student ID (e.g., 1234.0) */
    double n = 1234.0;
    double ans_n = 0.0;
    double ans_seven = 0.0;

    printf("=== Lab 12 Task E12.2: Hand One Result Back ===\n");

    /* First call: passing N */
    half_of(n, &ans_n);
    printf("half_of(%.2f) = %.2f\n", n, ans_n);

    /* Second call: passing 7.0 */
    half_of(7.0, &ans_seven);
    printf("half_of(7.00) = %.2f\n", ans_seven);

    return 0;
}

/* Function definition: stores half of x into caller's variable via pointer */
void half_of(double x, double *resultp)
{
    *resultp = x / 2.0;
}
