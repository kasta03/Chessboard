#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie(int tab[], int x)
    {
    for(int i=0; i<10; i++)
        {
        tab[i]=rand()%101;
        }
    }
int najwieksza(int tab[], int x)
    {
        int max=0;
        for(int i=0; i<10; i++)
        {
        if (tab[i]>max)
        max=tab[i];
        }
    return max;
    }
int main()
{
    int tab[10];
    srand(time(0));
    losowanie(tab,10); 
    for (int i = 0; i < 10; i++)
    printf("tab[%d] = %d, adres=%p\n", i, tab[i],&tab[i]);
    printf("Największy element to: %d\n",najwieksza(tab,10));
}