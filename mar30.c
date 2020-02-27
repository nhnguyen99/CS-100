#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        char ch;
        struct node *next;
} Node;

void printList(Node *head) {
        Node *ptr = head;
        while ( ptr != NULL ) {
                printf("%c ", ptr->ch);
                ptr = ptr->next;
        }
        printf("\n");
        return;
}

int size(Node *ptr) {
        int count = 0;
        while ( ptr != NULL ) {
                count = count + 1;
                ptr = ptr->next;
        }
        return count;
}

Node *add(Node *head, char ch) {
        Node *newOne = malloc( sizeof(Node) );
        newOne->ch = ch;
        newOne->next = NULL;
        if (head == NULL) return newOne;
        Node *ptr = head;
        while (ptr->next != NULL)
                ptr = ptr->next;
        ptr->next = newOne;
        return head;
}

int main(void) {
        Node *head = NULL;
        head = add(head, 'T');
        head = add(head, 'I');
        head = add(head, 'D');
        head = add(head, 'E');

        printList(head);
        int count = size(head);
        printf("There are %d nodes in the list\n", count);
        return 0;
}
