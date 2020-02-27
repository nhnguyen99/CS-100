#include <stdio.h>

int main(void) {

int a, positive = 0, negative = 0;
printf("Enter a series of number: \n");
scanf("%d", &a);

while (a != 0) {
  if (a > 0) positive++;
  if (a < 0) negative++;
  scanf("%d", &a);
}
if (positive > negative) printf("More positive numbers\n");
else if (negative > positive) printf("More negative numbers\n");
else printf("Equal counts\n");
  return 0;
}
