#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
        char *name;
        struct node *next;
} Node;

Node *add(Node *, char *);
void print(Node *);

int main(void) {
        Node *head = NULL;
        char str[50];

        printf("Enter a name or 'quit' to exit : ");
        scanf("%s", str);
        while ( strcmp(str, "quit") != 0 ) {
                head = add(head, str);
                printf("\nThe list is now : ");
                print(head);
                printf("Enter a name or 'quit' to exit : ");
                scanf("%s", str);
        }
        return 0;
}

void print(Node *ptr) {
        while (ptr) {
                printf("%s ", ptr->name);
                ptr = ptr->next;
        }
        printf("\n\n");
        return;
}

Node *add(Node *head, char *n) {
        Node *newOne = malloc( sizeof(Node) );
        newOne->name = malloc( strlen(n) + 1 );
        strcpy(newOne->name, n);

        // case #1 - adding to an empty list
        if (head == NULL) {
                newOne->next = NULL;
                return newOne;
        }

        // case #2 - adding at the front of the list
        if (strcmp(n, head->name) < 0) {
                newOne->next = head;
                return newOne;
        }

        // case #3 - adding somewhere in the middle/end
        Node *prev = head;
        Node *curr = head->next;
        while (curr && strcmp(curr->name, n) < 0) {
                prev = curr;
                curr = curr->next;
        }
        prev->next = newOne;
        newOne->next = curr;
        return head;
}
