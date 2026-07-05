#include <stdio.h>

typedef struct BankAccount {
    int accountNo;
    char name[100];
} acc;

int main() {
    acc acc1 = {123, "Aruba"};
    printf("Account No: %d\n", acc1.accountNo);
    printf("Name: %s\n", acc1.name);
    return 0;
}