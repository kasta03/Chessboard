#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;}

int main()
{
    srand(time(NULL));
    double tab[10];
    for (int i=0;i<10;i++)
    {
        tab[i]=d_rand(-100.0, 100.0);
        printf ("A[%d]=%*.*f\n",i,6,2,tab[i]);
    }
    printf("\n");
    int k=0;
    for (int i=9;i>=0;i--)
    {
        printf ("A[%d]=%*.*f\n",k,6,2,tab[i]);
        k++;
    }
    return 0;
}
