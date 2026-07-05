#include <stdio.h>

int main() {

    int age = 22;
    int oldAge = age;
    int newAge = oldAge + 2;

    printf("New age is : %d", newAge);

    int rupee = 1;
    int dollar;
    dollar = 74;

    /*
        Order of declaration is important
        Wrong declaration order

        float pi = 3.14;
        float area = pi * rad * rad;
        float rad = 3;
    */

    // Valid declaration
    int age1, age2, age3;
    age1 = age2 = age3 = 22;

    // Invalid
    // int a1 = a2 = a3 = 22;

    return 0;
}