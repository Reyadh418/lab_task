/*
 * E11.1: Smallest power of 2 that is greater than or equal to n.
 * Follows Lab 11, G11.1 & E11.1
 */
#include <stdio.h>

int main(void) {
    int n;
    int power = 1;

    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    // Multiply by 2 until power >= n
    while (power < n) {
        power *= 2;
    }

    printf("The smallest power of 2 >= %d is %d\n", n, power);

    return 0;
}
