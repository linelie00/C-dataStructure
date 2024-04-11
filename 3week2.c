#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더 파일
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, char data) {
    s->arr[++(s->top)] = data;
}

char pop(Stack *s) {
    if(isEmpty(s))
        printf("isEmpty\n");
    else return s->arr[(s->top)--];
}

bool isMatchingPair(char s, char e) {
    if ((s=='{'&&e=='}')||(s=='['&&e==']')||(s=='('&&e==')'))
        return true;
    else
        return false;
}

bool isBalanced(char expression[100],Stack *s) {
    for(int i=0; i<MAX_SIZE; i++) {
        if (expression[i] == '{' || expression[i] == '['||expression[i] == '(')
            push(s,expression[i]);
        else if (expression[i] == '}' || expression[i] == ']'||expression[i] == ')') {
            if(isMatchingPair(s->arr[s->top],expression[i]))
                pop(s);
            else
                return false;
        }
        else
            return true;
    }
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);

    Stack s;
    initialize(&s);

    if (isBalanced(expression,&s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}