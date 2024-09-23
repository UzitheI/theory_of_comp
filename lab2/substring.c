#include <stdio.h>
#include <string.h>


int dfa_accepts(char input_string[]) {
    int state = 0;
    int length = strlen(input_string);

    for (int i = 0; i < length; i++) {
        char current_char = input_string[i];

        switch (state) {
            case 0: 
                if (current_char == '0') {
                    state = 1;
                }
                break;
            
            case 1:
                if (current_char == '0') {
                    state = 2;
                } else {
                    state = 0;
                }
                break;

            case 2:
                if (current_char == '1') {
                    state = 3;
                } else if (current_char == '0') {
                    state = 2;
                } else {
                    state = 0; 
                }
                break;

            case 3:
                return 1; 
        }
    }

    return (state == 3);
}

int main() {
    char input_string[100];
    printf("Enter the input string:\n");
    scanf("%s", input_string);

    if (dfa_accepts(input_string)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
