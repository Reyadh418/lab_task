/*
 * C11.2: Find largest, smallest, and count without storing any values in arrays.
 * Follows Lab 11 §1.1, §1.4, §5 & C11.2
 *
 * Edge cases handled:
 * 1. No values at all (first input is 0)
 * 2. Exactly one value followed by 0
 * 3. Set that is entirely negative
 */
#include <stdio.h>

int main(void) {
    double value;
    double largest, smallest;
    int count = 0;

    printf("Enter double values (0 to stop):\n");

    // Priming read
    printf("Value: ");
    if (scanf("%lf", &value) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check if user entered sentinel immediately (Zero passes)
    if (value == 0.0) {
        printf("\nNo values were entered.\n");
    } else {
        // Initialize largest and smallest with the FIRST valid data value, NOT 0.
        // Reason: If data is all negative, initialising largest to 0 falsely reports 0.
        largest = value;
        smallest = value;
        count = 1;

        // Loop until sentinel 0 is encountered
        while (1) {
            printf("Value: ");
            if (scanf("%lf", &value) != 1) {
                break;
            }
            if (value == 0.0) {
                break; // Sentinel reached
            }

            count++;
            if (value > largest) {
                largest = value;
            }
            if (value < smallest) {
                smallest = value;
            }
        }

        printf("\n========================================\n");
        printf("Total numbers entered : %d\n", count);
        printf("Largest value         : %.2f\n", largest);
        printf("Smallest value        : %.2f\n", smallest);
        printf("========================================\n");
    }

    return 0;
}
