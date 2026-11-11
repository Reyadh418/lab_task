/*
 * E11.2: Correctly parenthesised parameterized macros used inside larger expressions.
 * Follows Lab 11 §1.5, Worked Example 11.3, & E11.2
 */
#include <stdio.h>

// Parentheses around every parameter AND around the entire body
#define SQUARE(x)       ((x) * (x))
#define MAX2(a, b)      (((a) > (b)) ? (a) : (b))

int main(void) {
    // Replace 1234 with digits 4-7 of your Student ID (N)
    int N = 1234;
    int rem = N % 97;

    printf("Student ID N = %d, N %% 97 = %d\n\n", N, rem);

    // Using SQUARE inside a larger expression with compound argument
    // If SQUARE lacked parameter parentheses: rem + 1 * rem + 1
    // If SQUARE lacked body parentheses: 1000 / (rem + 1) * (rem + 1)
    // With tight parentheses: 1000 / ((rem + 1) * (rem + 1))
    int sq_calc = 1000 / SQUARE(rem + 1);
    printf("Expression 1: 1000 / SQUARE(%d + 1) = %d\n", rem, sq_calc);

    // Using MAX2 inside a larger expression with compound arguments
    // Tests operator precedence with multiplication and addition outside & inside
    int max_calc = 10 + 2 * MAX2(N - 100, rem * 20);
    printf("Expression 2: 10 + 2 * MAX2(%d - 100, %d * 20) = %d\n", N, rem, max_calc);

    return 0;
}
