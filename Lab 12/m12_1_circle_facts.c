/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Mediocre Exercise 1 (M12.1): Two results, one call
 * 
 * Task Description:
 * Write a function:
 *   void circle_facts(double r, double *areap, double *circump);
 * which fills in both the area and the circumference for radius r.
 * Use 3.14159 as a named constant.
 * Call it for r = 2.0 and for r = N / 1000.0, printing both results
 * to two decimal places.
 */

#include <stdio.h>

#define PI 3.14159

/* Function prototype: two output parameters returning area and circumference */
void circle_facts(double r, double *areap, double *circump);

int main(void)
{
    /* N is digits 4 to 7 of your student ID (e.g., 1234) */
    double n_val = 1234.0;
    double r1 = 2.0;
    double r2 = n_val / 1000.0; /* e.g., 1.234 */
    
    double area1 = 0.0, circum1 = 0.0;
    double area2 = 0.0, circum2 = 0.0;

    printf("=== Lab 12 Task M12.1: Circle Facts (Two Results, One Call) ===\n");

    /* First run: r = 2.0 */
    circle_facts(r1, &area1, &circum1);
    printf("Radius: %5.2f | Area: %7.2f | Circumference: %7.2f\n", r1, area1, circum1);

    /* Second run: r = N / 1000.0 */
    circle_facts(r2, &area2, &circum2);
    printf("Radius: %5.2f | Area: %7.2f | Circumference: %7.2f\n", r2, area2, circum2);

    return 0;
}

/* Function definition */
void circle_facts(double r, double *areap, double *circump)
{
    *areap = PI * r * r;
    *circump = 2.0 * PI * r;
}
