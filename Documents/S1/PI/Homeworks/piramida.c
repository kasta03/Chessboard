#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    do
    {
    printf ("Podaj wysokosc: ");
    scanf ("%d",&x);
    int k=x;
    int c=0;
    for (int i=0; i<x;i++)
    {
    k--;
    c=c+2;
      for (int a=0; a<=k; a++)
      {
      printf(" ");
      }
      for (int a=1; a<c;a++)
        printf("*");
      printf ("\n");
    }
    }while (x<=0);
    return 0;
}
