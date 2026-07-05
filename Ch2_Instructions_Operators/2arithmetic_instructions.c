#include <stdio.h>

int main() {

    int a = 1, b = 2, c = 3;

    // Valid
    a = b + c;

    // Invalid
    // b + c = a;

    printf("%d\n", 3 % 2);
    printf("%d\n", -3 % 2);

    return 0;
}