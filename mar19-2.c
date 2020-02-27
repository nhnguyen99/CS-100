#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, sub, data[100];
    for (a = 0; a < 100, a++) data[a] = a;

    printf("Enter a subscript or -999 to exit: ");
    scanf("%d", &sub);
    while (sub!= -999) {
      printf("data[%d] is %d\n", sub, data[sub]);
      printf("Enter another or -999 to exit: ");
      scanf("%d", &sub);
    }
return 0;
}
