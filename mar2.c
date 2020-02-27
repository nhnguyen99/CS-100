#include <stdio.h>
#include <string.h>

int main(void) {
  char str[50];
  printf("Enter a string: \n");
  scanf("%s", str);
  printf("The string is %s", str);

  int len = strlen(str);
  str(len) = '!';
  printf("The string is %s", str);
  return 0;
}
