#include <stdio.h>

int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name); // Note: scanf only reads until whitespace
    printf("Your name is: %s", name);
    
    return 0;
}