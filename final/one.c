#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *in1 = fopen(argv[2], "r");
  FILE *in2 = fopen(argv[3], "r");
  FILE *in3 = fopen(argv[4], "r");
  int x = atoi(argv[1]);
  int num1, num2, num3;
  int count1 = 0, count2 = 0, count3 = 0, bad = 0;
  fscanf(in1, "%d", &num1);
  fscanf(in2, "%d", &num2);
  fscanf(in3, "%d", &num3);
  for (int i = 0; i < x; i++) {
    if ((num1 == num2) && (num1 != num3)) count3++;
    else if ((num1 == num3) && (num1 != num2)) count2++;
    else if ((num2 == num3) && (num2 != num1)) count1++;
    else if ((num1 != num2) && (num1 != num3) && (num2 != num3)) bad++;
    fscanf(in1, "%d", &num1);
    fscanf(in2, "%d", &num2);
    fscanf(in3, "%d", &num3);
  }
  printf("Data1 has %d possible bad values\n", count1);
  printf("Data2 has %d possible bad values\n", count2);
  printf("Data3 has %d possible bad values\n", count3);
  printf("There are %d unknown cases\n", bad);

  return 0;
}
