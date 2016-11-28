#include <stdio.h>

int main(void)
{

//Skriv ett program som skriver ut bokstäverna a-z i gemener på en rad,
//i VERSALER på en annan rad och
//siffrorna 0-9 på en tredje.
//Använd putchar, printf är förbjudet.

int i;
for (i='a'; i<='z'; i++)
{
    putchar(i);
};
putchar('\n');
for (i='A'; i<='Z'; i++)
{
    putchar(i);
};
putchar('\n');
for (i='0'; i<='9'; i++)
{
    putchar(i);
};
putchar('\n');


//return(0);

const char message[] = "abcdefghijklmnopqrstuvxyz\nABCDEFGHIJKLMNOPQRSTUVXYZ\n0123456789\0";
for ( i=0; i<strlen(message); i++)
    putchar(message[i]);


return(0);
}
const char message[] = "abcdefghijklmnopqrstuvxyz\nABCDEFGHIJKLMNOPQRSTUVXYZ\n0123456789\0";
char *c = message;
while (&c==0)
    putchar(c++);


return(0);
}

