#include <stdio.h>
#include <string.h>

int dfa_accepts(char input_string[]) {
    int state = 0;
    int length = strlen(input_string);

    for (int i = 0; i < length; i++) {
        char current_char = input_string[i];

        // Ensure valid input characters
        if (current_char != '0' && current_char != '1') {
            return 0; // Reject if an invalid character is found
        }

        // Transition logic
        switch (state) {
            case 0: 
                if (current_char == '0') {
                    state = 1;
                }
                break;

            case 1:
                if (current_char == '0') {
                    state = 2;
                } else if (current_char == '1') {
                    state = 0;
                }
                break;

            case 2:
                if (current_char == '1') {
                    state = 3;
                } else if (current_char == '0') {
                    state = 2;
                }
                break;

            case 3:
                // Stay in the accepting state but allow additional valid input
                if (current_char == '0' || current_char == '1') {
                    state = 3;
                }
                break;

            default:
                return 0; // Reject for any unexpected state
        }
    }

    // Accept if the final state is 3
    return (state == 3);
}

int main() {
    char input_string[100];
    printf("Enter the input string:\n");
    scanf("%99s", input_string); // Use %99s to prevent buffer overflow

    if (dfa_accepts(input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
