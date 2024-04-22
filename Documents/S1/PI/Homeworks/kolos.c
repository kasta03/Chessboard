#include <stdio.h>
int main(void)
{
    int a[5]={1,2,3,4,5};
    int *p=a;
    while (*p++);
    *p--;
    printf ("%d",*p-1);
    return 0;
}