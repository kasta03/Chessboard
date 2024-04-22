#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

void hex(int p){
  char tab[N+1];
  char literka;
  int y;
  int x=p;
  if (p<0 || p>=4096)
    printf("Zła liczba\n");
    else
    {
        for (int i=N-1;i>=0;i--)
        {
            y=x%16;
            if  (y>=10)
            {literka=y+'A'-10;
            tab[i]=literka;}
            else
            {literka=y+'0';
            tab[i]=literka;}
        x=x/16;
        }
        tab[N]='\0';
    printf("%4d = %s\n", p, tab);
  }
}

int main(void){
  for(int i=-2; i<=4097; i++)
    if(i<3 || (i>8 && i<17) || i>4093 || i%1000==0)
      hex(i);
  return 0;
} 