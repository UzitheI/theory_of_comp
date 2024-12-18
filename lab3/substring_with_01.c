#include <stdio.h>

// Function to simulate the NFA
int simulateNFA(char *input) {
    int currentState = 0; // Start state
    int i = 0;

    while (input[i] != '\0') {
        char inputSymbol = input[i];

        switch (currentState) {
            case 0: // State q0
                if (inputSymbol == '0') {
                    currentState = 1; // Transition to q1 on '0'
                }
                break;

            case 1: // State q1
                if (inputSymbol == '1') {
                    currentState = 2; // Transition to q2 on '1'
                } else if (inputSymbol == '0') {
                    currentState = 1; // Stay in q1 on '0'
                }
                break;

            case 2: // Accepting state q2
                break; // No further state transitions
        }

        i++;
    }

    // Check if in accepting state
    if (currentState == 2) {
        printf("String accepted\n");
        return 1; // Accepted
    } else {
        printf("String rejected\n");
        return 0; // Rejected
    }
}

// Main function
int main() {
    char input[100];

    printf("Enter input string: ");
    scanf("%s", input);

    simulateNFA(input);

    return 0;
}
