#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losuj(char *t, int n)
{
    for (int i=0; i<n; i++)
    {
        t[i]='0'+(rand() % 8);
    }
}
void wypisz(char *t)
{
    for (int i=0; i<10; i++)
    {
        printf("%o\n",t[i]);
    }
}
int main()
{
    int n=6;
    srand(time(0));
    char tab[] = "000000";
    losuj(tab,n);
    wypisz(tab);
}