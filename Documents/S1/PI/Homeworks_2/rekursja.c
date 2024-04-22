#include <stdio.h>

int rekursja(int x, int a, int b, int c)
    {
    if (x==1)
    return a;
    else if (x==2)
    return b;
    else if (x==3)
    return c;
    else 
    return rekursja(x-1,a,b,c)+rekursja(x-2,a,b,c)+rekursja(x-3,a,b,c);
    }
int main ()
    {
        int n,a=3,b=7,c=2;
        scanf ("%d",&n);
        printf ("%d element szeregu jest równy %d\n",n, rekursja (n,a,b,c));
        return 0;
    }