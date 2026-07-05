#include <stdio.h>

int main() {
    int marks[] = {98, 95, 99};
    
    // Traversing an array
    for (int i = 0; i < 3; i++) {
        printf("%d index = %d\n", i, marks[i]);
    }
    return 0;
}