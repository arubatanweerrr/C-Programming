#include <stdio.h>

// Function prototype
int factorial(int n);

int main() {
    int n;
    printf("enter n : ");
    scanf("%d", &n);
    printf("factorial is : %d", factorial(n));
    return 0;
}

// Recursive function definition
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int factNm1 = factorial(n - 1);
    int factN = factNm1 * n;
    return factN;
}