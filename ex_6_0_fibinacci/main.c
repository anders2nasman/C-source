#include <stdio.h>
#include <stdlib.h>


const unsigned long long int fib_c[] = {
1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,
46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,
14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,
1134903170,1836311903,2971215073,512559680,3483774753,3996334433,3185141890,2886509027,
1776683621,368225352,2144908973,2513134325,363076002,2876210327,3239286329,1820529360,
764848393,2585377753,3350226146,1640636603,695895453,2336532056,3032427509,1073992269,
4106419778,885444751,696897233,1582341984,2279239217,3861581201,1845853122,1412467027,
3258320149,375819880,3634140029,4009959909,3349132642,3064125255,2118290601,887448560,
3005739161,3893187721,2603959586,
2202180011,511172301,2713352312,3224524613,1642909629,572466946,2215376575,2787843521 };

unsigned long long int fib(unsigned long int x)
{
    int i=0;
    unsigned long long int n[2]= {1,1}, sum=1;
    for (i=2; i<=x; i++)
    {
        sum=n[0]+n[1];
        n[0]=n[1];
        n[1]=sum;
    }
    return( sum );

}

double fib_d(unsigned int x)
{
    int i=0;
    double n[2]= {1,1}, sum=1;
    for (i=2; i<=x; i++)
    {
        sum=n[0]+n[1];
        n[0]=n[1];
        n[1]=sum;
    }
    return( sum / (double) n[0] );

}

unsigned long long int fib_r(unsigned int n)
{
    if ( n <= 1 ) {
        return(1);
    } else if ( n < sizeof(fib_c) ) {
        return( fib_c[n] );
    } else {
        return fib_r(n-2)+fib_r(n-1);
    }
}

unsigned long long int fib_y(unsigned int n)
{
    static unsigned long long fib_c[4096]={0};
    if ( n <= 1 ) {
        return(1);
    } else if ( n < sizeof(fib_c) && fib_c[n]!=0 ) {
        return( fib_c[n] );
    } else if ( n < sizeof(fib_c) ) {
        fib_c[n] = fib_r(n-2)+fib_r(n-1);
        return( fib_c[n] );
    } else {
        return( fib_r(n-2)+fib_r(n-1) );
    }
}

int main()
{
    int i=0;
    printf("Fibonacci!\n");

    for (i=0; i<1000; i++)
    {
        printf("fib(%d) = %llu %llu %0.12f \n",i,fib(i),fib_r(i),fib_d(i));
    }

    return 0;
}

/*
fib(0) = 1 1
fib(1) = 1 1
fib(2) = 2 2
fib(3) = 3 3
fib(4) = 5 5
fib(5) = 8 8
fib(6) = 13 13
fib(7) = 21 21
fib(8) = 34 34
fib(9) = 55 55
fib(10) = 89 89
fib(11) = 144 144
fib(12) = 233 233
fib(13) = 377 377
fib(14) = 610 610
fib(15) = 987 987
fib(16) = 1597 1597
fib(17) = 2584 2584
fib(18) = 4181 4181
fib(19) = 6765 6765
fib(20) = 10946 10946
fib(21) = 17711 17711
fib(22) = 28657 28657
fib(23) = 46368 46368
fib(24) = 75025 75025
fib(25) = 121393 121393
fib(26) = 196418 196418
fib(27) = 317811 317811
fib(28) = 514229 514229
fib(29) = 832040 832040
fib(30) = 1346269 1346269
fib(31) = 2178309 2178309
fib(32) = 3524578 3524578
fib(33) = 5702887 5702887
fib(34) = 9227465 9227465
fib(35) = 14930352 14930352
fib(36) = 24157817 24157817
fib(37) = 39088169 39088169
fib(38) = 63245986 63245986
fib(39) = 102334155 102334155
fib(40) = 165580141 165580141
fib(41) = 267914296 267914296
fib(42) = 433494437 433494437
fib(43) = 701408733 701408733
fib(44) = 1134903170 1134903170
fib(45) = 1836311903 1836311903
fib(46) = 2971215073 2971215073
fib(47) = 512559680 512559680
fib(48) = 3483774753 3483774753
fib(49) = 3996334433 3996334433
fib(50) = 3185141890 3185141890
fib(51) = 2886509027 2886509027
fib(52) = 1776683621 1776683621

fib(53) = 368225352 368225352
fib(54) = 2144908973 2144908973
fib(55) = 2513134325 2513134325
fib(56) = 363076002 363076002
fib(57) = 2876210327 2876210327
fib(58) = 3239286329 3239286329
fib(59) = 1820529360 1820529360
fib(60) = 764848393 764848393
fib(61) = 2585377753 2585377753
fib(62) = 3350226146 3350226146
fib(63) = 1640636603 1640636603
fib(64) = 695895453 695895453
fib(65) = 2336532056 2336532056
fib(66) = 3032427509 3032427509
fib(67) = 1073992269 1073992269
fib(68) = 4106419778 4106419778
fib(69) = 885444751 885444751
fib(70) = 696897233 696897233
fib(71) = 1582341984 1582341984
fib(72) = 2279239217 2279239217
fib(73) = 3861581201 3861581201
fib(74) = 1845853122 1845853122
fib(75) = 1412467027 1412467027
fib(76) = 3258320149 3258320149
fib(77) = 375819880 375819880
fib(78) = 3634140029 3634140029
fib(79) = 4009959909 4009959909
fib(80) = 3349132642 3349132642
fib(81) = 3064125255 3064125255
fib(82) = 2118290601 2118290601
fib(83) = 887448560 887448560
fib(84) = 3005739161 3005739161
fib(85) = 3893187721 3893187721
fib(86) = 2603959586 2603959586
fib(87) = 2202180011 2202180011
fib(88) = 511172301 511172301
fib(89) = 2713352312 2713352312
fib(90) = 3224524613 3224524613
fib(91) = 1642909629 1642909629
fib(92) = 572466946 572466946
fib(93) = 2215376575 2215376575
fib(94) = 2787843521 2787843521


*/
