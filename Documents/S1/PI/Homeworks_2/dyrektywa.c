#include <stdio.h>
#define ROZMIAR(x) (sizeof(x)/sizeof(x[0]))
int main()
{
const double tab1[] = {679.100, 428.457, 317.481, 924.451, 478.856, 813.807, 50.673,
-632.281, 779.172, -196.442, -70.067, -86.876, 507.880, 731.883, -732.392, 420.747, 592.491,
573.191, 15.551, -168.429, -32.004, -489.447, -143.568, 984.672, 937.237, 617.304, -679.282,
145.131, -186.397, 684.719, -821.511, -507.297, 113.176, 495.970, -582.846, -407.968,
309.777, 467.828, -40.249, 88.948, -728.615, 889.684, -997.928, 779.265, 621.567, -730.319,
200.012, 214.058, 842.872, -784.437, -954.371, -189.132, -273.883, -97.940, -204.461,
-336.646, -480.636, 116.258, 808.484, 332.967, -199.023, 986.973, 825.670, 914.153, 482.943,
-757.176, -493.816, -207.281, 710.652, 465.935, 881.668, 982.037, 355.620, 883.740, 761.302,
-22.813, -846.579, -38.685, -808.756, 996.292, 176.878, -763.127, -192.840, 902.994,
138.933, 602.699, -433.652, 658.297, -281.043, -625.168, -8.736, 519.933, -638.195,
-183.066, 434.086, 844.748, 59.758, 940.270, -362.533, -229.590, 406.206, -480.865,
-247.553, -238.175, -597.125, -486.251, 739.012, -443.704, 475.064, 930.256, -447.412,
-348.058, -832.871, 359.748, -445.064, 306.063, -37.553, 121.284};
const char tab2[] = "Description: grep searches the named input FILEs (or standard input if \
no files are named, or if a single hyphen-minus (-) is given as file name) for lines \
containing a match to the given PATTERN. By default, grep prints the matching lines. In \
addition, two variant programs egrep and fgrep are available. egrep is the same as grep -E. \
fgrep is the same as grep -F. Direct invocation as either egrep or fgrep is deprecated, but \
is provided to allow historical applications that rely on them to run unmodified.";
printf("Rozmiar tablicy tab1 = %ld\n", ROZMIAR(tab1));
printf("Rozmiar tablicy tab2 = %ld\n", ROZMIAR(tab2));
}