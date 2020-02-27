#include <stdio.h>

int main(void) {
  int numWeight;
  double ounceValue = 1333.15, personValue;
  printf("Enter the weight of the person: ");
  scanf("%d", &numWeight);
  personValue = numWeight*16*ounceValue;
  printf("The person is worth $%lf.\n", personValue);
return 0;
}
