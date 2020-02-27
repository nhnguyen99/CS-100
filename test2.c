#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countCase(char *, int *, int *);

int main(void) {
  char str[50];
  int upper, lower;
  scanf("%s", str);
  while (!feof(stdin)) {
    upper = 0, lower = 0;
    countCase(str, &upper, &lower);
    printf("%s: %d uppercase, %d lowercase\n", str, upper, lower);
    scanf("%s", str);
  }
return 0;
}

void countCase(char str[], int *a, int *b) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (isupper(str[i])) (*a)++;
    else if (islower(str[i])) (*b)++;
  }
return;
}
