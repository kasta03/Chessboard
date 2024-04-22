#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max)
{
  double r = (double)rand() / RAND_MAX;
  return r * (max - min) + min;
}
double *f_add(int n, double *tab1, double *tab2, double *tab3)
{
  double *pmax = tab3;
  double max = tab3[0];
  for (int i = 0; i < n; i++)
  {
    tab3[i] = tab1[i] + tab2[i];
    if (tab3[i] > max)
    {
      max = tab3[i];
      pmax = tab3 + i;
    }
  }
  return pmax;
}
int main()
{
  srand(time(0));
  int n = 10;
  double tab1[n], tab2[n], tab3[n];
  for (int i = 0; i < n; i++)
  {
    tab1[i] = d_rand(0, 1);
    tab2[i] = d_rand(0, 1);
  }
  double *pmax = f_add(n, tab1, tab2, tab3);
  for (int i = 0; i < n; i++)
  {
    printf("tab3[%d] = %f, adres: %p\n", i, tab3[i], tab3 + i);
  }
  int index = pmax - tab3;
  printf("Maksimum: tab3[%d] = %f,adres: %p\n", index, *pmax, pmax);
  return 0;
}