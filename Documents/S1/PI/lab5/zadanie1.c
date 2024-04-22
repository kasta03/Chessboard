#include<stdio.h>
#include<limits.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    int bity=sizeof(int)*CHAR_BIT;

    unsigned int mask= 1<<(bity/2);
    d=a&mask;
    c=a&mask;
    if (d==c)
    
    printf("TAK");
    return 0;
}