#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int i_rand(int min, int max) {
//     return rand() % (max - min + 1) + min;
// }

double d_rand(double min, double max)
{
  double r = (double)rand() / RAND_MAX;
  return r * (max - min) + min;
}
double *f_add(int n, double *tab1, double *tab2, double *tab3)
{
  double *x = tab3;
  double max = tab3[0];
  for (int i = 0; i < n; i++)
  {
    tab3[i] = tab1[i] + tab2[i];
    if (tab3[i] > max)
    {
      max = tab3[i];
      x = tab3 + i;
    }
  }
  return x;
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
  return 0;
}

// double *f_add(int n, double *tab1, double *tab2, double *tab3)
// {
//   double *max = tab3;
//   double x = tab3[0];
//   for (int i = 0; i < n; i++)
//   {
//     tab3[i] = tab1[i] + tab2[i];
//     if (tab3[i] > max)
//     {
//       max = tab3[i];
//       x = tab3 + i;
//     }
//   }
//   return x;
// }