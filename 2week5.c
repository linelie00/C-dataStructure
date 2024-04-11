#include <stdio.h>
#include <string.h>

char str[100];

void reverse(int c, int i, char newstr[100]) {
    if (c<0) {
        for (int k = 0; k < strlen(str);k++) {
            printf("%c", newstr[k]);
        }
        return;
    }
    newstr[i] = str[c];
    reverse(--c, ++i, newstr);
}
int main() {
    char new_str[100];
    scanf("%s", str);
    reverse(strlen(str)-1, 0, new_str);

    return 0;
}