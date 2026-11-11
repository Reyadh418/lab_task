/*
 * C11.1: Four faults fixed one at a time.
 * Follows Lab 11 §5 & C11.1
 *
 * Faults diagnosed:
 * 1. Line 3: '#define LIMIT 5;' -> Semicolon in macro definition causes syntax errors
 *    at uses: 'i <= 5;; i++' and 'i <= 5;)'. Compiler STOPPED (error).
 *    Correction: #define LIMIT 5
 *
 * 2. Line 4: '#define HALF(x) x / 2' lacks parentheses. In 'HALF(total + 1)' it expands
 *    to 'total + 1 / 2'. With total = 20, '1 / 2' is 0, so '20 + 0 = 20' instead of 10.5.
 *    Compiler said NOTHING (silent logic error).
 *    Correction: #define HALF(x) (((double)(x)) / 2.0)
 *
 * 3. Line 17-19: While loop has no update statement for 'i' (missing 'i++').
 *    Results in an infinite loop printing '1 1 1...'. Compiler said NOTHING.
 *    Correction: Add 'i++;' inside the while loop body.
 *
 * 4. Line 22: 'printf("Half of the total is %.2f\n", HALF(total + 1));' passed an int
 *    to '%.2f' when HALF had integer division. Compiler WARNED with -Wall (format mismatch).
 *    Correction: Cast to double / use 2.0 in the macro so a double is passed to %.2f.
 */
#include <stdio.h>

// Fixed Fault 1 (removed semicolon)
#define LIMIT 5

// Fixed Fault 2 & 4 (parentheses around parameter and body + float division for %.2f)
#define HALF(x) (((double)(x)) / 2.0)

int main(void) {
    int i, value, total = 0;

    // Read 5 values and accumulate
    for (i = 1; i <= LIMIT; i++) {
        printf("Value %d: ", i);
        scanf("%d", &value);
        total += value;
    }

    // Print squares from 1 to LIMIT
    i = 1;
    while (i <= LIMIT) {
        printf("%d ", i * i);
        i++; // Fixed Fault 3: added missing update to prevent infinite loop
    }
    printf("\n");

    // Display half of (total + 1)
    printf("Half of the total is %.2f\n", HALF(total + 1));

    return 0;
}
