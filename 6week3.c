#include <stdio.h>
#define MAX_SIZE 10

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

void peek_min(Stack *s) {
    int min = s->arr[0];
    for(int i=0; i<=s->top; i++){
        if(s->arr[i] < min) min = s->arr[i];
    }
    printf("Min: %d\n", min);
}

void print_stack(Stack *s) {
    for(int i=s->top; i>=0; i--){
        printf("%d", s->arr[i]);
        if(i != 0) printf("->");
        else printf("->NULL\n");
    }
}

void push(Stack *s, int data) {
    if(isFull(s))
        printf("isFull\n");

    s->arr[++(s->top)] = data;

    print_stack(s);
    peek_min(s);
}

void pop(Stack *s) {
    if(isEmpty(s))
        printf("isEmpty\n");
    s->arr[(s->top)--];
    print_stack(s);
    peek_min(s);

}

int peek(Stack *s) {
    return s->arr[(s->top)];
}

int main() {
    Stack s;
    initialize(&s);

    printf("Pushing elements onto the stack...\n");
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    push(&s, 1);
    printf("Popping elements from the stack...\n");
    pop(&s);
    pop(&s);
    pop(&s);

    return 0;
}