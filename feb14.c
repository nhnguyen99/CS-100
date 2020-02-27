#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char str[50];
  int a;
  int counts[26] = {0};

  printf("Enter strings, terminating with ctr-d: ");
  scanf("%s", str);
  printf("\n");

  while (!feof(stdin)) {
    int len = strlen(str);
    for (a=0; a<len; a++) {
      char ch = str[a];
      if (islower(ch)) {
        int sub = ch - 97;
        counts[sub] = counts[sub] + 1;
      }
      if (isupper(ch)) {
        int sub = ch - 65;
        counts[sub] = counts[sub] + 1;
      }
    }
    scanf("%s", str);
  }
  for (a = 0; a < 26; a++) {
    printf("%d ", counts[a]);
  }
  printf("\n");

  int max = counts[0];
  for (a = 1; a < 26; a++)
    if (counts[a] > max) max = counts[a];
  printf("The number that is seen the most is: %d\n", max);
  printf("The letter that is seen the most is: ");
  for (a = 0; a < 26; a++)
    if (counts[a] == max)
      printf("%c ", a+65);
  printf("\n");
return 0;
}
