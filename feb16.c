#include <stdio.h>

int isPosMulFive(int);
int isSmallNeg(int);

int main(void) {
  int num, count1 = 0; count2 = 0;
  scanf("%d", &num);

  while(!feof(stdin)) {
    int ans1 = isPosMulFive(num);
    if (ans1 == 1) count1++;

    int ans2 = isSmallNeg(num);
    if (ans2 == 1) count2++;
    scanf("%d", &num);
  }
  printf("%d positive multiples of five\n", count1);
  printf("%d small negative numbers\n", count2);
return 0;
}
int isSmallNeg( int value ) {
  if (value >= -100 && value < 0) return 1;
  return 0;
}
