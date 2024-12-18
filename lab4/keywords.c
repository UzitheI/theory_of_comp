#include <stdio.h>
#include <string.h>

// List of C keywords
char keyword[32][10] = {
    "auto", "double", "int", "struct", "break", "else", "long", "switch", "case",
    "enum", "register", "typedef", "char", "extern", "return", "union", "const",
    "float", "short", "unsigned", "continue", "for", "signed", "void", "default",
    "goto", "sizeof", "volatile", "do", "if", "static", "while"
};

// Define states for the finite automaton
enum states { q0, qf, qd };

// Function prototypes
enum states delta(enum states, char);
int iskeyword(char[]);

// Main function
int main() {
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove the newline character if present

    ch = string[i];

    // Check if the input string is a keyword
    if (iskeyword(string)) {
        printf("%s: keyword\n", string);
    } else {
        // Process the string using the finite automaton
        while (ch != '\0') {
            curr_state = delta(curr_state, ch);
            ch = string[++i];
        }

        // Check the final state to determine if it's a valid identifier
        if (curr_state == qf) {
            printf("%s: valid identifier\n", string);
        } else {
            printf("%s: not a valid identifier.\n", string);
        }
    }

    return 0;
}

// Transition function for the finite automaton
enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch (s) {
        case q0:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_') {
                curr_state = qf;
            } else {
                curr_state = qd;
            }
            break;

        case qf:
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_' || (ch >= '0' && ch <= '9')) {
                curr_state = qf;
            } else {
                curr_state = qd;
            }
            break;

        case qd:
            curr_state = qd; // Once in qd, remain in qd
            break;
    }

    return curr_state;
}

// Function to check if a string is a keyword
int iskeyword(char str[]) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keyword[i]) == 0) {
            return 1; // The string is a keyword
        }
    }
    return 0; // The string is not a keyword
}
