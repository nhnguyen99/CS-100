#include <stdio.h>

int main(void) {
  FILE *fp1 = fopen("good", "w");
  FILE *fp2 = fopen("bad", "w");
  int num, temp;
  printf("Enter your data: ");
  scanf("%d", &num);
  fprintf(fp1, "%d\n", num);
  temp = num;
  scanf("%d", &num);
  while (!feof(stdin)) {
      if (num > temp) {
      fprintf(fp1, "%d\n", num);
    }
    else fprintf(fp2,"%d\n", num);
    temp = num;
    scanf("%d", &num);
  }
  fclose(fp1);
  fclose(fp2);
return 0;
}
