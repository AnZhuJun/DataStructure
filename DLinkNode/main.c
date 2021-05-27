#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DLinkNode;

void CreateF(DLinkNode *L,ElemType a[],int n)
{
    DLinkNode *s;
//    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->next = L->prior = NULL;

    for(int i = 0;i<n;i++)
    {
        s = (DLinkNode *)malloc(sizeof (DLinkNode));
        s->data = a[i];
        s->next = L->next;

        if(L->next != NULL)
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }
}

void Display(DLinkNode *L)
{
    DLinkNode *s = L;
    while(s!=NULL)
    {
        printf("%c ",s->data);
        s = s->next;
    }

    printf("\n");
}

void CreateR(DLinkNode *L,ElemType a[],int n)
{
    DLinkNode *s,*p;
    L->next = L->prior = NULL;
    p = L;

    for(int i = 0;i<n;i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        p->next = s;
        s->prior = p;
        p = s;
    }

    p->next = NULL;
}

int length(DLinkNode *L)
{
    DLinkNode *s;
    int i = 0;
    s = L->next;

    while(s!=NULL)
    {
        i++;
        s = s->next;
    }

//    printf("length is %d \n",i);
    return i;
}

int Insert(DLinkNode *L,ElemType a,int index)
{
    DLinkNode *s,*p;
    p = L;

    if(index <= 0 || index > length(L) + 1)
        return 0;

    for(int i = 0;i<index-1;i++)
    {
            p = p->next;
    }

    if(p==NULL)
        return 0;
    else
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a;
        s->next = p->next;
        if(p->next!=NULL)
            p->next->prior = s;
        p->next = s;
        s->prior = p;
        return 1;
    }
}

int Delete(DLinkNode *L,int index,ElemType *value)
{
    DLinkNode *s,*p;
    p = L;

    if(index <= 0 || index > length(L))
        return 0;

    for(int i = 0; i < index - 1;i++)
    {
        p = p->next;
    }

    if(p!=NULL)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        *value = p->next->data;
        s = p->next;
        p->next = s->next;
        s->next->prior = p;
        free(s);
        printf("delete index of %d value is %c\n",index,*value);
    }
}

int DeleteByValue(DLinkNode *L,ElemType value)
{
    DLinkNode *s,*p;
    p = L;

    while(p->next!=NULL)
    {
        if(p->next->data == value)
        {
            s = p->next;
            if(s == NULL)
                return 0;
            p->next = s->next;
            if(p->next!=NULL)
                p->next->prior = p;
            free(s);
        }

        if(p->next!=NULL)
            p = p->next;
    }
    return 1;
}

int main() {
    DLinkNode L;
    char a[] = "abcd";
    char value;
    CreateF(&L,a,4);

    Display(&L);

    Insert(&L,'k',3);
    Display(&L);
    Insert(&L,'k',1);
    Display(&L);
    Insert(&L,'k',6);
    Display(&L);
    Insert(&L,'k',8);
    Display(&L);

    Delete(&L,2,&value);
    Display(&L);

    DeleteByValue(&L,'k');
    Display(&L);

    return 0;
}
