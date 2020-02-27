#include <stdio.h>

typedef struct patient {
  char first[10];
  char last[10];
  int cwid;
  char gender;
} Patient;

void printPatient(Patient);

int main(void) {
  Patient p1;
  printf("Enter patient information: \n");
  printf("\tFirst name: ");
  scanf("%s", p1.first);
  printf("\tLastname: ");
  scanf("%s", p1.last);
  printf("\tCWID: ");
  scanf("%d", &p1.cwid);
  printf("\tGender: ");
  scanf(" %c", &p1.gender);

  printPatient(p1);

return 0;
}

void printPatient(Patient p) {
  printf("The patient is %s %s CWID: %d Gender: %c\n", p.first, p.last, p.cwid, p.gender);
}
