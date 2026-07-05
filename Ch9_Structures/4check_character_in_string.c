#include <stdio.h>

void checkChar(char str[], char ch);

int main() {
    char str[] = "Apna College";
    char ch = 'X';
    checkChar(str, ch);
    return 0;
}

void checkChar(char str[], char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            printf("Character is present!\n");
            return;
        }
    }
    printf("Character is NOT present :(\n");
}