#include <stdio.h>

int Fib(int n)
{
    static int counter = 0; // zmienna statyczna przechowująca licznik wywołań funkcji
    printf("numer wywołania: %d\n", ++counter); // inkrementacja i wyświetlenie licznika
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return Fib(n-1) + Fib(n-2); // wywołanie rekurencyjne
    }
}

int main(void)
{
    int n;
    printf("Podaj numer elementu ciągu Fibonacciego: ");
    scanf("%d", &n);
    printf("Wartość %d-tego elementu ciągu Fibonacciego wynosi %d\n", n, Fib(n));
    return 0;
}