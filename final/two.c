#include <stdio.h>
#include <string.h>

int sameWhenShifted(char *, char *);

int main(int argc, char *argv[]) {
  char s1[100], s2[100];
  printf("Enter string 1 : ");
  scanf("%s", s1);
  printf("Enter string 2 : ");
  scanf("%s", s2);
  int ans = sameWhenShifted(s1, s2);
  if ( ans != -1 )
    printf("%s shifts %d to get %s\n", s1, ans, s2);
  else
    printf("Cannot build %s from %s\n", s2, s1);
  return 0;
}

int sameWhenShifted(char *str1, char *str2) {
  int count = 0;
  int x = strlen(str1);
  int y = strlen(str2);
  char str[100];
  strcpy(str, str1);
  if (x != y) return -1;
  for (int i = 0; i < x; i++) {
    if (strcmp(str, str2) != 0) {
      int temp = str[0];
      for (int j = 0; j < x-1; j++) {
        str[j] = str[j+1];
      }
      str[x-1] = temp;
      count++;
    }
    else return count;
  }
  return -1;
}
