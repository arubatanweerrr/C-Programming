#include <stdio.h>

int main() {

    char s[1001];
    int freq[10]  = {0};
    int i;
    
    scanf("%s",  s);
    
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';
            freq[digit]++;
        }
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d ", freq[i]);
    }
    return 0;
}