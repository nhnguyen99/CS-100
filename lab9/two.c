#include <stdio.h>
#include <stdlib.h>

typedef struct letter {
        char info;
        struct letter *next;
} Letter;

int main(void) {
        Letter *a, *b, *c, *d;
        a = malloc (sizeof(Letter));
        b = malloc (sizeof(Letter));
        c = malloc (sizeof(Letter));
        d = malloc (sizeof(Letter));
        a->info = 'T';
        b->info = 'I';
        c->info = 'D';
        d->info = 'E';

        a->next = b;
        b->next = c;
        c->next = d;
        d->next = NULL;

        Letter *ptr = a;
        while ( ptr != NULL ) {
                printf("%c ", ptr->info);
                ptr = ptr->next;
        }
        printf("\n");

        // rearrange pointers so that it spells "DIET"
        a->next = NULL;
        b->next = d;
        c->next = b;
        d->next = a;

        // After rearranging, print the new word
        ptr = c;
        while ( ptr != NULL ) {
                printf("%c ", ptr->info);
                ptr = ptr->next;
        }
        printf("\n");
        return 0;
}
