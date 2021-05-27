#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef struct{
    char data[Maxsize];
    int length;
}SqString;

void StringAssign(SqString *S,char cstr[])
{
    int i;
    for(i = 0;cstr[i]!='\0';i++)
    {
        S->data[i] = cstr[i];
    }

    S->length = i;
}

void Display(SqString S)
{
    for(int i = 0;i<S.length;i++)
    {
        printf("%c ",S.data[i]);
    }

    printf("\n");
}

void StrCopy(SqString *s1,SqString s2)
{
    int i;
    s1->length = s2.length;
    for(i=0;i<s2.length;i++)
    {
        s1->data[i] = s2.data[i];
    }
}

int StrEqual(SqString s1,SqString s2)
{
    int flag = 1;

    if (s1.length != s2.length)
        flag = 0;
    else
    {
        for(int i = 0;i<s1.length;i++)
        {
            if(s1.data[i] != s2.data[i])
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 0)
    {
        printf("they are dislike\n");
    }
    else
    {
        printf("same\n");
    }
}

void StrConcat(SqString *s1,SqString s2)
{
    for(int i = s1->length;i<s1->length + s2.length;i++)
    {
        s1->data[i] = s2.data[i - s1->length];
    }

    s1->length = s1->length + s2.length;
}

SqString SubStr(SqString s1,int i,int j)
{
    SqString s;
    s.length = j-i;

    for(int k = i;k<j;k++)
    {
        s.data[k-i] = s1.data[k];
    }

    return s;
}

SqString StrIns(SqString s1,int index,SqString s2)
{
    SqString s;
    s.length = 0;

    if(index <= 0 || index > s1.length+1)
    {
        return s;
    }

    for(int i = 0;i<index;i++)
    {
        s.data[i] = s1.data[i];
    }

    for(int i = index;i<index + s2.length;i++)
    {
        s.data[i] = s2.data[i-index];
    }

    for(int i = index + s2.length;i<s1.length + s2.length;i++)
    {
        s.data[i] = s1.data[i - s2.length];
    }

    s.length = s1.length + s2.length;
    return s;
}

SqString StrDel(SqString s,int i,int j)
{
    SqString s1;

    for(int m = 0;m<i;m++)
    {
        s1.data[m] = s.data[m];
    }

    for(int n = j;n<s.length;n++)
    {
        s1.data[n-j+i] = s.data[n];
    }

    s1.length = s.length - (j-i);
    return s1;
}

SqString StrRep(SqString s1,int i,int j,SqString s2)
{

}

int main() {
    SqString S1;
    SqString S2;
    char a[]="abcde";
    char b[]="edcba";

    StringAssign(&S1,a);
    StringAssign(&S2,b);
    Display(S1);
    Display(S2);

    StrEqual(S1,S2);

    StrCopy(&S1,S2);
    Display(S1);

    StrEqual(S1,S2);

    StrConcat(&S1,S2);
    Display(S1);

    S1 = SubStr(S1,2,6);
    Display(S1);

    S1 = StrIns(S1,3,S2);
    Display(S1);

    S1 = StrDel(S1,1,4);
    Display(S1);

    return 0;
}
