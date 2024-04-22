#include <stdio.h>
#include <stdlib.h>

void change(char *tekst)
{
    char buffer;
    while(*tekst!=' ' && *tekst!='  ' && *tekst!='\n')
    tekst++;
    tekst++;
    char *koniec;
    koniec=tekst;
    while(*koniec!=' ' && *koniec!='  ' && *koniec!='\n')
    koniec++;
    koniec--;
    int size= (koniec-tekst)/2+1;
    for (int i=0;i<3;i++)
    {
    buffer=*koniec;
    *koniec=*tekst;
    *tekst=buffer;
    tekst++;
    koniec--;
    }
}
int main(void)
{
    char tekst[]="Drugie slowo w tym napisie zostanie zamienione kolejnością";
    change(tekst);
    printf("%s\n",tekst);
}