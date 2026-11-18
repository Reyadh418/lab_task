/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Mediocre Exercise 2 (M12.2): The function that changes nothing
 * 
 * Problem:
 * The original program was:
 *   void add_bonus(double mark) { mark = mark + 5.0; }
 *   ...
 *   double mark = 71.0;
 *   add_bonus(mark);
 *   printf("%.1f\n", mark); // Prints 71.0 (silent logic defect!)
 *
 * Why the compiler had nothing to complain about:
 * The function add_bonus took mark by value, making a separate copy in its
 * own local data area, and adding 5.0 to that local copy is completely valid C syntax.
 * The compiler has no way to know the programmer intended to alter the caller's variable.
 *
 * Fix: Use an output parameter (pass by address).
 */

#include <stdio.h>

/* Corrected prototype with an output parameter */
void add_bonus(double *markp);

int main(void)
{
    double mark = 71.0;

    printf("=== Lab 12 Task M12.2: Repaired add_bonus ===\n");
    printf("Initial mark before bonus : %.1f\n", mark);

    /* Pass the address of mark so the function can modify main's variable */
    add_bonus(&mark);

    printf("Mark after add_bonus(&mark): %.1f\n", mark); /* prints 76.0 */

    return 0;
}

/* Corrected function definition using pointer indirection */
void add_bonus(double *markp)
{
    *markp = *markp + 5.0;
}
