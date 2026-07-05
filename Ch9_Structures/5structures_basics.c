#include <stdio.h>
#include <string.h>

struct student {
    char name[100];
    int roll;
    float cgpa;
};

void printInfo(struct student s1);

int main() {
    struct student s1;
    strcpy(s1.name, "Aruba");
    s1.roll = 64;
    s1.cgpa = 9.2;

    printf("Student info:\n");
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);
    printf("CGPA: %f\n", s1.cgpa);

    return 0;
}