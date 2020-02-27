#include <stdio.h>

int main(void) {
  int num, divide = 0, negative = 0;

  printf("Enter integers, ending with ctrl-d:\n");
  scanf("%d", &num);
  while (!feof(stdin)) {
    if ((num > 0) && (num % 5 == 0)) {
    divide = divide + 1;
    }
    if ((num <= -1) && (num >= -100)) {
    negative = negative + 1;
    }
    scanf("%d", &num);
  }
  printf("\n");
  printf("%d positive multiples of 5\n", divide);
  printf("%d small negative values\n", negative);
return 0;
}
