//My name is Nguyen Hung Nguyen and this is my work for project 6. The purpose of this project is to create two lists of names and phone numbers by first name or last name, make any changes to those lists, and print them out.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"

///////////////////////////////////////////////////////////////

void printNumber(long val) {
	return;
}

int searchItem(MultiLinkedList *list, char *first, char *last) {
	for (Node *ptr = list->headFirstName; ptr != NULL; ptr = ptr->nextFirst) {
		if ((strcasecmp(ptr->first, first) == 0) && (strcasecmp(ptr->last, last) == 0)) {
			return 0;
		}
	}
return 1;
}

///////////////////////////////////////////////////////////////

MultiLinkedList *add(MultiLinkedList *list, char *first, char *last, long num) {
	// allocate a new node
	for (Node *ptr = list->headFirstName; ptr != NULL; ptr = ptr->nextFirst) {
		if ((strcasecmp(ptr->first, first) == 0) && (strcasecmp(ptr->last, last) == 0)) {
			printf("Error: name already exists.\n");
			printf("add Routine\n");
			return list;
		}
	}
	Node *newNode = malloc ( sizeof(Node) );
	newNode->first = malloc ( strlen(first) + 1 );
	strcpy(newNode->first, first);
	newNode->last = malloc ( strlen(last) + 1 );
	strcpy(newNode->last, last);
	newNode->number = num;

	if (!list->headFirstName) {
		list->headFirstName = newNode;
		list->headLastName  = newNode;
	}

	if (strcasecmp(first, list->headFirstName->first) < 0) {
		newNode->nextFirst = list->headFirstName;
		list->headFirstName = newNode;
	}

	Node *prev1 = list->headFirstName;
	Node *curr1 = prev1->nextFirst;
	while (curr1 && strcasecmp(curr1->first, first) < 0) {
		prev1 = curr1;
		curr1 = curr1->nextFirst;
	}
	prev1->nextFirst = newNode;
	newNode->nextFirst = curr1;

	if (strcasecmp(last, list->headLastName->last) < 0) {
		newNode->nextLast = list->headLastName;
		list->headLastName = newNode;
	}

	Node *prev2 = list->headLastName;
	Node *curr2 = prev2->nextLast;
	while (curr2 && strcasecmp(curr2->last, last) < 0) {
		prev2 = curr2;
		curr2 = curr2->nextLast;
	}
	prev2->nextLast = newNode;
	newNode->nextLast = curr2;

	return list;
}

int size(MultiLinkedList *list) {
	int count = 0;
	Node *ptr = list->headFirstName;
	while (ptr) {
		count++;
		ptr = ptr->nextFirst;
	}
	return count;
}

void printByFirst(MultiLinkedList *list) {
	Node *ptr = list->headFirstName;
	while (ptr) {
		printf("%s %s %03ld-%03ld-%04ld\n",  ptr->first, ptr->last, ptr->number/10000000, (ptr->number/10000) % 1000, ptr->number % 10000);
		ptr = ptr->nextFirst;
	}
	return;
}

void printByLast(MultiLinkedList *list) {
	Node *ptr = list->headLastName;
	while (ptr) {
		printf("%s %s %03ld-%03ld-%04ld\n",  ptr->first, ptr->last, ptr->number/10000000, (ptr->number/10000) % 1000, ptr->number % 10000);
		ptr = ptr->nextLast;
	}
	return;
}

int lookup(MultiLinkedList *list, char *name) {
	int count = 0;
	for (Node *ptr = list->headFirstName; ptr != NULL; ptr = ptr->nextFirst) {
		if ((strcasecmp(ptr->first, name) == 0) || (strcasecmp(ptr->last, name) == 0)) {
			printf("%s %s %03ld-%03ld-%04ld\n",  ptr->first, ptr->last, ptr->number/10000000, (ptr->number/10000) % 1000, ptr->number % 10000);
			count++;
		}
		else if ((ptr->nextFirst == NULL) && (count == 0)) {
			printf("Error: item not found in list\n");
			return count;
		}
	}
	// print all instances of name (as either a first name or a last name)
	return count;
}

void updatePhone(MultiLinkedList *list, char *first, char *last, long number) {
	int x = searchItem(list, first, last);
	if (x == 1) {
		printf("Error: item not found in list\n");
		return;
	}
	for (Node *ptr = list->headFirstName; ptr != NULL; ptr = ptr->nextFirst) {
		if ((strcasecmp(ptr->first, first) == 0) && (strcasecmp(ptr->last, last) == 0)) {
			ptr->number = number;
			return;
		}
	}
	return;
}

MultiLinkedList *removeItem(MultiLinkedList *list, char *first, char *last) {
	Node *head = list->headFirstName;
	Node *head1 = list->headLastName;
	if (head == NULL) {
    printf("Error: item not found in list\n");
    return list;
  }
	int x = searchItem(list, first, last);
	if (x == 1) {
		printf("Error: item not found in list\n");
		return list;
	}

	else {
	  if ((strcasecmp(first, head->first) == 0) && (strcasecmp(last, head->last) == 0)) {
	   	list->headFirstName = head->nextFirst;
			list->headLastName = head1->nextLast;
	  	return list;
	  }
		Node *prev = head;
		Node *curr = head->nextFirst;
		while (curr && (strcasecmp(curr->first, first) < 0)) {
			prev = curr;
			curr = curr->nextFirst;
		}
		if (curr == NULL) {
			printf("Error: item not found in list\n");
			return list;
		}
		prev->nextFirst = curr->nextFirst;

		Node *prev1 = head1;
		Node *curr1 = head1->nextLast;
		while (curr1 && strcasecmp(curr1->last, last) < 0) {
			prev1 = curr1;
			curr1 = curr1->nextLast;
		}
		if (curr1 == NULL) {
			printf("Error: item not found in list\n");
			return list;
		}
		prev1->nextLast = curr1->nextLast;
		return list;
	}
}


MultiLinkedList *updateFirst(MultiLinkedList *list, char *first, char *last, char *newFirst) {
	int x = searchItem(list, first, last);
	if (x == 1) {
		printf("Error: item not found in list\n");
		return list;
	}
	else {
		int y = searchItem(list, newFirst, last);
		if (y == 0) {
			printf("Error: name already exists\n");
			printf("updateFirst routine\n");
			return list;
		}
		else {
				for (Node *ptr = list->headFirstName; ptr != NULL; ptr = ptr->nextFirst) {
					if ((strcasecmp(ptr->first, first) == 0) && (strcasecmp(ptr->last, last) == 0)) {
						removeItem(list, ptr->first, ptr->last);
						add(list, newFirst, ptr->last, ptr->number);
						return list;
					}
				}
		}
	}
	return list;
}

MultiLinkedList *updateLast(MultiLinkedList *list, char *first, char *last, char *newLast) {
	int x = searchItem(list, first, last);
	if (x == 1) {
		printf("Error: item not found in list\n");
		return list;
	}
	else {
		int y = searchItem(list, first, newLast);
		if (y == 0) {
			printf("Error: name already exists\n");
			return list;
		}
		else {
				for (Node *ptr = list->headLastName; ptr != NULL; ptr = ptr->nextLast) {
					if ((strcasecmp(ptr->first, first) == 0) && (strcasecmp(ptr->last, last) == 0)) {
						removeItem(list, ptr->first, ptr->last);
						add(list, ptr->first, newLast, ptr->number);
						return list;
					}
				}
			}
		}
	return list;
}
