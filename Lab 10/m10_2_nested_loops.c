#include <stdio.h>

int main(void) {
    int student_id_N = 1234;
    int r = (student_id_N % 6) + 3;
    int inner_count = 0;

    printf("Student ID N = %d, calculated r = %d\n\n", student_id_N, r);

    printf("--- (a) %dx%d Multiplication Table ---\n", r, r);
    printf(" * |");
    for (int col = 1; col <= r; col++) {
        printf("%4d", col);
    }
    printf("\n---+");
    for (int col = 1; col <= r; col++) {
        printf("----");
    }
    printf("\n");

    for (int i = 1; i <= r; i++) {
        printf("%2d |", i);
        for (int j = 1; j <= r; j++) {
            printf("%4d", i * j);
            inner_count++;
        }
        printf("\n");
    }

    printf("\nInner body execution count for (a): %d (Expected r * r = %d)\n\n", inner_count, r * r);

    printf("--- (b) Right Triangle of Asterisks ---\n");
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    printf("--- (c) Upside-Down Right Triangle ---\n");
    for (int i = r; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
