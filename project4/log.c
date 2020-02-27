//My name is Nguyen Hung Nguyen and this is my work for project 4. The purpose of this project is to print all the incoming and outcoming text messages, with the dates and phone numbers, in chronological order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *readableTime(int sec) {
  time_t epoch_time = (time_t) sec;
  return asctime(localtime(&epoch_time));
}
void f1(int, FILE *); //This function processes the incoming messages from the first argument.
void f2(int, FILE *); //This function processes the outcoming messagaes from the second argument.
void f3(int, FILE *); //This function processes the incoming messages from the first argument when the second argument has hit end-of-file.
void f4(int, FILE *); //This function processes the outcoming messages from the second argument when the first argument has hit end-of-file.

int main(int argc, char *argv[ ]) {
	if (argc != 3) {
		printf("Usage: ./a.out text_in text_out\n");
		return 0;
	}
  FILE *in1 = fopen(argv[1], "r");
	if ( in1 == NULL ) {
		printf("Input file %s does not exist\n", argv[1]);
		return 0;
	}
  FILE *in2 = fopen(argv[2], "r");
	if ( in2 == NULL ) {
		printf("Input file %s does not exist\n", argv[1]);
		return 0;
	}
  int time1, time2;
  fscanf(in1, "%d", &time1);
  fscanf(in2, "%d", &time2);
  while ((!feof(in1)) && (!feof(in2))) {
    if (time1 < time2) {
        f1(time1, in1);
        fscanf(in1, "%d", &time1);
    }
    else {
      f2(time2, in2);
      fscanf(in2, "%d", &time2);
    }
  }
  while (!feof(in1)) {
    f3(time1, in1);
    fscanf(in1,"%d", &time1);
  }
  while (!feof(in2)) {
    f4(time2, in2);
    fscanf(in2,"%d", &time2);
  }
  printf("\n");
return 0;
}

void f1(int x, FILE *in1) {
  int numChar, sum = 0, len;
  long long number;
  char str[50];
  char *strTime = readableTime(x);
  int lenTime = strlen(strTime);
  strTime[lenTime-1] = '\0';
  printf("%s", strTime);
  printf(" From ");
  fscanf(in1, "%lld", &number);
  printf("%lld-%lld-%lld | ", number/10000000, (number/10000)%1000, number%10000);
  fscanf(in1, "%d", &numChar);
  fscanf(in1, "%s", str);
  for (int i = 0; i < numChar; i++) {
    len = strlen(str);
    if (sum+len == 40) {
      printf("%s", str);
      sum = sum + len;
    }
    else {
      sum = sum + len + 1;
      if (sum <= 40) printf("%s ", str);
      else {
        sum = 0;
        printf("\n");
        printf("%-42s | ", " ");
        printf("%s ", str);
        len = strlen(str);
        sum = sum + len + 1;
      }
    }
    if (i < numChar-1) fscanf(in1, "%s", str);
  }
  printf("\n");
  return;
}

void f2(int x, FILE *in2) {
  int numChar, sum = 0, len;
  long long number;
  char str[50];
  char *strTime = readableTime(x);
  int lenTime = strlen(strTime);
  strTime[lenTime-1] = '\0';
  printf("%s", strTime);
  printf("   To ");
  fscanf(in2, "%lld", &number);
  printf("%lld-%lld-%lld | ", number/10000000, (number/10000)%1000, number%10000);
  fscanf(in2, "%d", &numChar);
  fscanf(in2, "%s", str);
  for (int i = 0; i < numChar; i++) {
    len = strlen(str);
    if (sum+len == 40) {
      printf("%s", str);
      sum = sum + len;
    }
    else {
      sum = sum + len + 1;
      if (sum <= 40) printf("%s ", str);
      else {
        sum = 0;
        printf("\n");
        printf("%-42s | ", " ");
        printf("%s ", str);
        len = strlen(str);
        sum = sum + len + 1;
      }
    }
    if (i < numChar - 1) fscanf(in2, "%s", str);
  }
  printf("\n");
return;
}

void f3(int x, FILE *in1) {
  int numChar, sum = 0, len;
  long long number;
  char str[50];
  char *strTime = readableTime(x);
  int lenTime = strlen(strTime);
  strTime[lenTime-1] = '\0';
  printf("%s", strTime);
  printf(" From ");
  fscanf(in1, "%lld", &number);
  printf("%lld-%lld-%lld | ", number/10000000, (number/10000)%1000, number%10000);
  fscanf(in1, "%d", &numChar);
  fscanf(in1, "%s", str);
  for (int i = 0; i < numChar; i++) {
    len = strlen(str);
    if (sum+len == 40) {
      printf("%s", str);
      sum = sum + len;
    }
    else {
      sum = sum + len + 1;
      if (sum <= 40) printf("%s ", str);
      else {
        sum = 0;
        printf("\n");
        printf("%-42s | ", " ");
        printf("%s ", str);
        len = strlen(str);
        sum = sum + len + 1;
      }
    }
    if (i < numChar-1) fscanf(in1, "%s", str);
  }
  printf("\n");
  return;
}

void f4(int x, FILE *in2) {
  int numChar, sum = 0, len;
  long long number;
  char str[50];
  char *strTime = readableTime(x);
  int lenTime = strlen(strTime);
  strTime[lenTime-1] = '\0';
  printf("%s", strTime);
  printf("   To ");
  fscanf(in2, "%lld", &number);
  printf("%lld-%lld-%lld | ", number/10000000, (number/10000)%1000, number%10000);
  fscanf(in2, "%d", &numChar);
  fscanf(in2, "%s", str);
  for (int i = 0; i < numChar; i++) {
    len = strlen(str);
    if (sum+len == 40) {
      printf("%s", str);
      sum = sum + len;
    }
    else {
      sum = sum + len + 1;
      if (sum <= 40) printf("%s ", str);
      else {
        sum = 0;
        printf("\n");
        printf("%-42s | ", " ");
        printf("%s ", str);
        len = strlen(str);
        sum = sum + len + 1;
      }
    }
    if (i < numChar - 1) fscanf(in2, "%s", str);
  }
  printf("\n");
return;
}
