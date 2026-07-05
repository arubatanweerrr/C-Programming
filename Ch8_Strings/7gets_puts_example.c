#include <stdio.h>

int main() {
    char str[100];
    printf("Enter string: ");
    gets(str); // Reads a full line, including spaces
    puts(str); // Prints the string
    
    return 0;
}