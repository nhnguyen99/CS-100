#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int count = 0;
  char word;
  printf("Enter a character (or <control-d> to exit): ");
  scanf(" %c", &word);
  while (!feof(stdin)) {
    for (int i = 1; i < argc; i++) {
      int len = strlen(argv[i]);
      for (int j = 0; j < len; j++) {
        if (word == argv[i][j]) count++;
      }
    }
    printf("%c occurs %d times\n", word, count);
    printf("Enter a character (or <control-d> to exit): ");
    scanf(" %c", &word);
    count = 0;
  }
  printf("\n");
  return 0;
}
