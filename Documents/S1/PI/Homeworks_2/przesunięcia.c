#include <stdio.h>
// 0000101   5   2
// 0001011   11  3
unsigned int count1(unsigned int p)
{
    unsigned int count=0;
    while (p>0)
    {
        if(p % 2 !=0)
        count++;
        p=p>>1;
    }
    return count;
}
int main()
{
    unsigned int x=2071;
    printf ("%d\n", count1(x));
}