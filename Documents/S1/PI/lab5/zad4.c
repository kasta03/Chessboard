#include <stdio.h>

int Fib(int n, int depth) {
  printf("Fib called with n = %d, depth = %d\n", n, depth);
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return Fib(n - 1, depth + 1) + Fib(n - 2, depth + 1);
  }
}

int main() {
  int n;
  printf("Enter an integer: ");
  scanf("%d", &n);
  printf("Fibonacci number: %d\n", Fib(n, 0));
  return 0;
}