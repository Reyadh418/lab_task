#include <stdio.h>

int main(void) {
    int n;
    int power = 1;

    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    while (power < n) {
        power *= 2;
    }

    printf("The smallest power of 2 >= %d is %d\n", n, power);

    return 0;
}
