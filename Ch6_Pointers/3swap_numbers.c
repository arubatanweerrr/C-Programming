#include <stdio.h>

void swap(int a, int b);
void _swap(int *a, int *b);

int main() {
    int x = 3, y = 5;

    // Call by value (does not change original x, y)
    swap(x, y);
    printf("x = %d & y = %d\n", x, y);

    // Call by reference (successfully swaps x, y)
    _swap(&x, &y);
    printf("x = %d & y = %d\n", x, y);

    return 0;
}

// Function using call by value
void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

// Function using call by reference
void _swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}