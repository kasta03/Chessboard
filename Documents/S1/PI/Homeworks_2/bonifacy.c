#include <stdio.h>

int Fib(int n)
    {
    static int x=0;
    printf("numer wywołania: %d\n",x);
    x++;
    if (n==0)
    return 0;
    else if (n==1)
    return 1;
    else 
    {
    return Fib(n-1)+Fib(n-2);
    }
    }

void main(void)
    {
    int x;
    scanf("%d",&x);
    Fib(x);
    printf("%d\n",x);
    }
