#include <stdio.h>

int main()
{
    int k = 0;
    int liczba;
    scanf("%d", &liczba);
    printf("Dzielniki:");
    for (int i = 2; i <= liczba; i++)
    {
        if (liczba % i == 0)
        {
            printf("\n %d ", i);
            k = k + 1;
        }
    }
    if (k == 1)
        printf("\nTo jest liczba pierwsza \n");

    return (0);
}