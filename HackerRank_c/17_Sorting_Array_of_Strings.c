#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sorts lexicographically
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// Sorts reverse lexicographically
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Counts unique characters using a frequency map for all ASCII values
int countDistinct(const char *s) {
    int freq[256] = {0};
    int count = 0;
    while (*s) {
        if (freq[(unsigned char)*s] == 0) {
            freq[(unsigned char)*s] = 1;
            count++;
        }
        s++;
    }
    return count;
}

// Sorts by number of distinct characters, then lexicographically
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int da = countDistinct(a);
    int db = countDistinct(b);
    if (da != db) return da - db;
    return strcmp(a, b);
}

// Sorts by length, then lexicographically
int sort_by_length(const char* a, const char* b) {
    size_t la = strlen(a);
    size_t lb = strlen(b);
    if (la != lb) return (int)(la - lb);
    return strcmp(a, b);
}

// Standard bubble sort implementation
void string_sort(char **arr, const int cnt, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char** arr = (char**)malloc(n * sizeof(char*));
    char buffer[1024];

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        arr[i] = malloc(strlen(buffer) + 1);
        strcpy(arr[i], buffer);
    }

    // Execution of sorts
    void (*sort_funcs[])(char **, const int, int (*)(const char*, const char*)) = {
        string_sort, string_sort, string_sort, string_sort
    };
    
    int (*cmp_funcs[])(const char*, const char*) = {
        lexicographic_sort, 
        lexicographic_sort_reverse, 
        sort_by_length, 
        sort_by_number_of_distinct_characters
    };

    for (int i = 0; i < 4; i++) {
        string_sort(arr, n, cmp_funcs[i]);
        for (int j = 0; j < n; j++) printf("%s\n", arr[j]);
        printf("\n");
    }

    // Cleanup memory
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);

    return 0;
}