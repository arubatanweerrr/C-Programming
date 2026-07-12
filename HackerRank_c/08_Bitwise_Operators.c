#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;

    
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int AND = a & b;
            int OR = a | b;
            int XOR = a ^ b;

            
            if (AND < k && AND > max_and) {
                max_and = AND;
            }
            if (OR < k && OR > max_or) {
                max_or = OR;
            }
            if (XOR < k && XOR > max_xor) {
                max_xor = XOR;
            }
        }
    }

    
    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}

int main() {
    int n, k;
    
    if (scanf("%d %d", &n, &k)) {
        calculate_the_maximum(n, k);
    }
    return 0;
}