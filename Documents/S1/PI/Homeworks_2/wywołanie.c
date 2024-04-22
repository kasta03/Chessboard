#include <stdio.h>
void funkcja(void)
{
    static int x=1;
    printf("Wywołanie: %d\n",x);
    x++;
}

int main(void)
{
    for (int i=0; i<5;i++)
    {
    funkcja();
    }
    return 0;
}