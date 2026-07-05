#include <stdio.h>
#include <string.h>

int main() {
    // Declaration
    char name[] = "Aruba Tanweer";
    char course[] = {'a', 'p', 'm', 'a', 'c', '\0'};

    // Printing string
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    // Printing with pointer
    for (char *ptr = name; *ptr != '\0'; ptr++) {
        printf("%c", *ptr);
    }
    printf("\n");

    return 0;
}