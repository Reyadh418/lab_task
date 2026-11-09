#include <stdio.h>

int main(void) {
    int choice;

    do {
        printf("\n========================================\n");
        printf("          INFORMATION SYSTEM            \n");
        printf("========================================\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Quit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n[Action] Adding a new record...\n");
                break;
            case 2:
                printf("\n[Action] Displaying all records...\n");
                break;
            case 3:
                printf("\n[Action] Searching for a record...\n");
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid choice! Please select an option from 1 to 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
