#include <stdio.h>
#include <limits.h> 

int main(void) {
  int a, b;
  printf("Podaj pierwsza liczbe: ");
  scanf("%d", &a);
  printf("Podaj druga liczbe: ");
  scanf("%d", &b);

  int bits = sizeof(int) * CHAR_BIT;  

  unsigned int mask = ~((unsigned int) ~0 >> (bits / 2));

  int result = (a & mask) == (b & mask);

  printf("Maska: %u\n", mask);
  printf("Prawa polowa bitow jest taka sama: %d\n", result);

  return 0;
}