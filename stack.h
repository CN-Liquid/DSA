#define LEN 20
#include "cusString.h"
struct stack {

  int stackPointer;
  struct string data[LEN];
};

void push(struct stack *s, struct string element);

struct string pop(struct stack *s);
void print(struct stack *s);
void dump(struct stack *s, char arr[]);