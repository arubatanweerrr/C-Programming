#include <stdio.h>

// Function prototype
int calcSquare(int n);

int main() {
    int n;
    printf("enter n : ");
    scanf("%d", &n);
    printf("square is : %d", calcSquare(n));
    return 0;
}

// Function definition
int calcSquare(int n) {
    return n * n;
}