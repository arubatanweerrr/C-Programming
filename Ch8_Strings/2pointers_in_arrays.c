#include <stdio.h>

int main() {
    int adr[3] = {1, 2, 3};
    int *ptr = &adr[0];
    
    // Printing array values using pointers
    printf("%d\n", *ptr);
    printf("%d\n", *(ptr + 1));
    printf("%d\n", *(ptr + 2));
    
    return 0;
}