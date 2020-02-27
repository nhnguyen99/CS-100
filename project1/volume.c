/*My name is Nguyen Hung Nguyen and this is my work for Project 1*/
#include <stdio.h>
#include <math.h>

int main(void) {
  int numTwenty, numTen, numFive, numOne, numQuarters, numDimes, numNickels, numPennies, numDollars, numCents, numBills;
  double volBills, volChange, pi = 3.14159;
  printf("Enter the number of $20s you have: ");
  scanf("%d", &numTwenty);
  printf("Enter the number of $10s you have: ");
  scanf("%d", &numTen);
  printf("Enter the number of $5s you have: ");
  scanf("%d", &numFive);
  printf("Enter the number of $1s you have: ");
  scanf("%d", &numOne);
  printf("Enter the number of quarters you have: ");
  scanf("%d", &numQuarters);
  printf("Enter the number of dimes you have: ");
  scanf("%d", &numDimes);
  printf("Enter the number of nickels you have: ");
  scanf("%d", &numNickels);
  printf("Enter the number of pennies you have: ");
  scanf("%d", &numPennies);
  numDollars = 20*numTwenty + 10*numTen + 5*numFive + numOne;
  numCents = 25*numQuarters + 10*numDimes + 5*numNickels + numPennies;
  printf("You have %d dollars in bills and %d cents in change.\n", numDollars, numCents);
  numBills = numTwenty + numTen + numFive + numOne;
  volBills = numBills*2.61*6.14*0.0043*pow(2.54,3);
  volChange = numPennies*pi*pow(19.05e-1/2,2)*1.52e-1 + numNickels*pi*pow(21.21e-1/2,2)*1.95e-1 + numDimes*pi*pow(17.91e-1/2,2)*1.35e-1 + numQuarters*pi*pow(24.26e-1/2,2)*1.75e-1;
  printf("The volume of your bills is %lf cubic centimeters.\n", volBills);
  printf("The volume of your change is %lf cubic centimeters.\n", volChange);
return 0;
}
