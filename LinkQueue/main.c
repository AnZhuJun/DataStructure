#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

typedef struct lnode{
    ElemType data;
    struct lnode *next;
}DataNode;

typedef struct{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;

void InitQueue(LinkQuNode *q)
{
//    q = (LinkQuNode *)malloc(sizeof (LinkQuNode));
    q->front = q->rear = NULL;
}

void Destroy(LinkQuNode *q)
{
    DataNode *pre= q->front,*p;
    if(pre!=NULL)
    {
        p = pre->next;
        while(p!=NULL)
        {
            free(pre);
            pre = p;
            p = p->next;
        }
        free(pre);
    }
    free(q);
}

int IsEmpty(LinkQuNode *q)
{
    return q->rear == NULL;
}

void EnQueue(LinkQuNode *q,ElemType value)
{
    DataNode *s;
    s = (DataNode *)malloc(sizeof(DataNode));
    s->data = value;
    s->next = NULL;

    if(q->rear == NULL)
        q->rear = q->front = s;
    else
    {
        q->rear->next = s;
        q->rear = s;
    }
}

int DeQueue(LinkQuNode *q,ElemType *value)
{
    DataNode *s;
    s = q->front;

    if(q->rear == NULL)
        return 0;

    if(s->next == NULL)
        q->front = q->rear = NULL;
    else
    {
        q->front = q->front->next;
    }

    *value = s->data;
    printf("%c \n",*value);
    free(s);
    return 1;
}

int main() {
    LinkQuNode q;
    ElemType value[]="abcde";
    ElemType a;

    InitQueue(&q);

    for(int i = 0;i<strlen(value);i++)
        EnQueue(&q,value[i]);

    while(!IsEmpty(&q))
        DeQueue(&q,&a);

    return 0;
}
