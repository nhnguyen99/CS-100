#include <stdio.h>

int main(void) {
  FILE *in1 = fopen("data1", "r");
  FILE *in2 = fopen("data2", "r");
  int num1, num2;
  fscanf(in1, "%d", &num1);
  fscanf(in2, "%d", &num2);

  while ((!feof(in1)) && (!feof(in2))) {
    if (num1 < num2) {
      printf("%d ", num1);
      fscanf(in1, "%d", &num1);
    }
    else if (num1 > num2) {
      printf("%d ", num2);
      fscanf(in2, "%d", &num2);
    }
    else if (num1 == num2) {
      printf("%d ", num1);
      fscanf(in1, "%d", &num1);
      fscanf(in2, "%d", &num2);
    }
  }
  while (!feof(in1)) {
    printf("%d ", num1);
    fscanf(in1, "%d", &num1);
  }
  while (!feof(in2)) {
    printf("%d ", num2);
    fscanf(in2, "%d", &num2);
  }
  printf("\n");
  fclose(in1);
  fclose(in2);
  return 0;
}
