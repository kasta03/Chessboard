#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double d_rand(double min, double max) 
{
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min;
} 
void funkcja(int n, double *suma, double *iloczyn, double *srednia)
{
    srand(time(0));
    *suma=0;
    *iloczyn=1;
    for (int i=0; i<n;i++)
        {
            double a=d_rand(0.5,1.5);
            *suma=a+*suma;
            *iloczyn=a**iloczyn;
        }
    *srednia=*suma/(double)n;
}
    int main ()
    {
        int b;
        scanf("%d",&b);
        double suma, iloczyn, srednia;
        funkcja(b, &suma, &iloczyn, &srednia);
        printf("\n%d\n%f\n%f\n%f\n",b,suma,iloczyn,srednia);
    return 0;
    }