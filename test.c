#include <stdio.h>
int main(void) {
 FILE *fp1 = fopen("data", "r");
 FILE *fp2 = fopen("data2", "r");
 int a, b, c=0, d=0;
 for (int z=0; z<4; z++) {
 fscanf(fp1, "%d", &a);
 fscanf(fp2, "%d", &b);
 if (a < b)
 { c = c + a; d = d + b; }
 else
 { c = c + b; d = d + a; }
 }
 printf("%d and %d\n", c, d);
 return 0;
}
