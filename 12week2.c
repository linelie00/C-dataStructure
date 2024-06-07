#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 100

int compare(const void *a, const void *b) {
    char *str1 = (char *)a;
    char *str2 = (char *)b;

    if (strlen(str1) != strlen(str2)) {
        return strlen(str1) - strlen(str2);
    } else {
        return strcmp(str1, str2);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char words[MAX][LEN];
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    qsort(words, N, sizeof(words[0]), compare);

    printf("%s\n", words[0]);
    for (int i = 1; i < N; i++) {
        if (strcmp(words[i], words[i-1]) != 0) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
