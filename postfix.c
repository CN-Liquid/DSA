#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
char charArray[20];
int parse(struct stack *s, int count, int result) {

  int value1;
  int value2;
  if (s->stackPointer == 1) {
    return result;
  }

  if (s->data[count].data[0] == '+') {

    value1 = atoi(pop(s).data);
    value2 = atoi(pop(s).data);
    pop(s);

    result = value1 + value2;
    sprintf(charArray, "%d", result);
    push(s, create_string(charArray));
  }

  else if (s->data[count].data[0] == '-') {
    value1 = atoi(pop(s).data);
    value2 = atoi(pop(s).data);
    pop(s);

    result = value1 - value2;
    sprintf(charArray, "%d", result);
    push(s, create_string(charArray));
  }

  else if (s->data[count].data[0] == '*') {
    value1 = atoi(pop(s).data);
    value2 = atoi(pop(s).data);
    pop(s);

    result = value1 * value2;
    sprintf(charArray, "%d", result);
    push(s, create_string(charArray));
  }

  else if (s->data[count].data[0] == '/') {
    value1 = atoi(pop(s).data);
    value2 = atoi(pop(s).data);
    pop(s);

    result = value1 / value2;
    sprintf(charArray, "%d", result);
    push(s, create_string(charArray));
  }

  return parse(s, s->stackPointer - 3, result);
}

int main() {
  struct stack s = {0};

  char arr[LENGTH] = "+5+4+3+12";

  dump(&s, arr);

  print(&s);
  int result = parse(&s, s.stackPointer - 3, 0);
  printf("%d", result);

  return 0;
}