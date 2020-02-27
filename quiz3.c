#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
 int value;
 struct node *next;
} Node;
int main(void) {
 Node *one = (Node *) malloc (sizeof(Node));
 Node *two = (Node *) malloc (sizeof(Node));
 one->value = 0; one->next = two;
 two->value = 1; two->next = one;
 Node *ptr = one;
 printf("A: %d\n", ptr->value);
 for (int a=0; a<3; a++)
 ptr = ptr->next;
 printf("B: %d\n", ptr->value);

 ptr = one;
 for (int a=1; a<=5; a++) {
 ptr->value = ptr->value + a;
 ptr = ptr->next;
 }
 printf("C: %d\n", one->value);
printf("D: %d\n", two->value);
 return 0;
}
