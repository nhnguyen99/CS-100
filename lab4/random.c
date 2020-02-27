#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num, i, count[10]= {0}, sum=0;

  printf("Enter a number: ");
  scanf("%d", &num);
  srand(0);
  for (i = 0; i < num; i++) {
    int r=rand() % 10;
    count[r]++;
  }
  for (i = 0; i < 10; i++) {
    if (count[i] > 0) sum++;
  }
  printf("%d random numbers generated %d out of 10 possible values\n", num, sum);

return 0;
}
