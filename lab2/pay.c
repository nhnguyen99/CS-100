#include <stdio.h>

int main(void) {
  double hourWage, wage;
  int hourWork;
  printf("Enter the hourly wage: ");
  scanf("%lf", &hourWage);
  printf("Enter the hours worked: ");
  scanf("%d", &hourWork);

  if ((hourWork>=0) && (hourWork <= 40))
    wage = hourWage*hourWork;
  else if (hourWork <=50)
    wage = hourWage*40 + 1.5*hourWage*(hourWork-40);
  else if (hourWork>= 51)
    wage = hourWage*40 + 1.5*hourWage*10 + 2.0*hourWage*(hourWork-50);
  printf("Entering %lf and %d gives a pay of %lf\n", hourWage, hourWork, wage);
return 0;
}
