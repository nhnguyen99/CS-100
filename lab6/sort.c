#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  FILE *in = fopen("datafile", "r");
  FILE *out1 = fopen("words", "w");
  FILE *out2 = fopen("numbers", "w");
  char str[60];
  int count1 = 0, count2 = 0;
  fscanf(in, "%s", str);
  while (!feof(in)) {
    int len = strlen(str);
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < len; i++) {
      if (isalpha(str[i])) count1++;
      else if (isdigit(str[i])) count2++;
    }
    if (count1 == len) fprintf(out1, "%s\n", str);
    else if (count2 == len) fprintf(out2, "%s\n", str);
    fscanf(in, "%s", str);
  }
  fclose(in);
  fclose(out1);
  fclose(out2);
  return 0;
}
