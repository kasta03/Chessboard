#include <stdio.h>


int program (p)
{
    return p*p;
}
int main ()
{
    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d",&liczba);
    int *w;
    w=&liczba;
    printf("%d",*w);
    printf("\n%d",program(*w));
    return 0;
}