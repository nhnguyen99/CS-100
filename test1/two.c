#include <stdio.h>
#include <string.h>

int main(void) {
  int hour, minute, count;
  char ampm[5];
  printf("Enter the time: ");
  scanf("%d", &hour);
  scanf("%d", &minute);
  scanf("%s", ampm);
  if (strcmp(ampm, "am") == 0) {
    if (hour < 12)
      count = (1440-60*hour-minute);
    else if (hour == 12) count = 1440 - minute;
    else if ((hour == 12) && (minute == 00)) count = 1440;
  }
  else if (strcmp(ampm,"pm") == 0) {
    if (hour < 12)
       count = ((1440/2)-60*hour-minute);
    else if (hour == 12) count = 1440 - 60*hour- minute;
    else if ((hour == 12) && (minute == 00)) count = 0;
  }
  printf("There are %d minutes left in the day as of %d %d %s\n", count, hour, minute, ampm);
return 0;
}
