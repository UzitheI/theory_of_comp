#include <stdio.h>
#include <string.h>

char input[20];
int len;
int flag;

void q2(int i) {
    if (input[i] == '\0') {
        flag = 1; // Mark string as accepted
    }
}

void q1(int i) {
    if (i < len) {
        if (input[i] == '1') { 
            q2(i + 1); // Transition to q2 if '1' is found
        }
    }
}

void q0(int i) {
    if (i < len) {
        if (input[i] == '0') { 
            q0(i + 1); // Stay in q0 on '0'
            q1(i + 1); // Also explore transition to q1
        } else if (input[i] == '1') { 
            q0(i + 1); // Stay in q0 on '1'
        }
    }
}

int main() {
    printf("Enter a binary string: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character if present
    len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    len = strlen(input); // Recalculate the length
    flag = 0; // Initialize flag
    q0(0); // Start at state q0 with index 0

    if (flag == 1) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is not accepted.\n");
    }

    return 0;
}
