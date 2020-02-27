#include <stdio.h>

int main(void) {
  int a = 5;
  printf("The value of a is %d\n", a);
  printf("the location of a is %p\n", &a);
  int b = 10;
  printf("The value of b is %d\n", b);
  printf("the location of b is %p\n", &b);

  int *p;
  p = &a;
  printf("The location of p is %p\n", p);
  printf("The value that p points to is %d\n", *p);
  return 0;
}
