#include <stdio.h>
#include <string.h>

int main(void) {
 char str1[20], str2[20], str3[20], str4[20];
 printf("Enter four words: ");
 scanf("%s %s %s %s", str1, str2, str3, str4);
 if ((strcmp(str1,str2)==0) || (strcmp(str1,str3)==0) || (strcmp(str1,str4)==0)||(strcmp(str2,str3)==0) || (strcmp(str2,str4)==0) || (strcmp(str3,str4)==0)) {
  printf("Match\n");
  printf("Entering %s and %s and %s and %s results in the output Match\n", str1, str2, str3, str4);
}
else {
  printf("No Match\n");
  printf("Entering %s and %s and %s and %s results in the output No Match\n", str1, str2, str3, str4);
}
return 0;
}
