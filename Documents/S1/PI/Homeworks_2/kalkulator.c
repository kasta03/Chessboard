#include <stdio.h>

float dodawanie (float a, float b);
float odejmowanie (float a, float b);
float mnozenie (float a, float b);
float dzielenie (float a, float b);

int main (void)
{
    printf("Proszę podać działanie: ");
    float x,y;
    char c;
    scanf("%f%c%f", &x, &c, &y);
    switch(c)
    {
    case '+':
        printf("\nWynik to:%.5f\n", dodawanie(x,y));
        break;
    case '-':
        printf("\nWynik to:%.5f\n", odejmowanie(x,y));
        break;
    case '*':
        printf("\nWynik to:%.5f\n", mnozenie(x,y));
        break;
    case '/':
        printf("\nWynik to:%.5f\n", dzielenie(x,y));
        break;
    default:
        printf("Nie ma tekigo działania\n");
        return 0;
    }
    
}
float dodawanie (float a, float b)
{
    return a+b;
}
float odejmowanie (float a, float b)
{
    return a-b;
}
float mnozenie (float a, float b)
{
    return a*b;
}
float dzielenie (float a, float b)
{
    return a/b;
}