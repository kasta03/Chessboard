#include <stdio.h>

void f6(void)
{
    static int x=100;
    printf("Funkcja f6() - odliczanie: %d\n",x);
    x--;
}
int main ()
{
    for (int i=0;i<=7;i++)
    f6();
}