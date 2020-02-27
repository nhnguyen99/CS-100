#include <stdio.h>
#include <string.h>

void reverse(char *);

int main(int argc, char *argv[]) {
  for (int a = 1; a < argc; a++) {
    printf("%s becomes ", argv[a]);
    reverse(argv[a]);
    printf("%s\n", argv[a]);
  }
  return 0;
}

void reverse(char str[]) {
  int len = strlen(str);
  for (int i = 0; i < len/2; i++) {
    char temp = str[i];
    str[i] = str[len-1-i];
    str[len-1-i] = temp;
  }
return;
}
