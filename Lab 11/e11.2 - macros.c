#include <stdio.h>

#define SQUARE(x)       ((x) * (x))
#define MAX2(a, b)      (((a) > (b)) ? (a) : (b))

int main(void) {
    int N = 1234;
    int rem = N % 97;

    printf("Student ID N = %d, N %% 97 = %d\n\n", N, rem);

    int sq_calc = 1000 / SQUARE(rem + 1);
    printf("Expression 1: 1000 / SQUARE(%d + 1) = %d\n", rem, sq_calc);

    int max_calc = 10 + 2 * MAX2(N - 100, rem * 20);
    printf("Expression 2: 10 + 2 * MAX2(%d - 100, %d * 20) = %d\n", N, rem, max_calc);

    return 0;
}
