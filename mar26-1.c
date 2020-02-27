#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct patient {
        char *first;
        char *last;
        int cwid;
        char gender;
} Patient;

void printPatient(Patient *);
Patient *readPatient(void);

int main(void) {
        Patient *p1;
        p1 = readPatient();
        printPatient(p1);
        return 0;
}

Patient *readPatient( ) {
        char str[100];
        Patient *p;
        p = malloc( sizeof(Patient) );
        printf("Enter patient information:\n");
        printf("\tFirst name : ");
        scanf("%s", str);
        p->first = malloc ( strlen(str) + 1 );
        strcpy(p->first, str);
        printf("\tLast name : ");
        scanf("%s", str);
        p->last = malloc ( strlen(str) + 1 );
        strcpy(p->last, str);
        printf("\tCWID : ");
        scanf("%d", &p->cwid);
        printf("\tGender : ");
        scanf(" %c", &p->gender);
        return p;
}
void printPatient( Patient *p ) {
        printf("The patient is %s %s, CWID %d, gender %c\n",
                p->first, p->last, p->cwid, p->gender);
        return;
}
