/*
 * M11.1: Trace it, fix it, clean it with conditional compilation.
 * Follows Lab 11 Worked Example 11.2 & M11.1
 *
 * To see trace lines: leave '#define DEBUG' active.
 * To turn off trace lines: comment out '//#define DEBUG'.
 */
#include <stdio.h>

// Comment or uncomment this line to toggle debug tracing
#define DEBUG

int main(void) {
    int i, n = 5, sum = 0;

    // Fixed defect: changed condition from 'i < n' to 'i <= n'
    for (i = 1; i <= n; i++) {
        sum += i;
#ifdef DEBUG
        printf("[trace] pass %d: i = %d, sum = %d\n", i, i, sum);
#endif
    }

    printf("Sum of 1 to %d is %d\n", n, sum);
    return 0;
}
