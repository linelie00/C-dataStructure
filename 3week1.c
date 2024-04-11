#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return (s->top == (MAX_SIZE-1));
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, int data) {
    if(isFull(s))
        printf("isFull\n");
    s->arr[++(s->top)] = data;
}

int pop(Stack *s) {
    if(isEmpty(s))
        printf("isEmpty\n");
    else return s->arr[(s->top)--];

}

int peek(Stack *s) {
    return s->arr[(s->top)];
}

int main() {
    Stack s;
    initialize(&s);

    printf("Stack is empty.\n");
    push(&s, 5);
    printf("Pushing: 5\n");
    push(&s, 10);
    printf("Pushing: 10\n");
    printf("Peek: %d\n",peek(&s));
    printf("Popping: %d\n",pop(&s));
    printf("Peek: %d\n",peek(&s));

    return 0;
}