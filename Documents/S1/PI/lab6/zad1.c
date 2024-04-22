// #include <stdio.h>
// #define ROZMIAR(tab) (sizeof(tab) / sizeof(tab[0]))

// int main()
// {
//     const float tab1[] = {-6.44, 7.34, -5.17, -8.85, -6.43, 0.41, -6.07, -5.37, 4.03, 6.37,
// -9.76, -6.19, -5.45, 1.22, 3.68, -8.25, -5.24, 7.35, 4.39, -9.68, 5.86, 8.00, 3.49, -1.30,
// -4.43, 7.39, -9.04, 2.47, 7.66, 1.71, 5.98, -8.78, -0.95, -9.19, -7.64, 2.62, 1.22, -3.70,
// 7.25, -4.75, -7.33, 7.49, -0.94, -2.78, -1.29, -7.27, -1.04, 3.47, -9.92, -6.65, 3.79, 5.94,
// -8.65, -2.71, -5.36, -3.08, -5.32, -4.40, 9.40, -7.66, 7.31, 5.37, -6.45, -3.63, 6.18,
// -4.08, 8.99, -2.60, 2.21, 6.24, 2.65, 4.88, 3.73, -8.30, -7.90, -7.56, -5.56, 1.06, 5.91,
// -5.48, 4.41, -0.29, -9.54, 5.76, 7.00, -4.90, -7.32, -8.32, 0.70, -7.92, -5.98, -1.99, 7.45,
// -2.43, 4.37, 3.63, 3.48, 3.36, -8.97, -4.30, -0.40, 3.68, -9.42, -6.67, 5.38, -7.33, -4.23,
// 9.81, 3.73, -8.32, -5.67, -1.86, 1.39, -5.21, -6.10, -1.61, -0.11, -3.41, 0.06, -9.42,
// -1.34, 4.08, -1.41, -3.88, -8.35, -7.04, 9.75, 5.13, 6.32, -9.22, -9.17, -4.08, 4.45, -8.60,
// -0.76, -0.17, -5.92, 5.01, -0.36, 7.81, 6.69, 3.97, -4.05, -1.92, 8.76, -0.14, 6.47, -1.35,
// 6.44, -3.47};
// const char tab2[] = "cd - Change the shell working directory. Change the current directory
// to DIR. The default DIR is the value of the HOME shell variable. The variable CDPATH defines
// the search path for the directory containing DIR. Alternative directory names in CDPATH are
// separated by a colon (:). A null directory name is the same as the current directory. If DIR
// begins with a slash (/), then CDPATH is not used. If the directory is not found, and the
// shell option `cdable_vars' is set, the word is assumed to be a variable name. If that
// variable has a value, its value is used for DIR. Exit Status: Returns 0 if the directory is
// changed; non-zero otherwise.";
// printf("Rozmiar tablicy tab1 = %ld\n", ROZMIAR(tab1));
// printf("Rozmiar tablicy tab2 = %ld\n", ROZMIAR(tab2));
// return 0;
// }
#include <stdio.h>
#define ROZMIAR(tab) (sizeof(tab) / sizeof(tab[0]))

int main()
{
const float tab1[] = {-6.44, 7.34};
const char tab2[] = "cd - Change the shell working directory.";
printf("Rozmiar tablicy tab1 = %ld\n", ROZMIAR(tab1));
printf("Rozmiar tablicy tab2 = %ld\n", ROZMIAR(tab2));
return 0;
}