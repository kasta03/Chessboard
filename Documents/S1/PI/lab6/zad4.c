#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void losowanie(char *x, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        x[i] = '0' + (rand() % 8);
    }
}
void pisz(char *x)
{
    printf("%s\n", x);
}

int wartosc(char *x, int n)
{
    int i, wartosc = 0;
    for (i = 0; i < n; i++)
    {
        wartosc += (x[i] - '0') * pow(8, n - 1 - i);
    }
    return wartosc;
}
int main()
{
    char tab[] = "000000";
    int n = 6;
    losowanie(tab, n);
    printf("Wylosowano: %s\n", tab);
    printf("ósemkowy: %d\n", wartosc(tab, n));
    return 0;
}