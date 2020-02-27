#include <stdio.h>
#include <string.h>

int myFunction(char[], char);

int main(void) {
  char str[50];
  scanf("%s", str);

  int ans = myFunction(str, 'a');
  printf("There are %d a's in %s\n", ans, str);
  return 0;
}
int myFunction(char str[], char ch) {
  int a, len = strlen(str);
  int count = 0;
  for (a = 0; a < len; a++) {
    if (str[a] == ch) {
      count = count+1;
    }
  }
  return count;
}
