#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

#define MaxSize 7

typedef struct Node{
    ElemType data;
    struct Node *prior;
    struct Node *next;
}BTNode;

void CreateBTree(BTNode *b,ElemType a[])
{
    BTNode *St[MaxSize],*p;
    int top = -1,k,j=0;
    char ch;
    b = NULL;
    ch = a[j];

    while(ch!='\0')
    {
        switch (ch)
        {
            case '(':
                top++;
                St[top]=p;
                k=1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k=2;
                break;
            default:
                p = (BTNode *)malloc(sizeof (BTNode));
                p->data = ch;
                p->prior = p->next = NULL;
                if(b==NULL)
                    b=p;
                else
                {
                    switch (k)
                    {
                        case 1:St[top]->prior = p;
                            break;
                        case 2:St[top]->next = p;
                            break;
                    }
                }
        }
        j++;
        ch = a[j];
    }
}

void Display(BTNode *b)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->prior != NULL || b->next != NULL)
        {
            printf("(");
            Display(b->prior);
            if(b->next != NULL)
                printf(",");
            Display(b->next);
            printf(")");
        }
    }
}

BTNode *FindNode(BTNode *b, ElemType x)
{
    BTNode *p;
    if(b == NULL)
        return NULL;
    else if(b->data == x)
    {
        printf("%c\n",b->data);
        return b;
    }
    else
    {
        p = FindNode(b->prior, x);
        if(p!=NULL)
            return p;
        else
            return FindNode(b->next, x);
    }
}


int main() {
    BTNode b,*c;
    CreateBTree(&b,"A(B(D(,G)),C(E,F))");
    Display(&b);
//    c = FindNode(&b,'A');

    return 0;
}
