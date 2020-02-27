#include <stdio.h>

int isAscending(int [ ]); // returns 1 if numbers are ascending, else 0
int isDescending(int [ ]); // returns 1 if numbers are descending, else 0

int main(void) {
 int array[10];
 printf("Enter ten integers : ");
 for (int a=0; a<10; a++) scanf("%d", &array[a]);
 if ( isAscending(array) == 1)
 printf("The values are in ascending order\n");
 else if ( isDescending(array) == 1)
 printf("The values are in descending order\n");
 else
 printf("The values are neither ascending or descending\n");
 return 0;
}

int isAscending(int array[10]) {
  int i = 1, count = 0;
  while (i < 10) {
    if (array[i] >= array[i-1]) {
      count++;
    }
    i++;
  }
  if (count == 9) return 1;
  else return 0;
}

int isDescending(int array[10]) {
  int i = 1, count = 0;
  while(i < 10) {
    if (array[i] <= array[i-1]) {
      count++;
    }
   i++;
  }
  if (count == 9) return 1;
  else return 0;
}
