#include <stdio.h>

int main() {
    FILE *fptr;

    // Reading characters one by one using fgetc
    fptr = fopen("NewFile.txt", "r");
    printf("character in file is : %c\n", fgetc(fptr));
    fclose(fptr);

    // Writing characters using fputc
    fptr = fopen("NewFile.txt", "w");
    fputc('a', fptr);
    fputc('p', fptr);
    fputc('p', fptr);
    fputc('l', fptr);
    fputc('e', fptr);
    fclose(fptr);

    return 0;
}