#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i_rand(int min, int max){
return rand() % (max-min+1) + min;
}
double d_rand(double min, double max){
double r = (double) rand()/RAND_MAX;
return r*(max-min) + min;
}
int main ()
{
    srand(time(0));
    int tab[10];
    for (int i=0;i<10;i++)
    {
        tab[i]=i_rand(-100,100);
        printf("%d ",tab[i]);
    }
    printf("\n");
    for (int i=0;i<10;i++)
    {
        for (int j=i+1;j<10;j++)
        {
         if (tab[i]>tab[j])
         {
         int a=tab[i];
         tab[i]=tab[j];
         tab[j]=a;
         }
        }
         printf("%d ",tab[i]);
    }
    return 0;
}
