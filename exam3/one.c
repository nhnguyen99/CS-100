#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int value;
        struct node *next;
} Node;

Node *add(Node *head, int num) {
        Node *n = malloc( sizeof(Node) );
        n->value = num;
        n->next = NULL;
        if (head == NULL) return n;
        Node *ptr = head;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = n;
        return head;
}

void printList(Node *, int, int);

int main(void) {
    Node *head = NULL;
    int num, start, stop;
    printf("Enter values for the list, -1 to end: ");
    scanf("%d", &num);
    while ( num != -1 )
        { head = add(head, num); scanf("%d", &num); }
    printf("Print: enter start & stop locations : ");
    scanf("%d %d", &start, &stop);
    printList(head, start, stop);
    return 0;
}

void printList(Node *head, int first, int last) {
  Node *ptr = head;
  for (int i = 1; i < first; i++) {
    ptr = ptr->next;
  }
  for (int j = first; j <= last; j++) {
      printf("%d ", ptr->value);
      ptr = ptr->next;
      if (ptr->next == NULL) {
        printf("%d ", ptr->value);
        return;
      }
  }
  printf("\n");
  return;
}
