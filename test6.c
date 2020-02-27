#include <stdio.h>
#include <string.h>

int main(void) {
  char str[60];
  printf("Enter your text: ");
  scanf("%s", str);
  int len = strlen(str);
  while (!feof(stdin)) {
    if (len > 1) printf("%c%c\n", str[0], str[len-1]);
    if (len == 1) printf("%c\n", str[0]);
    scanf("%s", str);
    len = strlen(str);
  }
return 0;
}
