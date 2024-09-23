//Write a program to implement DFA that accepts all the strings ending with 01


#include<stdio.h>
#include<string.h>

int main(){
    char input_string[100]; 
    printf("Enter the string:\n");
    scanf("%s", input_string);
    int length= strlen(input_string);

    if (length<2){
        printf("the string is rejected by the dfa\n");
    }
    else if (input_string[length-1]=='1')
    {
        if (input_string[length-2]=='0'){
            printf("The string is accepted\n");
        }
        else{
            printf("the string is rejected\n");
        }
    }
    else{
        printf("The string is rejected\n");
    }
    return 0;
}