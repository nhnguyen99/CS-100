#include <stdio.h>
#include <stdlib.h>

int main(void) {
int a = 5, b = 10;
int *p = &a; // p points to the variable a
printf("The value referenced by p is %d %p\n", *p, p); // print the value p references
p = &b;
printf("p now points to memory location %p\n", p); // updated the location p references
printf("the value referenced by p is now %d\n", *p);

return 0;
}
