#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
    int numA = 0, numE = 0, numI = 0, numO = 0, numU = 0;
    char str[100];
    fscanf(fp, "%s", str);
    int len = strlen(str);
    while (!feof(fp)) {
    for (int i = 0; i < len; i++) {
      if ((str[i] == 'a') || (str[i] == 'A')) numA++;
      else if ((str[i] == 'e') || (str[i] == 'E')) numE++;
      else if ((str[i] == 'i') || (str[i] == 'I')) numI++;
      else if ((str[i] == 'o') || (str[i] == 'O')) numO++;
      else if ((str[i] == 'u') || (str[i] == 'U')) numU++;
    }
      fscanf(fp, "%s", str);
      len = strlen(str);
    }
      printf("%s\n", str);
    double percentA, percentE, percentI, percentO, percentU;
    double sum = numA + numE + numI + numO + numU;
    percentA = (numA/sum)*100.0;
    percentE = (numE/sum)*100.0;
    percentI = (numI/sum)*100.0;
    percentO = (numO/sum)*100.0;
    percentU = (numU/sum)*100.0;
    printf("%d, %lf percent, were a/A\n", numA, percentA);
    printf("%d, %lf percent, were e/E\n", numE, percentE);
    printf("%d, %lf percent, were i/I\n", numI, percentI);
    printf("%d, %lf percent, were o/O\n", numO, percentO);
    printf("%d, %lf percent, were u/U\n", numU, percentU);

return 0;
}
