#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  int count;
  struct node *next;
} Node;

Node *addToList(Node *head, int num) {
  for (Node *curr = head; curr != NULL; curr = curr->next) {
    if (num == curr->value) {
      curr->count++;
      return head;
    }
  }
  
  Node *newOne = malloc( sizeof(Node) );
  newOne->value = num;
  newOne->count = 1;
  if (head == NULL) {
          newOne->next = NULL;
          return newOne;
  }
  if (num % 2 != 0) {
          newOne->next = head;
          return newOne;
  }
  else if (num % 2 == 0) {
    Node *prev = head;
    Node *now = head->next;
    while (now != NULL) {
          prev = now;
          now = now->next;
    }
    prev->next = newOne;
    newOne->next = now;
    return head;
  }
  return NULL;
}

void stats(Node *head) {
  int countOdd = 0, countEven = 0;
  for (Node *curr = head; curr != NULL; curr = curr->next) {
    if (curr->value % 2 != 0) {
      countOdd = countOdd + curr->count;
    }
    else if (curr->value % 2 == 0) {
      countEven = countEven + curr->count;
    }
  }
  printf("%d even and %d odd numbers\n", countEven, countOdd);
}

void printList(Node *ptr) {
  while (ptr)
  { printf("[%d-%d] ", ptr->value, ptr->count); ptr=ptr->next; }
  printf("\n");
}

int main( int argc, char *argv[] ) {
  Node *head = NULL;
  if ( argc != 2 )
    { printf("Usage: ./a.out datafile\n"); exit(1); }
  FILE *fp = fopen(argv[1], "r");
  if ( ! fp )
    { printf("File %s does not exist\n", argv[1]); exit(1); }
  int num;
  fscanf(fp, "%d", &num);
  while ( ! feof(fp) )
    { head = addToList( head, num ); fscanf(fp, "%d", &num); }
  printList(head);
  stats(head);
return 0;
}
