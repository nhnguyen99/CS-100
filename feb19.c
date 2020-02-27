#include <stdio.h>

double myAverage(int, int);
int main(void) {
  int a,b;
  printf("Enter two integers: ");
  scanf("%d %d", &a, &b);
  double ans;
  ans = myAverage(a,b);
  printf("The averageof %d and %d is %lf\n", a, b, ans);
  return 0;
}
double myAverage(int x, int y) {
  double z;
  z = (x+y)/2.0;
  return x;
}
