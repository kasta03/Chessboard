#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

float f_rand(float min, float max) {
    float r = (float)rand() / RAND_MAX;
    return r * (max - min) + min; 
}
void funkcja(int n, float *suma, float *iloczyn, float *srednia)
{    
    srand(time(0));
    //suma=0, iloczyn=1;
    for (int i=0; i<n;i++)
    {
    float x = f_rand(0.5,1.5);
    *suma=*suma+x;
    (*iloczyn)=(*iloczyn) *x;
    //printf("%f\n",x);
    }
    *srednia=*suma/(float)n;
    // return n, suma, iloczyn, srednia;
}
int main ()
{
    int x;
    float suma=0, iloczyn=1, srednia=0;
    printf("Podaj liczbe losowań: \n");
    scanf("%d",&x);
    funkcja(x,&suma,&iloczyn,&srednia);
    printf("%d  %f  %f  %f",x,suma,iloczyn,srednia);
    return 0;
}