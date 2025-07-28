#include <stdio.h>
#include <time.h>

void TOH(char source, char dest, char temp, int rings) {
  if (rings == 1) {
    printf("Move ring %d from %c to %c\n", rings, source, dest);
  } else {
    TOH(source, temp, dest, rings - 1);
    printf("Move ring %d from %c to %c\n", rings, source, dest);
    TOH(temp, dest, source, rings - 1);
  }
}

int main() {

  time_t start, end;
  double seconds;
  start = time(NULL);
  TOH('A', 'C', 'B', 30);
  end = time(NULL);
  seconds = difftime(end, start);
  printf("Tine is %lf", seconds);
  return 0;
}