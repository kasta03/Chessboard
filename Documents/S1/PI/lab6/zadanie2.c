#include <stdio.h>

void funkcja(char *lancuch) 
{
  int i = 0, j = 0;
  while (lancuch[i] != '\0') 
  {
    if (lancuch[i] != ' ') 
    {
      lancuch[j] = lancuch[i];
      j++;
    }
    i++;
  }
  lancuch[j] = '\0';
}
int main() {
  char lancuch[] = "To jest TESTOWY    lancuch";
  printf("PRZED: %s\n", lancuch);
  funkcja(lancuch);
  printf("PO: %s\n", lancuch);
  return 0;
}