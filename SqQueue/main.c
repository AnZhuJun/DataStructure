#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 5
typedef char ElemType;

typedef struct {
    ElemType data[Maxsize];
    int front;
    int rear;
}SqQueue;

void Init(SqQueue *Q)
{
//    Q = (SqQueue *)malloc(sizeof (SqQueue));
    Q->rear = Q->front = -1;
}

int IsEmpty(SqQueue *Q)
{
    return (Q->front == Q->rear);
}

int enQueue(SqQueue *Q,ElemType value)
{
    if(Q->rear == Maxsize - 1)
        return 0;

    Q->rear++;
    Q->data[Q->rear] = value;
    return 1;
}

int deQueue(SqQueue *Q,ElemType *value)
{
    if (Q->rear == Q->front)
        return 0;

    Q->front++;
    *value = Q->data[Q->front];
    printf("dequeue %c \n",*value);
    return 1;
}

int main() {
    SqQueue Q;
    ElemType value;
    ElemType a[] = "abcde";

    Init(&Q);
    for(int i = 0;i<strlen(a);i++)
    {
        enQueue(&Q,a[i]);
    }

    while(!IsEmpty(&Q))
    {
        deQueue(&Q,&value);
    }

    return 0;
}
