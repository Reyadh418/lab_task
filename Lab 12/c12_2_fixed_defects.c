/*
 * CSE 115L: Programming Language I Lab
 * Lab 12 - Challenging Exercise 2 (C12.2): Four defects, one of which the compiler never mentions
 * 
 * Summary of Defects in Original Code:
 * 1. Line 19: split_fee(45000.0, hall, &tuition); 
 *    - Defect: 'hall' passed as double value instead of '&hall' (double *).
 *    - Compiler action: STOPPED THE BUILD (type mismatch).
 *    - Fix: Pass '&hall'.
 *
 * 2. Line 27: void read_marks(int *markp) { markp = 88; }
 *    - Defect: Assigned integer 88 directly to pointer variable 'markp', not through indirection '*markp'.
 *    - Compiler action: WARNED under -Wall (makes pointer from integer without a cast).
 *    - Fix: Change to '*markp = 88;'.
 *
 * 3. Line 22: printf("address %d\n", &marks);
 *    - Defect: Used %d to format a memory address ('int *').
 *    - Compiler action: WARNED under -Wall (format specifies type 'int' but argument has type 'int *').
 *    - Fix: Use '%p' and cast to '(void *)&marks'.
 *
 * 4. Lines 3, 13, 26: void bump_cgpa(double cgpa) { cgpa = cgpa + 0.10; }
 *    - Defect: Passed by value; modified local parameter copy only. Caller's cgpa in main remained 3.21.
 *    - Compiler action: NOTHING AT ALL (silent logic error).
 *    - Fix: Change prototype and definition to take 'double *cgpap', call with '&cgpa', and update '*cgpap += 0.10;'.
 */

#include <stdio.h>

/* Corrected Prototypes */
void bump_cgpa(double *cgpap);                                   /* Fixed: output parameter */
void read_marks(int *markp);                                      /* Takes address of marks */
void split_fee(double fee, double *hallp, double *tuitionp);      /* Takes addresses of hall and tuition */

int main(void)
{
    double cgpa = 3.21;
    int marks = 0;
    double hall = 0.0, tuition = 0.0;

    printf("=== Lab 12 Task C12.2: Corrected Program (All 4 Defects Fixed) ===\n\n");

    /* Defect 4 Fixed: pass address &cgpa so function modifies main's variable */
    bump_cgpa(&cgpa);
    printf("cgpa    : %.2f\n", cgpa);        /* Prints 3.31 */

    /* Defect 2 Fixed: inside read_marks, *markp = 88 updates marks in main */
    read_marks(&marks);
    printf("marks   : %d\n", marks);          /* Prints 88 */

    /* Defect 1 Fixed: pass &hall instead of hall */
    split_fee(45000.0, &hall, &tuition);
    printf("hall    : %.2f\n", hall);         /* Prints 13500.00 */
    printf("tuition : %.2f\n", tuition);      /* Prints 31500.00 */

    /* Defect 3 Fixed: use %p and (void *) cast for memory address */
    printf("address : %p\n", (void *)&marks);

    return 0;
}

/* Corrected function definitions */

/* Fixed: now receives pointer and alters caller's cgpa via *cgpap */
void bump_cgpa(double *cgpap)
{
    *cgpap = *cgpap + 0.10;
}

/* Fixed: indirection operator * assigns 88 into the cell pointed to by markp */
void read_marks(int *markp)
{
    *markp = 88;
}

void split_fee(double fee, double *hallp, double *tuitionp)
{
    *hallp = fee * 0.30;
    *tuitionp = fee * 0.70;
}
