#include<stdio.h>

long power(long  u, long v)
{

    long p , i;
    p=1;
    for (i = 1; i <= v; ++i)
    {
        p = p * u;
    }

    return p;
}
int main()
{
    long  a,b;
    scanf("%ld",&a);
    scanf("%ld",&b);
    long  temp,last,final;
    temp=a;
     final=0;
    while(temp!=0){
        last=temp%10;
        final=final+power(last,b);
        temp=temp/10;

        
    }

    printf("%ld",final);

    return 0;

    }

   
