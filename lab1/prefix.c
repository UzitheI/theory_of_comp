#include <stdio.h>
#include <string.h>

void prefix(char input_string[], int length) {
    printf("The prefixes of the string are:\n");
    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", input_string[j]);
        }
        printf("\n");
    }
}

void suffix(char input_string[], int length) {
    printf("The suffixes of the string are:\n");
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            printf("%c", input_string[j]);
        }
        printf("\n");
    }
}

void substring(char input_string[], int length) {
    printf("The substrings of the string are:\n");
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", input_string[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char input_string[100];
    printf("Enter the string:\n");
    scanf("%s", input_string);
    int length_of_string = strlen(input_string);
    int choice;

    printf("Enter 1 for prefix, 2 for suffix, and 3 for substrings:\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            prefix(input_string, length_of_string);
            break;
        
        case 2:
            suffix(input_string, length_of_string);
            break;
        
        case 3:
            substring(input_string, length_of_string);
            break;
        
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}
