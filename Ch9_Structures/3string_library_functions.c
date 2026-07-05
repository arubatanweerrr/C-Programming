#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Shradha";
    printf("Length: %d\n", strlen(name));

    char oldVal[] = "Old value";
    char newVal[50];
    strcpy(newVal, oldVal);
    puts(newVal);

    char firstStr[50] = "Hello";
    char secStr[] = "World";
    strcat(firstStr, secStr);
    puts(firstStr);

    printf("Compare result: %d\n", strcmp("Apple", "Banana"));

    return 0;
}