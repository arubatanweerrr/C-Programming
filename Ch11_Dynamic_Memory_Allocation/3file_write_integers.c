#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("Test.txt", "w");
    
    // Writing numbers to a file
    int n = 45;
    fprintf(fptr, "%d", n);
    fprintf(fptr, "%c", ' ');
    fprintf(fptr, "%d", 98);
    
    fclose(fptr);
    return 0;
}