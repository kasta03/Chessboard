#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    int A[50],B[50],C[51]={0};
    int buffer=0;
    for (int i=0;i<50;i++)
    {
        A[i]=i_rand(0, 9);
        B[i]=i_rand(0, 9);
    }
    for (int i=50;i>=0;i--)
    {
        if (A[i]+B[i]+buffer<10)
        {
        C[i+1]=A[i]+B[i]+buffer;
        buffer=0;
        }
        else
        {
        C[i+1]=A[i]+B[i]+buffer-10;
        buffer=1;
        }
    }
    C[0]=buffer;
    printf (" ");
    for (int i=50;i>=0;i--)
    {
        printf ("%d",A[i]);
    }
        printf ("\n");
        printf (" ");
    for (int i=50;i>=0;i--)
    {
        printf ("%d",B[i]);
    }
        printf ("\n");
    for (int i=51;i>0;i--)
    {
        printf ("%d",C[i]);
    }
    return 0;
}
