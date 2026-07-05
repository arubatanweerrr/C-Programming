#include <stdio.h>

int main() {
    FILE *fptr;
    int n;
    
    fptr = fopen("Test.txt", "r");
    
    // Reading integers from a file
    fscanf(fptr, "%d", &n);
    printf("number = %d\n", n);
    fscanf(fptr, "%d", &n);
    printf("number = %d\n", n);
    
    fclose(fptr);
    return 0;
}