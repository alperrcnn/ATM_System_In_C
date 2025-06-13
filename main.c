#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USER_COUNT 3  //  Total number of users that we defined

typedef struct {
    char name[50];
    int pin;
    float balance;
} Account;
// Registered users. ACC Name/PIN/Current balance
Account accounts[USER_COUNT] = {
    {"Alper", 1111, 1250.5},
    {"Can", 2222, 830.0},
    {"Mehmet", 3333, 1020.75}
};

int activeUser = -1; //Index of the currently active user

// Function prototypes
int authenticate();   // Function for PIN authentication
void showMenu();      // Function to display the menu
void viewBalance();   // Function to show account balance
void deposit();       // Function to deposit money
void withdraw();      // Function to withdraw money
void changePin();     // Function to change PIN


int main() {
    printf("=== ATM SYSTEM ===\n\n");

    if (!authenticate()) {   // Exit if authentication fails
        printf("Acces denied. Try again later.\n");
        return 1;
    }

    showMenu(); // Show menu after successful login
    return 0;
}

int authenticate() {
    int tries = 3; //3 attempt right
    int inputPin;

    while (tries > 0) {
        printf("Please enter your PIN: ");

        if (scanf("%d", &inputPin) != 1) {  // Check PIN input validity
            printf("Acces denied.\n");

            while (getchar() != '\n'); // Clear input buffer on invalid input
            continue;
}

    for (int i = 0; i < USER_COUNT; i++) {

        if (accounts[i].pin == inputPin) {
                activeUser = i;
                printf("Welcome, %s!\n", accounts[i].name);

        return 1; //Successful login
}
}
        tries--;
        printf("Wrong PIN. Password attempts left: %d\n", tries);
}
    return 0;  // Failed login
}
// Display the main menu and process user choices
void showMenu() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1) Show balance\n");
        printf("2) Deposit\n");
        printf("3) Withdraw\n");
        printf("4) Change PIN \n");
        printf("5) Exit\n");
        printf("Make your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");

            while (getchar() != '\n');
            continue;
}

        switch (choice) {
            case 1:
                viewBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                changePin();
                break;
            case 5:
                printf("See you later, %s.\n", accounts[activeUser].name);
                return; // Exit the program
            default:
                printf("Geçersiz seçim.\n");
}
}
}
// Show current balance of the active user
void viewBalance() {
    system("cls");
    printf("Current balance: %.2f TL\n", accounts[activeUser].balance);

}
// Deposit money to the active user's account
void deposit() {
    system("cls");
    float amount;
    printf("Deposit amount: ");
    if (scanf("%f", &amount) != 1 || amount <= 0) {

        printf("Invalid amount.\n");
        while (getchar() != '\n');

        return;
}

    accounts[activeUser].balance += amount;
    printf("%.2f TL deposited. New balance: %.2f TL\n", amount, accounts[activeUser].balance);
}

void withdraw() {
    system("cls");
    float amount;
    printf("Amount of withdraw: ");
    if (scanf("%f", &amount) != 1) {
        printf("Invalid enter.\n");
        while (getchar() != '\n');
        return;
}

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
}
    if (amount > accounts[activeUser].balance) {
        printf("Insufficient balance.\n");

        return;
}

    accounts[activeUser].balance -= amount;
    printf("%.2f TL withdrawn. Remaining balance is: %.2f TL\n", amount, accounts[activeUser].balance);
}
// Change PIN for the active user
void changePin() {
    system("cls");

    int currentPin, newPin;
    printf("Please enter your current PIN: ");

    if (scanf("%d", &currentPin) != 1 || currentPin != accounts[activeUser].pin) {
        printf("Wrong PIN.\n");
        while (getchar() != '\n');
        return;
}

    printf("Please enter your 4 digit new PIN: ");
    if (scanf("%d", &newPin) != 1 || newPin < 1000 || newPin > 9999) {

        printf("Invaild PIN format.\n");
        while (getchar() != '\n');

        return;
}

    accounts[activeUser].pin = newPin;
    printf("Your PIN has changed successfully.\n");
}
