#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    srand (time(NULL));
    int tab[N];
    for(int i=0; i<N; i++)
    {
    tab[i] = rand() % 10;
    printf("%d ", tab[i]);
    }
    printf("\n");
    for (int i=0; i<N; i++)
    {
        int counter=0;
        for (int j=0; j<N; j++)
        {
            if(tab[i]==tab[j])
            counter++;
        }
        if (counter==1)
        printf("%d wystepuje w tablicy tylko raz.\n", tab[i]);
    }
}