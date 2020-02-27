#include <stdio.h>

int main(void) {
  int num1, num2, num3, max, min, range;
  printf("Enter three numbers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  if (num1 >= num2) {
    if (num2 >= num3) {
    max = num1;
    min = num3;
    }
    else {
      if (num1 >= num3) {
      max = num1;
      min = num2;
      }
      else {
        max = num3;
        min = num2;
      }
    }
  }
  else {
    if (num1 >= num3) {
      max = num2;
      min = num3;
    }
    else {
      min = num1;
      if (num2 >= num3)
        max = num2;
      else max = num3;
    }
  }
range = max - min;
printf("Entering %d %d %d gives a range of %d\n", num1, num2, num3, range);
return 0;
}
