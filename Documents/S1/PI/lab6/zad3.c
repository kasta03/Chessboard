#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main()
{
    int tab[N];
    int *w;
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        tab[i] = rand() % 101;
    }
    w = &tab[0];
    for (int i = 0; i < N; i++)
    {
        printf("%d, adres: %p\n", *(w + i), w + i);
    }
    for (int i = 1; i < N; i++)
    {
        if (*(w + i) > *w)
        {
            w = w + i;
        }
    }
    printf("Najwiekszy element jest rowny %d i znajduje sie pod adresem: %p\n", *w, w);
    return 0;
}