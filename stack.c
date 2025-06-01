#include "stack.h"
#include <stdio.h>

void push(struct stack *s, struct string element) {

  if (s->stackPointer > LEN) {
    printf("The stack is full\n");

  }

  else {
    s->data[s->stackPointer] = element;
    s->stackPointer = s->stackPointer + 1;
  }
}
struct string pop(struct stack *s) {
  if (s->stackPointer == 0) {
    printf("Stack is empty\n");

  }

  else {
    s->stackPointer = s->stackPointer - 1;
    return s->data[s->stackPointer];
  }
}

void print(struct stack *s) {
  for (int i = 0; i < s->stackPointer; i++) {
    printf("%c\t", s->data[i]);
  }
  printf("\n");
}
void dump(struct stack *s, char arr[]) {
  for (int i = 0; arr[i] != '\0'; i++) {

    char temp_str[2] = {arr[i], '\0'};

    struct string data = create_string(temp_str);

    push(s, data);
  }
}