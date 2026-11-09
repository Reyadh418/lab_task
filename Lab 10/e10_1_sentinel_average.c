#include <stdio.h>

int main(void) {
    double value, total = 0.0;
    int count = 0;

    printf("Enter non-negative numbers (negative number to stop): ");
    scanf("%lf", &value);

    while (value >= 0.0) {
        total += value;
        count++;

        printf("Enter next number: ");
        scanf("%lf", &value);
    }

    if (count == 0) {
        printf("\nNo valid numbers were entered. Average cannot be calculated.\n");
    } else {
        double average = total / count;
        printf("\nTotal numbers entered: %d\n", count);
        printf("Sum: %.2f\n", total);
        printf("Average: %.2f\n", average);
    }

    return 0;
}
