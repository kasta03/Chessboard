#include <stdio.h>

unsigned int count1(unsigned int p)
{
    unsigned int licznik=0;
    while (p>0)
    {
        if (p%2==1)
        {licznik++;}
        p>>=1;
    }
    return licznik;
}
int main ()
{
    unsigned int p=2071;
    printf ("Liczba jedynek =%d, dla p=%d\n",count1(p),p);
    return 0;
}