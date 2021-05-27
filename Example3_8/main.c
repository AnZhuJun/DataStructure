#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

typedef struct lnode{
    ElemType data;
    struct lnode *next;
}LinkNode;

void Init(LinkNode *rear)
{
    rear = NULL;
}

void EnQueue(LinkNode *rear,ElemType data)
{
    LinkNode *p;
    p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = data;

    if(rear == NULL)
    {
        p->next = p;
        rear = p;
    }
    else
    {
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

int DeQueue(LinkNode *rear,ElemType *value)
{
    LinkNode *s;

    if(rear == NULL)
        return 0;
    else if(rear->next == rear)
    {
        *value = rear->data;
        free(rear);
        rear = NULL;
    }
    else
    {
        s = rear->next;
        *value = s->data;
        rear->next = s->next;
        free(s);
    }

    printf("dequeue %c \n",*value);
    return 1;
}

int IsEmpty(LinkNode *rear)
{
    return rear == NULL;
}

int main() {
    LinkNode rear;
    ElemType value[]="abcde";
    ElemType a;

    Init(&rear);

    for(int i = 0; i < strlen(value);i++)
    {
        EnQueue(&rear,value[i]);
    }

    while(!IsEmpty(&rear))
        DeQueue(&rear,&a);

    return 0;
}
