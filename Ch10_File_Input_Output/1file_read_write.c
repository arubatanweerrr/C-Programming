#include <stdio.h>

int main() {
    FILE *fptr;
    char ch;

    // Reading a file
    fptr = fopen("Test.txt", "r");
    if (fptr == NULL) {
        printf("doesn't exist!\n");
    } else {
        fscanf(fptr, "%c", &ch);
        printf("character in file is : %c\n", ch);
        fscanf(fptr, "%c", &ch);
        printf("character in file is : %c\n", ch);
        fclose(fptr);
    }

    // Writing in a file
    ch = 'N';
    fptr = fopen("NewFile.txt", "w");
    fprintf(fptr, "%c", ch);
    fclose(fptr);

    return 0;
}