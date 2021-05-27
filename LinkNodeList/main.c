#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 50

typedef char ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;

void Init(LinkNode *L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void CreateF(LinkNode *L,ElemType a[],int n)
{
    LinkNode *s;
//    L=(LinkNode *)malloc(sizeof (LinkNode));
    L->next = NULL;

    for(int i=0;i<n;i++)
    {
        s = (LinkNode *)malloc(sizeof (LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateR(LinkNode *L,ElemType a[],int n)
{
    LinkNode *s,*r;
//    L->next = NULL;
    r = L;
    for(int i = 0 ;i<n;i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void Display(LinkNode *L)
{
    LinkNode *s;
    s = L->next;
    while(s!=NULL)
    {
        printf("%c ",s->data);
        s = s->next;
    }

    printf("\n");
}

int Length(LinkNode *L)
{
    LinkNode *s;
    int i = 0;
    s = L->next;

    while(s!=NULL)
    {
        i++;
        s = s->next;
    }
    printf("length is %d \n",i);
    return i;
}

int GetElemByIndex(LinkNode *L,int index,ElemType *value)
{
    LinkNode *s = L;
    if(index<=0 || index > Length(L))
        return 0;

    for(int i = 0; i < index ;i++)
    {
        s = s->next;
    }

    *value = s->data;
    printf("value of index %d is %c \n",index,*value);

    return 1;
}

int GetIndexByValue(LinkNode *L,ElemType value)
{
    LinkNode *s = L;
    int index = 0,flag = 0;

    while(s!=NULL)
    {
        if(s->data == value)
        {
            flag = 1;
            break;
        }
        else
        {
            s = s->next;
            index++;
        }
    }

    if(flag == 0)
    {
        printf("value %c not exist \n",value);
        return 0;
    }
    else
    {
        printf("value of %c in index %d \n",value,index);
        return 1;
    }
}

int DeleteByIndex(LinkNode *L,int index)
{
    LinkNode *s = L->next,*next;

    if(index <= 0 || index > Length(L))
        return 0;

    for(int i = 1;i<index-1;i++)
    {
        s = s->next;
    }

    if(s == NULL)
        return 0;
    else
    {
        next = s->next;
        if(next == NULL)
            return 0;
        s->next = next->next;
        return 1;
    }
}

int InsertF(LinkNode *L, ElemType value)
{
    LinkNode *s,*p = L;

    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = value;
    s->next = NULL;

    if(p == NULL)
    {
        p->next = s;
        return 1;
    }
    else
    {
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

int InsertR(LinkNode *L, ElemType Value)
{
    LinkNode *s,*p = L;

    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = Value;
    s->next = NULL;

    while(p->next != NULL)
    {
        p = p->next;
    }

    if(p!=NULL)
    {
        p->next = s;
        p = s;
        p->next = NULL;
        return 1;
    }
}

int InsertByIndex(LinkNode *L,int index,ElemType value)
{
    LinkNode *s,*p=L;

    for(int i = 0;i < index-1;i++)
    {
        p = p->next;
    }

    if(p == NULL)
        return 0;
    else
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = value;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

int main() {
    LinkNode L,L1;
    char a[] = "abcd";
    char value;

    Init(&L);
    Init(&L1);
    CreateF(&L,a,4);
    CreateR(&L1,a,4);
    Display(&L);
    Display(&L1);

    Length(&L);

    GetElemByIndex(&L,2,&value);
    GetIndexByValue(&L,'s');

    DeleteByIndex(&L,2);
    Display(&L);

    InsertF(&L, 'k');
    Display(&L);

    InsertR(&L, 's');
    Display(&L);

    InsertByIndex(&L,1,'z');
    Display(&L);

    return 0;
}
