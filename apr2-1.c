#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly {
        double coeff;
        int degree;
        struct poly *next;
} Poly;

void printPoly(Poly *ptr) {
        printf("[ ");
        while (ptr) {
                if (ptr->degree == 0)
                        printf("%lf ", ptr->coeff);
                else if (ptr->degree == 1)
                        printf("%lfx ", ptr->coeff);
                else
                        printf("%lfx^%d ", ptr->coeff, ptr->degree);
                if (ptr->next != NULL)
                        printf("+ ");
                ptr = ptr->next;
        }
        printf("]\n");
        return;
}

double evaluate(Poly *ptr, int val) {
        double value = 0.0;
        while (ptr) {
                value = value + ptr->coeff * pow(val, ptr->degree);
                ptr = ptr->next;
        }
        return value;
}

// Add a new node at the end of the existing list
Poly *add(Poly *thePoly, double c, int d) {
// build new node
        Poly *newNode = (Poly *) malloc ( sizeof(Poly) );
        newNode->coeff = c;
        newNode->degree = d;
        newNode->next = NULL;
// handle special case of an empty initial list
        if (thePoly == NULL)
                return newNode;
// link at the end of the list
        Poly *ptr = thePoly;
        while (ptr->next != NULL)
                ptr = ptr->next;
        ptr->next = newNode;
        return thePoly;
}

int main(void) {
        Poly *head = NULL;
        double x;
        int y, val;
        printf("Enter a term (double coefficient & integer degree) : ");
        scanf("%lf %d", &x, &y);
        while ( x != 0 || y != 0) {
                head = add(head, x, y);
                printf("The polynomial is now : ");
                printPoly(head);
                printf("Enter another term or 0 0 to exit : ");
                scanf("%lf %d", &x, &y);
        }

        printf("\n\nThe final polynomial is : ");
        printPoly(head);
        printf("\n\nEnter a value for x : ");
        scanf("%d", &val);
        printf("The value of the polynomial at x=%d is %lf\n",
                val, evaluate(head, val) );
        return 0;
}
