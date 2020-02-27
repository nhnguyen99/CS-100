#include <stdio.h>
#include <string.h>
#include <ctype.h>

void incrementCounts(char[], int []);
void printMissing(int[]);
int main(void) {
  int counts[26] = {0};
  printf("Enter some text, ending with <control-d>: ");
  char str[100];
  scanf("%s", str);
  while (!feof(stdin)) {
    incrementCounts(str, counts);
    scanf("%s", str);
  }
  printMissing(counts);
}

void incrementCounts(char str[], int counts[]) {
  int len = strlen(str);
  for (int a=0; a<len; a++) {
    char ch = str[a];
    if (islower(ch)) {
      int num = ch - 97;
      counts[num] = counts[num] + 1;
    }
    if (isupper(ch)) {
      int num = ch - 65;
      counts[num] = counts[num] + 1;
    }
  }
return;
}

void printMissing(int counts[]) {
  printf("Missing letters: ");
  for (int a = 0; a < 26; a++) {
    if (counts[a] == 0)
    printf("%c ", a+97);
  }
  printf("\n");
}
