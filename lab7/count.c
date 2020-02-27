#include <stdio.h>
#include <string.h>
#include <ctype.h>

void counts(char *, int *, int *, int *);

int main(int argc, char *argv[]) {
  FILE*fp = fopen(argv[1], "r");
  char str[100];
  fscanf(fp, "%s", str);
  while (!feof(fp)) {
    int upper, lower, digit;
    counts(str, &upper, &lower, &digit);
    printf("%s has %d uppercase, %d lowercase, and %d digits\n", str, upper, lower, digit);
    fscanf(fp, "%s", str);
  }
return 0;
}

void counts(char str[], int *upper, int *lower, int *digit) {
  *upper = 0, *lower = 0, *digit = 0;
  int len = strlen(str);
  for (int i=0; i < len; i++) {
    if (islower(str[i])) (*lower)++;
    if (isupper(str[i])) (*upper)++;
    if (isdigit(str[i])) (*digit)++;
  }
return;
}
