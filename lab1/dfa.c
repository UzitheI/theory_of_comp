#include<stdio.h>
#include<string.h>
int main(){
    char input_string[100];
    printf("Enter the input string\n");
    scanf("%s", input_string);
    int length=strlen(input_string);
    int i=0;
    if (length<2){
        printf("the string is rejected by the dfa\n");
    }
    else if (input_string[i]=='0')
    {
        if (input_string[i+1]=='1'){
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