Basic ATM System in C language

In this code:
-User information is stored together using the Account structure.
-Multiple user records are stored using the accounts array.
-A fixed user count is set with #define USER_COUNT 3.
-while and for loops are used to control repetitive operations.
-if and switch statements are used to perform different operations based on conditions.
-The code is modularized with separate functions defined for each operation.
-When a user enters invalid input, the input buffer is cleared using while(getchar() != '\n'); and an error message is displayed.
-The console screen is cleared with system("cls"); (specific to Windows systems).
-The user's PIN is verified, and they are given three attempts to enter it correctly.
-Deposit and withdrawal operations are validated and reflected in the user's balance.
-After confirming the old PIN, the user can set a new one.