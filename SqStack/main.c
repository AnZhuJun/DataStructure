#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef char ElemType;

typedef struct {
    ElemType data[Maxsize];
    int top;
}SqStack;

void Init(SqStack *S)
{
    S = (SqStack *)malloc(sizeof(SqStack));
    S->top = -1;
}

int IsEmpty(SqStack *S)
{
    return S->top == -1;
}

int Push(SqStack *S, ElemType a)
{
    if (S->top == Maxsize-1)
        return 0;

    S->top++;
    S->data[S->top] = a;
    return 1;
}

void Display(SqStack *S)
{
    int i = S->top;
    while(!IsEmpty(S) && i>=0)
    {
        printf("%c ",S->data[i]);
        i--;
    }
    printf("\n");
}

int Pop(SqStack *S,ElemType *value)
{
    if(IsEmpty(S))
        return 0;

    *value = S->data[S->top--];
    printf("pop %c \n",*value);
    return 1;
}

int Peek(SqStack *S,ElemType *value)
{
    if(IsEmpty(S))
        return 0;

    *value = S->data[S->top];
    printf("peek %c \n",*value);
}

int main() {
    SqStack S;
    Init(&S);
    char value;

    Push(&S, 'a');
    Push(&S, 'b');
    Push(&S, 'c');
    Push(&S, 'd');

    Display(&S);

    Pop(&S,&value);
    Display(&S);

    Peek(&S,&value);
    Display(&S);

    return 0;
}
