#include <stdlib.h>
#include <string.h>
#include "reverse_string.h"
char *reverse(const char *value) {
  int length = (int) strlen(value);
  char *reversed = (char *)malloc(length + 1);
  for(int i = 1; i <= length; i++) {
    reversed[i - 1] = value[length - i];
  }
  reversed[length] = '\0';
  return reversed;
}