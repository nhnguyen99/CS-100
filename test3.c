#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  int num, a = 0;
  fscanf(fp, "%d", &num);
  printf("Unique numbers in %s are ", argv[1]);
  while (!feof(fp)) {
      if (a != num) {
      printf("%d ", num);
      a = num;
    }
    fscanf(fp, "%d", &num);
  }
  fclose(fp);
return 0;
}
