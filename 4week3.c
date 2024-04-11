#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
typedef char element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE][50];
} QueueType;

// 오류 함수
void error(char *message){
    printf("%s\n", message);
}
// 순환 큐 초기화
void init_queue(QueueType *q){
    q->rear = -1;
    q->front = -1;
}
// 순환 큐 상태 출력
void display(QueueType *q){
    for(int i=0; i<MAX_QUEUE_SIZE; i++){
        if (i > q->front && i < q->rear) {
            printf("%s, ", q->data[i]);
        }
        else if (i > q->front && i == q-> rear) {
            printf("%s", q->data[i]);
        }
    }
    printf("\n");
}
// 순환 큐가 포화상태인가?
int is_full(QueueType *q){
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}
// 순환 큐가 공백상태인가?
int is_empty(QueueType *q){
    if (q->front == q->rear)
        return 1;

    else
        return 0;
}
// 방문객 추가
void enqueue(QueueType *q, char item[]){
    if(is_full(q))
        error("대기열이 가득 찼습니다.");
    strcpy(q->data[++(q->rear)],item);
}
// 탐승 및 대기열 이동
void dequeue(QueueType *q){
    if(is_empty(q))
        error("대기열이 비어 있습니다.");
    strcpy(q->data[++(q->rear)],q->data[++(q->front)]);
}
// 메인
int main(void){
    QueueType q;
    init_queue(&q);

    char item[50];
    int num;

    while(1) {
        scanf("%d", &num);
        if (num == 4)
            break;

        switch(num) {
            case 1 :
                scanf("%s", item);
                enqueue(&q, item);
                break;
            case 2 :
                dequeue(&q);
                break;
            case 3 :
                display(&q);
                break;
        }
    }
}