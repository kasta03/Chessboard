// **************************************************
// Wybierz opcje:
// -->      A: wykonaj mnozenie.
// -->      B: zadaj zagadke.
// -->      D: wyswietl dowcip.
// -->      Q: zakoncz program.
// **************************************************

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clear_buffer(void)
    {
        while (getchar()!='\n')
        continue;
    }
void task_A()
    {
        int a; int b;
            printf("Prosze podać kolejno dwie liczby mnożenia: ");
            get_2ints(&a,&b);
            printf("Wynik to: %d", (a*b));
    }
int get_2ints(int*a,int*b)
    {
        scanf("%d%d",a,b);
        while (scanf("%d%d",a,b)!=2);
        {
            printf("Źle");
            clear_buffer();
        }
    }
char get_choice(void)
    {
    char choice=0;
    while(!isgraph(choice=getchar()))
    continue;
    clear_buffer();
    return toupper(choice);
    }
void show_menu(void)
    {
    printf("");
    }
int main()
    {
    char choice=0;
    while((choice=getchar())!='Q')
    {
        switch(choice)
        {
            case 'A':
            {
            task_A();
            break;
            }
            case 'B':
            task_B();
            break;
        }
        show_menu();
    }
    return 1;
    }