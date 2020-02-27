#include <stdio.h>

int main(void) {
  int a, num, sum, remain;
  sum = 0;
  printf("Enter a number: ");
  scanf("%d", &a);
  num = a;
  while (num > 0) {
    remain = num % 10;
    sum = sum + remain;
    num = num / 10;
  }
  printf("If the user enters %d, the program generates the answer %d\n", a, sum);
return 0;
}
