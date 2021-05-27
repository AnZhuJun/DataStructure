#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxsize 5

typedef char ElemType;

typedef struct{
    ElemType data[Maxsize];
    int front,rear;
}CircularQueue;

void Init(CircularQueue *Q)
{
    Q->rear = Q->front = 0;
}

int IsEmpty(CircularQueue *Q)
{
    return (Q->front == Q->rear);
}

int EnQueue(CircularQueue *Q,ElemType value)
{
    if((Q->rear + 1)%Maxsize == Q->front)
        return 0;

    Q->rear = (Q->rear + 1)%Maxsize;
    Q->data[Q->rear] = value;
    return 1;
}

int DeQueue(CircularQueue *Q,ElemType *value)
{
    if(Q->front == Q->rear)
        return 0;

    Q->front = (Q->front + 1)%Maxsize;
    *value = Q->data[Q->front];
    printf("dequeue %c \n",*value);
    return 1;
}

int main() {
    CircularQueue Q;
    ElemType a[] = "abcdef";
    ElemType value;

    Init(&Q);

    for(int i = 0 ; i < strlen(a);i++)
    {
        EnQueue(&Q,a[i]);
    }

    while(!IsEmpty(&Q))
    {
        DeQueue(&Q,&value);
    }

    return 0;
}
