#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef char element;

typedef struct
{
    int front;
    int rear;
    element data[SIZE];
} QueueType;

void init(QueueType *Q)
{
    Q->rear = -1;
    Q->front = -1;
    for(int i=0;i<100;i++)
        Q->data[i]='\0';
}

int is_empty(QueueType *Q)
{
    if (Q->front == Q->rear)
        return 1;

    else
        return 0;
}

int is_full(QueueType *Q)
{
    if (Q->rear == SIZE - 1)
        return 1;
    else
        return 0;

}

void enqueue(QueueType *Q, element e)
{
    if(is_full(Q))
        return;
    Q->data[++(Q->rear)] = e;
}

element dequeue(QueueType *Q)
{
    if(is_empty(Q))
        return -1;
    element item = Q->data[++(Q->front)];
    return item;
}

void print(QueueType *Q)
{
    printf("Front Pos : %d, Rear Pos : %d\n", Q->front, Q->rear);
    //printf("[%c] [%c] [%c]\n", Q->data[0], Q->data[1], Q->data[2]);
    for (int i=0; i<SIZE; i++) {
        if (Q->data[i] == '\0') {
            printf("\n");
            break;
        }
        printf("[%c] ", Q->data[i]);
    }
}

int main()
{
    QueueType Q;
    init(&Q);

    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    print(&Q);
    printf("[%c] \n", dequeue(&Q));
}