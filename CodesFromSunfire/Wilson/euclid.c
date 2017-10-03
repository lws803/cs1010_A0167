#include "stdio.h"

int main() {
  int a = 12;
  int b = 42;

  printf("%d\n", euclid(a, b));

  return 0;
}


int euclid(int a, int b) {
  int r;
  while (b>0) {
    r = a%b;
    a = b;
    b=r;
  }

  return a;
}
