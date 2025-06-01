#include "cusString.h"
#include <stdio.h>
#include <string.h>

struct string create_string(const char *input) {
  struct string s;

  strcpy(s.data, input);

  s.size = strlen(input);
  return s;
}