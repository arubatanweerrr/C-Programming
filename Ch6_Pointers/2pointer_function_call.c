#include <stdio.h>

void square(int m);
void _square(int *m);

int main() {
    int number = 4;

    // Call by value
    square(number);
    printf("m is : %d\n", number);

    // Call by reference
    _square(&number);
    printf("m is : %d\n", number);

    return 0;
}

void square(int m) {
    m = m * m;
    printf("square is : %d\n", m);
}

void _square(int *m) {
    *m = (*m) * (*m);
    printf("square is : %d\n", *m);
}