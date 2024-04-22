#include <stdio.h>
#include <stdlib.h>

int main()
{
    float suma=0;
    int n=0;
    int i=0;
    //for (i=0; i<=n;i++)
    while (suma<10.0)
    {
        suma+=1/(1.0+i);
        i++;
        n++;
    }
    printf("Suma wynosi %f i jest to suma %d liczb",suma,n);
    return 0;
}
