#include <stdio.h>

int main(void) {
  int a,b,c;
  double numAvg;
  printf("Enter three numbers: ");
  scanf("%d %d %d",&a,&b,&c);
  numAvg = (double)(a+b+c)/3;
  printf("The average is %lf.\n", numAvg);
return 0;
}
