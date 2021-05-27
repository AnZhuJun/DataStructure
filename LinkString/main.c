#include <stdio.h>
#include <stdlib.h>

typedef struct snode{
    char data;
    struct snode *next;
}LinkStrNode;

void StrAssign(LinkStrNode *s,char str[])
{
    LinkStrNode *p=s,*q;

    for(int i = 0 ;str[i]!='\0';i++)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = str[i];
        p->next = q;
        p = q;
    }

    p->next = NULL;
}

void DisPlay(LinkStrNode s)
{
    LinkStrNode *p = s.next;

    while(p != NULL)
    {
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}

void DisPlay2(LinkStrNode *s)
{
    LinkStrNode *p = s->next;

    while(p != NULL)
    {
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}

void Destroy(LinkStrNode *s)
{
    LinkStrNode *pre = s,*p = s->next;

    while (p!=NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }

    free(pre);
}

void Copy(LinkStrNode *s1,LinkStrNode s2)
{
    LinkStrNode *p = s2.next,*q,*r;

    r = s1;
    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof (LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
}

int Equal(LinkStrNode s1,LinkStrNode s2)
{
    LinkStrNode *p = s1.next,*q = s2.next;

    while(p!=NULL && q != NULL && p->data == q->data)
    {
        p = p->next;
        q = q->next;
    }

    if(p == NULL && q == NULL)
    {
        printf("相同\n");
        return 1;
    }
    else
    {
        printf("不相同\n");
        return 0;
    }
}

int Length(LinkStrNode s)
{
    LinkStrNode *p = s.next;
    int length = 0;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }

    printf("length is %d \n",length);
    return length;
}

LinkStrNode *Concat(LinkStrNode s1,LinkStrNode s2)
{
    LinkStrNode *str,*p = s1.next,*q,*r;

    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = str;
    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    p = s2.next;
    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof (LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *SubStr(LinkStrNode s,int i,int j)
{
    LinkStrNode *p = s.next,*str,*r,*q;

    str = (LinkStrNode *)malloc(sizeof (LinkStrNode));
    r = str;

    if(i<=0 || j>Length(s))
        return str;

    for(int k=0;k<i-1;k++)
    {
        p = p->next;
    }

    for(int k=i;k<=j;k++)
    {
        q = (LinkStrNode *)malloc(sizeof (LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    r->next = NULL;
    return str;

}

LinkStrNode *Insert(LinkStrNode s1,int i,LinkStrNode s2)
{
    LinkStrNode *str,*p=s1.next,*q,*r,*p1 = s2.next;
    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = str;

    if(i<=0 || i>Length(s1))
        return str;

    for(int k=1;k<i;k++)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    while (p1!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof (LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    r->next = NULL;
    return str;
}

//从i开始删除j个节点
LinkStrNode *Delete(LinkStrNode s,int i,int j)
{
    LinkStrNode *str,*r,*p = s.next,*q;
    str = (LinkStrNode *)malloc(sizeof (LinkStrNode));
    r = str;

    if(i<=0 || j >Length(s) || i + j -1 > Length(s))
        return str;

    for(int k=1;k<i;k++)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    for(int k=0;k<j;k++)
        p = p->next;

    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    r->next = NULL;
    return str;
}

//将s1从i开始的j个字符用s2代替
LinkStrNode *RepStr(LinkStrNode s1,int i,int j,LinkStrNode s2)
{
    LinkStrNode *str,*p = s1.next,*p1 = s2.next,*r,*q;

    str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next = NULL;
    r = str;

    if(i <= 0 || j > Length(s1) || i + j - 1>Length(s1))
        return str;

    for(int k = 0;k<i-1;k++)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }

    for(int k=0;k<j;k++)
        p = p->next;

    while(p1!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof (LinkStrNode));
        q->data = p1->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    while(p!=NULL)
    {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }

    r->next = NULL;
    return str;
}

int main() {
    LinkStrNode s,s1,s2,*s3;
    char str[] = "abcde";
    char str2[] = "qwe";

    StrAssign(&s,str);
    StrAssign(&s2,str2);
    DisPlay(s);
    Copy(&s1,s);
    DisPlay(s1);
    Equal(s,s2);
    Length(s);
    Length(s2);

    s3 = Concat(s1,s2);
    DisPlay2(s3);

    s3 = SubStr(s1,2,5);
    DisPlay2(s3);

    s3 = Insert(s,2,s2);
    DisPlay2(s3);

    s3 = Delete(s,2,2);
    DisPlay2(s3);

    s3 = RepStr(s,2,2,s2);
    DisPlay2(s3);

    return 0;
}
