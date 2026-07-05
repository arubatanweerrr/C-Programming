#include <stdio.h>

int main() {
    int marks[3];
    
    printf("physics : ");
    scanf("%d", &marks[0]);
    
    printf("chem : ");
    scanf("%d", &marks[1]);
    
    printf("math : ");
    scanf("%d", &marks[2]);
    
    printf("physics = %d\n", marks[0]);
    printf("chem = %d\n", marks[1]);
    printf("math = %d\n", marks[2]);
    
    return 0;
}