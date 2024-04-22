#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void funkcja(char * lancuch)
{
    int size=strlen(lancuch);
    //char *zmiana;
    //zmiana=lancuch;
    int j=0;
    for (int i=0; i<size;i++)
    {
        if (isspace(lancuch[i])==0)
        {
            lancuch[j]=lancuch[i];
            j++;
        }
    }
    lancuch[j]='\0';
}
int main()
{
    char lancuch[]="To jest TESTOWY    lancuch";
    printf("%s\n",lancuch);
    funkcja(lancuch);
    printf("%s\n",lancuch);
}