#include <stdio.h>
#include <stdlib.h>

int count = 0;
int k;
int listSize;
typedef int element;


int is_full(){
    return count == listSize;
}

int is_empty(){
    return count == 0;
}

void insert(int arr[], element item) {
    if (is_full())
        printf("Queue is full. Cannot enqueue.\n");
    else {
        arr[(count++) % (listSize+1)] = item+1;
        printf("%d\n", item+1);
    }
}

void delete(int arr[],int i) {
    if (is_empty(arr)) {
        printf("Queue is empty. Cannot dequeue.\n0\n");
    }
    else {
        count--;
        element item = arr[i];
        printf("%d\n", item);
    }
}

int main() {
    scanf("%d, %d", &listSize, &k);
    int arr[listSize];

    for(int i=0;i<=listSize;i++) {
        insert(arr, i);
    }

    for(int i=0; i<=listSize; i++) {
        delete(arr, i);
    }

}