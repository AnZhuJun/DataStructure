#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkStack;

void Init(LinkStack *S)
{
//    S = (LinkStack *)malloc(sizeof(LinkStack));
    S->next = NULL;
}

void Push(LinkStack *S,ElemType a)
{
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));

    p->data = a;
    p->next = S->next;
    S->next = p;
}

int IsEmpty(LinkStack *S)
{
    return S->next == NULL;
}

void Display(LinkStack *S)
{
    LinkStack *p;
    p = S->next;

    while(!IsEmpty(p))
    {
        printf("%c ",p->data);
        if(p->next == NULL)
            break;
        p = p->next;
    }
    printf("\n");
}

void Pop(LinkStack *S)
{
    LinkStack *p;
    if(IsEmpty(S))
        exit(0);

    p = S->next;
    S->next = p->next;
    printf("pop %c \n",p->data);
    free(p);
}

int main() {
    LinkStack S;

    Init(&S);
//    S.next = NULL;
    Push(&S,'a');
    Push(&S,'b');
    Push(&S,'c');

    while(!IsEmpty(&S))
        Pop(&S);
    return 0;
}
