#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 8
void U2(int p){
char tab[N+1];

    if ((p<-128)||(p>127))
    printf("Poza zakresem\n");
    else{
    int x=p;
    tab[8]='\0';
    if (p<0)
    {
        x=-p;
        tab[0]=1+'0';
        for (int i=7;i>0;i--)
        {
            if (x%2==1)
            tab[i]=0+'0';
            else 
            tab[i]=1+'0';
            x=x/2;
        }
        int buffer=1;
        for (int i=7;i>0;i--) 
        {
            if (tab[i]=='1')
            tab[i]=(tab[i]^buffer);
            else
            {
            tab[i]=(tab[i]^buffer);
            buffer=0;
            }
        }
    }
    else if (p>=0)
    {
       for (int i=7;i>0;i--)
        {
            if (x%2==1)
            tab[i]=1+'0';
            else 
            tab[i]=0+'0';
            x=x/2;
        } 
        tab[0]=0+'0';
    }

printf("%4d = %s\n", p, tab);
}
}

int main(void){
for(int i=-130; i<131; i++)
if(i<-125 || i>125 || i%50==0)
U2(i);

return 0;
}
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>

// #define N 8

// void U2(int p) {
//     char tab[N + 1];
//     int x = p;
//     tab[8] = '\0';
//     if (p < 0) {
//         tab[0] = '1'; // zmiana wartości 1 na '1'
//         for (int i = 7; i > 0; i--) {
//             if (x % 2 == 1)
//                 tab[i] = '1';
//             else
//                 tab[i] = '0';
//             x = x / 2;
//         }
//     } else if (p >= 0) {
//         for (int i = 7; i > 0; i--) {
//             if (x % 2 == 1)
//                 tab[i] = '1';
//             else
//                 tab[i] = '0';
//             x = x / 2;
//         }
//         tab[0] = '0'; // zmiana wartości 0 na '0'
//     }
//     printf("%4d = %s\n", p, tab);
// }

// int main(void) {
//     for (int i = -130; i < 131; i++)
//         if (i < -125 || i > 125 || i % 50 == 0)
//             U2(i);
//     return 0;
// }
