#include <stdio.h>

int main(void)
{

//Skriv ett program som skriver ut bokst�verna a-z i gemener p� en rad,
//i VERSALER p� en annan rad och
//siffrorna 0-9 p� en tredje.
//Anv�nd putchar, printf �r f�rbjudet.

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

