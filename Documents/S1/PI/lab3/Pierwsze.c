#include <stdio.h>

int main()
    {
    int k;
    for (int i=2; i<=1000;i++)
    {
        k=1;
        for (int x=2;x<=i;x++)
        {
            if (i%x==0)
            k=0;
        }
        if (k==1)
            printf(" %d ",i);
    }

    return 0;
}
