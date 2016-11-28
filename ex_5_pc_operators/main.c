#include <stdio.h>
#define LENGTH 39
#define OP(a,o,b) (a o b)

// op() callable operator, so we can iterate over it
char op(char a, char o, char b)
{
    switch (o)
    {
    case '+' :
        return(a+b); // only signed char bitwise ops
    case '-' :
        return(a-b);
    case '*' :
        return(a*b);
    case '/' :
        return(a/b);
    case '&' :
        return(a&b);
    case '|' :
        return(a|b);
    case '^' :
        return(a^b);
    case '~' :
        return(~a);
    case '>' :
        return(a>>b);
    case '<' :
        return(a<<b);
    default  :
        return(a?a:b); // well, has to default to something
    }
}
float letter_frequency[256]= {0.0};
void letter_frequency_init(void)
{
    letter_frequency['E']= 12.02;
    letter_frequency['T']= 9.10;
    letter_frequency['A']=  8.12;
    letter_frequency['O']=  7.68;
    letter_frequency['I']=  7.31;
    letter_frequency['N']=  6.95;
    letter_frequency['S']=  6.28;
    letter_frequency['R']=  6.02;
    letter_frequency['H']=  5.92;
    letter_frequency['D']=  4.32;
    letter_frequency['L']=  3.98;
    letter_frequency['U']=  2.88;
    letter_frequency['C']=  2.71;
    letter_frequency['M']=  2.61;
    letter_frequency['F']=  2.30;
    letter_frequency['Y']=  2.11;
    letter_frequency['W']=  2.09;
    letter_frequency['G']=  2.03;
    letter_frequency['P']=  1.82;
    letter_frequency['B']=  1.49;
    letter_frequency['V']=  1.11;
    letter_frequency['K']=  0.69;
    letter_frequency['X']=  0.17;
    letter_frequency['Q']=  0.11;
    letter_frequency['J']=  0.10;
    letter_frequency['Z']=  0.07;
}
double weighed_sum_of_letters( char c[] )
{
    double sum=0.0;
    int i;
    letter_frequency_init();
    for ( i=0; i<sizeof(c); i++ )
    {
        sum += letter_frequency[(unsigned int)c[i]&('a'-'A')]; / lower case
    }
    return(sum);
}
int main(void)
{
    char message[] = { 254, 200, 206, 194, 195, 201, 141, 222, 217, 204, 202, 200, 141, 193, 204, 216,
                       195, 206, 197, 141, 206, 194, 201, 200, 141, 196, 222, 141, 156, 202, 225, 229,
                       200, 244, 194, 218, 147, 228, 0
                     };

    char *c=message;
    int i=0,oi,ci;
    unsigned int a=0;
    unsigned char cc,pc;
    int freq[256]= {0};
    char ops[] = "-^><+*/\\&|~\0"; //
    char try_op ='^';
    char most_common[7] = { ' ', 'e', 't', 'a', 'o', 'i', 'n' };
    char result[1024]= {'\0'};

    // calculate character frequency table
    for ( i=0; i<LENGTH; i++ )
    {
        a=(unsigned int)message[i]&0xff;
        freq[a]=freq[a]+1;
        cc = message[i];
        pc =  (message[i]>>0)^0xaa;
        //printf( "%2d %02x %02x %c \n", i, cc, pc, pc );
    }
    // find the most frequent character
    int max=-1, most_frequent = 0;
    for ( i=0; i<256; i++ )
    {
        //printf( "%2d %02x %d \n", i, freq[i], freq[i] );
        if ( freq[i] >= max)   // well, can be several
        {
            max = freq[i];
            most_frequent = i;
        }
    }
    // iterate over most common characters
    // and most common operators
    // for now, asumme the most frequent is ' ' = 0x20
    char target = 0x20; // space ' ', if not - try with other common characters
    for ( ci=0; ci<sizeof(most_common); ci++ )
    {
        for ( oi=0; ci<sizeof(ops); oi++ )
        {
            target=most_common[ci];
            try_op=ops[oi];
            printf( "most frequent value %02x, try with %02x and op %c\n", most_frequent, target, try_op );
            for ( i=0; i<LENGTH; i++ )
            {
                //pc =  (message[i]>>0)^(most_frequent^target);
                pc =  op(message[i],try_op,op(most_frequent,try_op,target));
                result[i]=pc;
                if ( pc>7 && pc <127)
                {
                    printf( "%c", pc );
                }
            }
            printf("\n");
            printf("probability (weighed sum) %f \n",weighed_sum_of_letters(result)/(i-1)*100);
        }
        if ( weighed_sum_of_letters(result)/(i-1)*100 > 10 )
        {
            break;
        }
    }
    // how to make a guess if the result is correct
    // try, weighted sum of characters. sum(prob(c))
    //
    return 0;
}


/*



https://www.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html

Letter  Count           Letter  Frequency
E       21912           E       12.02
T       16587           T       9.10
A       14810           A       8.12
O       14003           O       7.68
I       13318           I       7.31
N       12666           N       6.95
S       11450           S       6.28
R       10977           R       6.02
H       10795           H       5.92
D       7874            D       4.32
L       7253            L       3.98
U       5246            U       2.88
C       4943            C       2.71
M       4761            M       2.61
F       4200            F       2.30
Y       3853            Y       2.11
W       3819            W       2.09
G       3693            G       2.03
P       3316            P       1.82
B       2715            B       1.49
V       2019            V       1.11
K       1257            K       0.69
X       315             X       0.17
Q       205             Q       0.11
J       188             J       0.10
Z       128             Z       0.07





*/
