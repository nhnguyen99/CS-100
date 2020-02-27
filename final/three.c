#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct words {
	char *name;
	struct words *next;
} Words;

void print(Words *);
Words *add(Words *, char *);
int countSame(Words *);

int main(void) {
	char input[100];
	Words *myList = NULL;
	printf("Enter a word : ");
	scanf("%s", input);
	while (strcmp(input, "xxx") != 0) {
		myList = add (myList, input);
		printf("Enter a word or 'xxx' to exit : ");
		scanf("%s", input);
	}
	printf("\n\nThe list is ");  print(myList); printf("\n");
	printf("\n\ncountSame returns %d\n", countSame(myList) );
	return 0;
}
void print(Words *ptr) {
	while (ptr) { printf("%s ", ptr->name); ptr = ptr->next; }
	return;
}

Words *add(Words *ptr, char *name) {
	Words *newNode = malloc( sizeof(Words) );
	newNode->name = malloc( strlen(name) + 1 );
	strcpy(newNode->name, name);
	newNode->next = ptr;
	return newNode;
}

int countSame(Words *ptr) {
  int count = 0, lower = 0, upper = 0;
  int len = strlen(ptr->name);
  while (ptr) {
    for (int i = 0; i < len; i++) {
      if (islower(ptr->name[i])) lower++;
      else if (isupper(ptr->name[i])) upper++;
    }
    if ((lower == len) || (upper == len)) count++;
    ptr = ptr->next;
    if (ptr != NULL) {
      lower = 0;
      upper = 0;
      len = strlen(ptr->name);
    }
    else return count;
  }
  return count;
}
