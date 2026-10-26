#include <stdio.h>

int main() {
    int pin = 1520;
    int enteredPin;
    float balance = 1000.0f;
    int choice;
    float amount;
    char transaction = 'y';

    printf("Enter your secret PIN number: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Invalid PIN. Access denied.\n");
        return 0;
    }

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to withdraw: Rs. ");
                scanf("%f", &amount);
                if (amount > balance - 500) {
                    printf("Insufficient balance or must maintain a minimum reserve of Rs. 500.\n");
                } else if ((int)amount % 100 != 0) {
                    printf("Please enter the amount in multiples of 100.\n");
                } else {
                    balance -= amount;
                    printf("Please collect your cash. New balance: Rs. %.2f\n", balance);
                }
                break;

            case 3:
                printf("\nEnter amount to deposit: Rs. ");
                scanf("%d", &choice); // or use float amount
                scanf("%f", &amount);
                balance += amount;
                printf("Amount deposited successfully. New balance: Rs. %.2f\n", balance);
                break;

            case 4:
                printf("\nThank you for using the ATM.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please select a valid option.\n");
        }

        printf("\nDo you wish to perform another transaction? (y/n): ");
        scanf(" %c", &transaction);

    } while (transaction == 'y' || transaction == 'Y');

    printf("\nThank you for using the ATM.\n");
    return 0;
}
