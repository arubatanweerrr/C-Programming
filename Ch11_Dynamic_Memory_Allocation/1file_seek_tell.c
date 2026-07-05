#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("Test.txt", "r");
    
    // fseek moves the file pointer to a specific location
    // SEEK_SET: beginning, SEEK_CUR: current, SEEK_END: end
    fseek(fptr, 2, SEEK_SET);
    
    // ftell returns the current position of the file pointer
    printf("%ld\n", ftell(fptr));
    
    fclose(fptr);
    return 0;
}