#include <stdio.h>


// UTF-8

int len(const char *p)
{
    int i=0;
    while ( (*p)!=0 )
    {
        p++;
        i++;
    }
    return(i);
}

int main()
{
    char s[1024]= {0};
    int i=0, result, x=0;
    char *p=s;

    printf("input string : ");

    do
    {
        result=scanf("%s",p);
        p = p + len(p);
    }
    while (result && (p-1)!='\032');

    while ( (*p)!=0 )
    {
        p++;
        i++;
    }

    printf("length %d equals %d\n",i,strlen(s));

    return 0;
}

/*
int main()
{
    char s[1024]={0};
    int i=0, result, x=0;
    printf("input string : ");

    result=scanf("%s",&s);

    while ( result>0 && s[i]!=0 ) { i++; x++; }

    printf("length %d \n",x);

    return 0;
}
*/
