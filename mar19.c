#include <stdio.h>
#include <stdlib.h>

void initData(int *array, int size) {
    int a;
    for (a = 0; a < size; a++)
      array[a] = a;
      return;
}

int main(void) {
  int data[100];
  initData(data, 100);
 
  int data2[5000];
  initData(data2, 5000);

return 0;
}
