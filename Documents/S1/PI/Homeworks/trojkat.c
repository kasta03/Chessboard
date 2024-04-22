#include <stdio.h>
#include <stdlib.h>

int main ()
{
int znak;
printf ("Prosze podac litere: ");
scanf ("%c",&znak);
for (int i=0; i<4;i++)
{
    char ch=znak;
    for (int x=i; x<4; x++)
    {
        printf (" ");
    }
    for (int x=0;x<=i;x++,ch--)
    {
        printf ("%c",ch);
    }
    for (int x=1;x<=i;x++,ch++)
    {
        printf ("%c",ch+2);
    }
   
    printf ("\n");

}

}