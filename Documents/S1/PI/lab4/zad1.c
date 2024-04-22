#include <stdio.h>
#include <stdlib.h>
float dodawanie(float a, float b);
float odejmowanie(float a, float b);
float mnozenie(float a, float b);
float dzielenie(float a, float b);
int main()
{
    float a,b;
    char znak;
    printf ("Podaj dwie liczby i znak dzialania: \n");
    scanf("%f%c%f",&a,&znak,&b);
    switch(znak)
    {
        case '+':
        {
           printf ("\nWynik: %f\n",dodawanie(a,b));
    
        }
        case '-':
        {
           printf ("\nWynik: %f\n",odejmowanie(a,b));
    
        }
        case '*':
        {
           printf ("\nWynik: %f\n",mnozenie(a,b));
    
        }
        case '/':
        {
           printf ("\nWynik: %f\n",dzielenie(a,b));
    
        }
    }
    return 0;
}

float dodawanie(float a, float b)
{
    return a+b;
}
float odejmowanie(float a, float b)
{
    return a-b;
}
float mnozenie(float a, float b)
{
    return a*b;
}
float dzielenie(float a, float b)
{
    return a/b;
}