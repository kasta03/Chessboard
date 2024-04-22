#include <stdio.h>

int main()
{
    int x=-1431328341,y=599501227;
    // printf("Podaj 1 liczbe: \n");
    // scanf("%d",&x);
    // printf("Podaj 2 liczbe: \n");
    // scanf("%d",&y);
    unsigned int size=sizeof(int)* __CHAR_BIT__;
    unsigned int mask=~((~0)<<(size/2));
    int a,b;
    a=x&mask;
    b=y&mask;
    if (a==b)
    printf("a=b\n");
    else
    printf("a!=b\n");
    printf("%d\n",mask);
    printf ("%d   %d\n",a,b);
}