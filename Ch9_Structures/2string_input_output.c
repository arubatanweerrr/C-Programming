#include <stdio.h>

int main() {
    // Printing using format specifier
    char name[] = "Aruba";
    printf("%s\n", name);

    // Input using scanf
    char firstName[40];
    printf("Enter first name : ");
    scanf("%s", firstName);
    printf("Your first name is %s\n", firstName);

    // Input using fgets and puts
    char fullName[40];
    printf("Enter full name : ");
    fgets(fullName, 40, stdin);
    puts(fullName);

    return 0;
}