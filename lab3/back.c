#include <stdio.h>
#include <string.h>

int main(void) {
  char str[21];

  printf("Enter some words: \n");
  scanf("%s", str);
  int len = strlen(str);
  int a;
  while (!feof(stdin)) {
    for (a=len-1; a>=0; a--)
      printf("%c", str[a]);
  printf("\n");
  scanf("%s", str);
  len = strlen(str);
  }
return 0;
}
