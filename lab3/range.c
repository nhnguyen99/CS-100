#include <stdio.h>

int main(void) {
  int num, range, max, min;
  printf("Enter some numbers: \n");
  scanf("%d", &num);
  max = num;
  min = num;
  while (num != 0) {
    scanf("%d", &num);
    if (num > max)
    max = num;
    if (num < min)
    min = num;
  }
range = max - min;
printf("Range of input = %d\n", range);
return 0;
}
