#include <stdio.h>

int main(void) {
  int numQuarters, numDimes, numNickels, numPennies, numCents;
  printf("Enter the number of quarters you have: ");
  scanf("%d", &numQuarters);
  printf("Enter the number of dimes you have: ");
  scanf("%d", &numDimes);
  printf("Enter the number of nickels you have: ");
  scanf("%d", &numNickels);
  printf("Enter the number of pennies you have: ");
  scanf("%d", &numPennies);
  numCents = 25*numQuarters + 10*numDimes + 5*numNickels + numPennies;
  printf("You have %d cents.\n", numCents);
return 0;
}
