#include <stdio.h>
int main() { 
        int arr[4] = {1,2,3,4};
        int (*ptr)[3];
        ptr = &arr;
        
        printf("%p\n", ptr[0]);
        printf("%p\n", ptr[1]);
        printf("%d\n", (*ptr)[0]);
        printf("%d\n", (*ptr)[1]);
}