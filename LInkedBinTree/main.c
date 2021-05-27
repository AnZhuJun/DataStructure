#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

#define MaxSize 7

typedef struct Node{
    ElemType data;
    struct Node *lchild,*rchild;
}BTNode;

BTNode *CreateBTree(ElemType *a)
{
    BTNode *St[MaxSize],*p,*b;
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
                p->lchild = p->rchild = NULL;
                if(b==NULL)
                    b=p;
                else
                {
                    switch (k)
                    {
                        case 1:St[top]->lchild = p;
                            break;
                        case 2:St[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = a[j];
    }

    return b;
}

void Display(BTNode *b)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            Display(b->lchild);
            if(b->rchild != NULL)
                printf(",");
            Display(b->rchild);
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
        p = FindNode(b->lchild, x);
        if(p!=NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

int Height(BTNode *b)
{
    int lchild,rchild;
    if(b==NULL)
        return 0;
    else
    {
        lchild = Height(b->lchild);
        rchild = Height(b->rchild);
        return (lchild > rchild)?(lchild + 1):(rchild + 1);
    }
}

int main() {
    BTNode *b,*c;
    b = CreateBTree("A(B(D(,G)),C(E,F))");
    printf("%d\n",Height(b));

    Display(b);
    printf("\n");
    c = FindNode(b,'A');


    return 0;
}
