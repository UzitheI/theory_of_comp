#include <stdio.h>
#include<string.h>
int main() {
    enum states {q0, q1, qf};
    char input[20];
    enum states curr_state = q0;
    int i = 0;
    int flag = 0;

    printf("Enter a binary string: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char ch = input[i];
    while (ch != '\0') {
        switch (curr_state) {
            case q0:
                if (ch == '0')
                    curr_state = q1;
                else
                    flag = 1;
                break;

            case q1:
                if (ch == '1')
                    curr_state = qf;
                else
                    flag = 1;
                break;

            case qf:
                if (ch == '0' || ch == '1')
                    curr_state = qf;
                break;

            default:
                flag = 1;
                break;
        }
        if (flag)
            break;
        ch = input[++i];
    }

    if (curr_state == qf)
        printf("\nThe string %s is accepted.\n", input);
    else
        printf("\nThe string %s is not accepted.\n", input);

    return 0;
}
