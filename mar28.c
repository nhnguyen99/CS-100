#include <stdio.h>
typedef struct node {
	char ch;
	struct node *next;
} Node;

int main(void) {
	Node a, b, c, d;
	a.ch = 'T';	a.next = &b;
	b.ch = 'E';	b.next = &c;
	c.ch = 'A';	c.next = &d;
	d.ch = 'M';	d.next = NULL;

	Node *ptr = &a;
	while ( ptr != NULL ) {
		printf("%c ", ptr->ch);
		ptr = ptr->next;
	}
	printf("\n");
	return 0;
}
