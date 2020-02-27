#include <stdio.h>
#include <string.h>


int main(void) {
  char str[50];
  int a, counts[26] = {0};

  printf("Enter your input: ");
  scanf("%s", str);
  printf("\n");

  while (!feof(stdin)) {
    int len = strlen(str);
    for (a=0; a<len; a++) {
      char ch = str[a];
        int num = ch - 97;
        counts[num] = counts[num] + 1;
    }
    scanf("%s", str);
  }
  printf("Missing letters: ");
  for (a = 0; a < 26; a++) {
    if (counts[a] == 0)
    printf("%c ", a+97);
  }
  printf("\n");
return 0;
}
