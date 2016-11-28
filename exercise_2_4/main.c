#include <stdio.h>

int main(void)
{
    int score;

    printf("enter result 0-100 (int): ");
    scanf("%d",&score);

    if ( score >= 75 )
    {
        printf("%d, you passed \n",score );
    }
    else
    {
        printf("%d, you failed \n",score  );
    }
    return 0;
}
