#include <stdio.h>
#define MAX 100

int table[100] = {0};

int fibo(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    if (table[n] == 0) {
      table[n] = fibo(n - 1) + fibo(n - 2);
    }
    return table[n];
  }
}

int main() {
  printf("%d", fibo(45));
  return 0;
}