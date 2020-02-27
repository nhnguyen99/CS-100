#include <stdio.h>
void function1(char *str, int num) {
 int a = 0;
 while ( a < num%10 ) {
 printf("%c", str[a]);
 a = a + num/10;
 }
 printf("\n");
 return;
}
void function2(int *x, int *y, int *z) {
 int temp = *x;
 *x = *x + *y + *z;
 *y = temp + *y;
 *z = temp - *z;
 return;
}
int main(void) {
 int a=27, b=39, c=13;
 function1("Roll-Tide", a);
 function1("ComputerScience", b);
 function1("CS100", c);
 function2(&a, &b, &c);
 printf("%d and %d and %d\n", a, b, c);
 function2(&a, &b, &c);
 printf("%d and %d and %d\n", a, b, c);
 return 0;
}
