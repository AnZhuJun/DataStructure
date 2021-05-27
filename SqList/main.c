#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 100
typedef char ElemType;

typedef struct {
    ElemType data[Maxsize];
    int length
}SqList;

void Init(SqList *L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

int length(ElemType a[])
{
    int i = 0;
    while(a[i])
    {
        i++;
    }

    return i;
}

void Create(SqList *L,ElemType a[],int n){
    if(n > length(a))
    {
        n = length(a);
    }

    for(int i=0;i<n;i++)
    {
        L->data[i] = a[i];
    }

    L->length = n;
}

void Print(SqList *L)
{
    int i = L->length;
    for(int j =0 ;j < i;j++)
    {
        printf(" %c",L->data[j]);
    }
    printf("\n");
}

int isEmpty(SqList *L)
{
    return L->length == 0;
}

int GetElemByIndex(SqList *L,int index,ElemType *value)
{
    if(index < 1 || index > L->length)
        return 0;

    *value = L->data[index-1];
    printf("the value in index of %d is %c \n",index,*value);
    return 1;
}

int GetElemByValue(SqList *L,ElemType value)
{
    for(int i = 0;i<L->length;i++)
    {
        if(L->data[i] == value)
        {
            printf("the index of value %c is %d \n",value,i+1);
            return 1;
        }
    }

    printf("the data value %c not exist \n",value);
    return 0;
}

int insert(SqList *L,int index,ElemType value)
{
    if(index < 1 || index > L->length)
        return 0;

    for(int i = L->length ;i >= index;i--)
    {
        L->data[i] = L->data[i-1];
    }

    L->data[index-1] = value;
    L->length++;
    return 1;
}

int DeleteByValue(SqList *L,ElemType Value)
{
    for(int i = 0;i<L->length;i++)
    {
        if(L->data[i] == Value )
        {
            for(int j = i;j < L->length-1;j++)
            {
                L->data[j] = L->data[j+1];
            }
            L->length--;
        }
    }
}

int DeleteByIndex(SqList *L,int index)
{
    if(index < 1 || index > L->length)
        return 0;

    index--;
    for(int i = index;i<L->length-1;i++)
    {
        L->data[i] = L->data[i+1];
    }
    L->length--;

    return 1;
}

int main() {
    char a[] ="abcdaca";
    char value;
    SqList L;
    Init(&L);
    Create(&L,a,7);
    Print(&L);
    GetElemByIndex(&L,2,&value);
    insert(&L,2,'l');
    Print(&L);

    GetElemByValue(&L,'a');

    DeleteByValue(&L,'a');
    Print(&L);

    DeleteByIndex(&L,2);
    Print(&L);
    return 0;
}
