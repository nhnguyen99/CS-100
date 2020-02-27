#include <stdio.h>
#include <stdlib.h>
void function(int *a, int b) {
 for (int z=0; z<b; z++)
 a[z] = z*z - b;
 return;
}
int main( ) {
 int *x = (int *) malloc ( sizeof(int) * 3);
 function(x, 3);
 printf("%d and %d\n", x[0], x[2]);
 int *y = (int *) malloc ( sizeof(int) * 7);
 function(y, 7);
 printf("%d and %d and %d\n", y[2],y[4],y[6]);
 return 0;
}
