#include <stdio.h>

int tailFact(int n, int a) {

  if (n == 1) {
    return a;
  }

  else {
    return tailFact(n - 1, a * n);
  }
}

int main() {
  printf("%d", tailFact(5, 1));
  return 0;
}