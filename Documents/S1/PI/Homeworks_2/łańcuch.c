#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void funkcja(char * lancuch)
{
    char *zamienione;
    zamienione=lancuch;
    while(*lancuch!='\0')
    {
        if (*lancuch!=' ' && *lancuch!='\t' && *lancuch!='\n')
        {
        *zamienione=*lancuch;
        zamienione++;
        }
        lancuch++;
    }
    *zamienione='\0';
}
int main()
{
    char lancuch[]="To jest TESTOWY     lancuch";
    printf("%s\n",lancuch);
    funkcja(lancuch);
    printf("%s\n",lancuch);
}