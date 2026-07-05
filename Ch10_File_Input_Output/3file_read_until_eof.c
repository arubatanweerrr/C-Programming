#include <stdio.h>

int main() {
    FILE *fptr;
    char ch;

    // Read the full file until End Of File (EOF)
    fptr = fopen("NewFile.txt", "r");
    ch = fgetc(fptr);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);

    return 0;
}