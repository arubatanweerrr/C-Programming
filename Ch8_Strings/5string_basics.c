#include <stdio.h>

int main() {
    char name[] = {'A', 'R', 'U', 'B', 'A', '\0'};
    char fullName[] = "ARUBA";
    
    printf("%s\n", name);
    printf("%s\n", fullName);
    
    return 0;
}