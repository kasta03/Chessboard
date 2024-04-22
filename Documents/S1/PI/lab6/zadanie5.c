#include <stdio.h>

void count(int *tab, int n) 
{
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (tab[i] == 0) {
      count++;
    }
    }
}