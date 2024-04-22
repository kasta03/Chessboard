#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main() 
    {
    int tab[N];
    int licznik;
    srand(time(0));

    for (int i = 0; i < N; i++) 
    {
        tab[i] = rand()%10;
    }
    for (int i = 0; i < N; i++) 
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) 
    {
    licznik = 0;
    for (int j = 0; j < N; j++) 
    {
        if (tab[i] == tab[j]) 
        {
            licznik++;
        }
    }
        if (licznik == 1) 
    {
        printf("%d wystepuje w tablicy tylko raz.\n", tab[i]);
    }
    }
    return 0;
    }