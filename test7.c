#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen("data1", "r");
  int num, count[51] = {0};
  fscanf(fp, "%d", &num);
  int i;
  while (!feof(fp)) {
    for (i = 0; i < 51; i++) {
      if (num == i) count[i]++;
    }
    fscanf(fp, "%d", &num);
  }
  int a, sum = 0;
  scanf("%d", &a);
  while (a != -1) {
    for (int i=0 ; i < 51; i++) {
      if (i < a) sum = sum + count[i];
    }
    printf("%d lower than %d", sum, a);
    scanf("%d", &a);
  }

  fclose(fp);
return 0;
}
