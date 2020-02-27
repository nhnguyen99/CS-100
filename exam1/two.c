#include <stdio.h>
#include <string.h>

int main(void) {
  char str[55];
  int count = 0;

  printf("Enter strings, terminating with xxx\n");
  scanf("%s", str);
  while (strcmp(str, "xxx") != 0) {
    int len = strlen(str);
    if (str[0] == str[len-1])
    count = count + 1;
    scanf("%s", str);
  }
  if (count == 1) printf("%d has same first and last character\n", count);
  else printf("%d have same first and last character\n", count);
return 0;
}
