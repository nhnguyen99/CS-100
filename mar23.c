#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
        char *first;
        char *last;
        int cwid;
        char gender;
};

void printInfo(struct student);

int main(void) {
	char str[100];
        struct student s;
        printf("Enter student information:\n");
        printf("\tFirst name : ");
        scanf("%s", str);
	s.first = malloc( strlen(str) + 1 );
	strcpy(s.first, str);
        printf("\tLast name : ");
        scanf("%s", str);
	s.last = malloc( strlen(str) + 1 );
	strcpy(s.last, str);
        printf("\tCWID : ");
        scanf("%d", &s.cwid);
        printf("\tGender : ");
        scanf(" %c", &s.gender);

        printInfo(s);

        return 0;
}

void printInfo( struct student st ) {
        printf("The student is %s %s, CWID %d, gender %c\n",
                st.first, st.last, st.cwid, st.gender);
        return;
}
