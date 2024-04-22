#include <stdio.h>

int main()
{
    int ile;
    printf("Ile liczb w tablicy? ");
    scanf ("%d",&ile);
    int *tablica;
    tablica = new int [ile];

    delete [] tablica;
    return 0;
}