#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min; }
    
int main ()
    {
    srand(time(NULL));
    int n;
    int tab [10]={0};
    double a;
    printf ("Podaj liczbe losowan: \n");
    scanf ("%d",&n);
       for(int i=0; i<n; i++)
		    {
			a=d_rand(0.0, 9.9999);
            tab [(int)a]++;			
		    }
        for (int i=0;i<10;i++)
            {
            printf("Przedzial [%d, %d): %d punktow.\n", i, i+1, tab[i]);
            }
        return 0;
    }