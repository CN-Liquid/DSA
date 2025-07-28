#include <stdio.h>

int GCD(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GCD(b, a % b);
  }
}

int main() {
  printf("%d", GCD(10, 15));
  return 0;
}