#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#define n 10

double d_rand(double min, double max)
    {
    double r = (double)rand() / RAND_MAX;
    return r * (max - min) + min; }
double *f_add(int n, double *tab1, double *tab2, double *tab3)
    {
     for (int i=0; i<n; i++)
     {
        tab3[i]=tab1[i]+tab2[i];
     }
        double *max;
        max=&tab3[0];
     for (int i=0; i<n; i++)
     {
        if (tab3[i]>*max)
        max=&tab3[i];
     }
     return max;
    }
int main ()
    {
    srand(time(0));
    double tab1[10], tab2[10], tab3[10];
      for (int i=0; i<10; i++)
      {
         tab1[i]=d_rand(0,1);
         tab2[i]=d_rand(0,1);
      }
      //*f_add(10,tab1,tab2,tab3);
      double *max = f_add(10, tab1, tab2, tab3);
      int indeks=max-tab3;
      for (int i=0; i<10; i++) 
      printf("tab3[%d]=%f, adres= %p\n", i, tab3[i], &tab3[i]);
      printf("Maksimum:tab3[%d]=%f, adres %p", indeks, *max, max);
    }