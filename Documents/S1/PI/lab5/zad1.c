#include <stdio.h>



int main ()
{
    int a,b,c,d,e;
    scanf("%d%d",&a,&b);
    c=4294901760;
    d=a|c;
    e=b|c;
    if (d==e)
    printf ("Tak\n");
    else 
    
    printf ("Nie");
    return 0;
}