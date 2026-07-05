#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello";
    
    // strlen: get string length
    printf("Length: %d\n", strlen(str));
    
    // strcpy: copy string
    char newStr[20];
    strcpy(newStr, str);
    
    // strcat: concatenate
    strcat(newStr, " World");
    
    // strcmp: compare strings
    printf("Compare: %d\n", strcmp(str, "Hello"));
    
    return 0;
}