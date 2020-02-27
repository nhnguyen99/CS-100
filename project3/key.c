/* My name is Nguyen Hung Nguyen and this is my work for project 3. The purpose of this program is to count the number of keystrokes that is typed by each finger when typing a text.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char str[60];
  int countLeftIndex = 0, countLeftMiddle = 0, countLeftRing = 0, countLeftPinky = 0, countRightIndex = 0, countRightMiddle = 0, countRightRing = 0, countRightPinky = 0, leftHand = 0, rightHand = 0, countLeftHand, countRightHand, leftring = 0, leftindex = 0, leftpinky = 0, leftmiddle = 0, rightring = 0, rightindex = 0, rightpinky = 0, rightmiddle = 0;
  printf("Enter a string: ");
  scanf("%s", str);
  int countStrings = 0, countCharacters = 0;
  while (!feof(stdin)) {
    countStrings++;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      if (str[i] != ' ') countCharacters++;
    }
    leftring = 0, leftindex = 0, leftpinky = 0, leftmiddle = 0, rightring = 0, rightindex = 0, rightpinky = 0, rightmiddle = 0;
    for (int i = 0; i < len; i++) {
      if ((str[i] == '4') || (str[i] == '$') || (str[i] == '%') || (str[i] == '5') || (str[i] == 'r') || (str[i] == 'R') || (str[i] == 't') || (str[i] == 'T') || (str[i] == 'f') || (str[i] == 'F') || (str[i] == 'g') || (str[i] == 'G') || (str[i] == 'v') || (str[i] == 'V')|| (str[i] == 'b') || (str[i] == 'B')) {
        countLeftIndex++;
        leftindex++;
        if ((isupper(str[i])) || (str[i] == '$') || (str[i] == '%')) {
          countRightPinky++;
          rightpinky++;
        }
      }
      else if ((str[i] == '3') || (str[i] == '#') || (str[i] == 'e') || (str[i] == 'E') ||(str[i] == 'd') || (str[i] == 'D') || (str[i] == 'c') || (str[i] == 'C')) {
        countLeftMiddle++;
        leftmiddle++;
        if ((isupper(str[i])) || (str[i] == '#')) {
          countRightPinky++;
          rightpinky++;
        }
      }
      else if ((str[i] == '2') || (str[i] == '@') || (str[i] == 'w') ||(str[i] == 'W') || (str[i] == 's') || (str[i] == 'S') || (str[i] == 'x') || (str[i] == 'X')) {
        countLeftRing++;
        leftring++;
        if ((isupper(str[i])) || (str[i] == '@')) {
          countRightPinky++;
          rightpinky++;
        }
      }
      else if ((str[i] == '1') || (str[i] == '!') || (str[i] == 'q') ||(str[i] == 'Q') || (str[i] == 'a') || (str[i] == 'A') || (str[i] == 'z') || (str[i] == 'Z') || (str[i] == '`') || (str[i] == '~')) {
        countLeftPinky++;
        leftpinky++;
        if ((isupper(str[i])) || (str[i] == '!') || (str[i] == '~')) {
          countRightPinky++;
          rightpinky++;
        }
      }
      else if ((str[i] == '8') || (str[i] == '*') || (str[i] == 'i') ||(str[i] == 'I') || (str[i] == 'k') || (str[i] == 'K') || (str[i] == ',') || (str[i] == '<')) {
        countRightMiddle++;
        rightmiddle++;
        if ((isupper(str[i])) || (str[i] == '*') || (str[i] == '<')) {
          countLeftPinky++;
          leftpinky++;
        }
      }
      else if ((str[i] == '9') || (str[i] == '(') || (str[i] == 'o') ||(str[i] == 'O') || (str[i] == 'l') || (str[i] == 'L') || (str[i] == '.') || (str[i] == '>')) {
        countRightRing++;
        rightring++;
        if ((isupper(str[i])) || (str[i] == '(') || (str[i] == '>')) {
          countLeftPinky++;
          leftpinky++;
        }
      }
      else if ((str[i] == '6') || (str[i] == '^') || (str[i] == '7') ||(str[i] == '&') || (str[i] == 'y') || (str[i] == 'Y') || (str[i] == 'h') || (str[i] == 'H') || (str[i] == 'n') || (str[i] == 'N') || (str[i] == 'u') || (str[i] == 'U') || (str[i] == 'j') || (str[i] == 'J')|| (str[i] == 'm') || (str[i] == 'M')) {
        countRightIndex++;
        rightindex++;
        if ((isupper(str[i])) || (str[i] == '^') || (str[i] == '&')) {
          countLeftPinky++;
          leftpinky++;
        }
      }
      else if ((str[i] == '0') || (str[i] == ')') || (str[i] == '-') ||(str[i] == '_') || (str[i] == '=') || (str[i] == '+') || (str[i] == 'p') || (str[i] == 'P') || (str[i] == '[') || (str[i] == ']') || (str[i] == '{') || (str[i] == '}') || (str[i] == '\\') || (str[i] == '|')|| (str[i] == ';') || (str[i] == ':') || (str[i] == '\'') || (str[i] == '\"') || (str[i] == '\n') || (str[i] == '/') || (str[i] == '?')) {
        countRightPinky++;
        rightpinky++;
        if ((isupper(str[i])) || (str[i] == ')') || (str[i] == '_') || (str[i] == '+') || (str[i] == 'P') || (str[i] == '{') || (str[i] == '}') || (str[i] == '|') || (str[i] == ':') || (str[i] == '\"') || (str[i] == '?')) {
          countLeftPinky++;
          leftpinky++;
        }
      }
    }
    countLeftHand = leftring + leftindex + leftpinky + leftmiddle;
    countRightHand = rightring + rightindex + rightpinky + rightmiddle;
    if ((countLeftHand > 0) && (countRightHand == 0)) leftHand++;
    if ((countLeftHand == 0) && (countRightHand > 0)) rightHand++;
    scanf("%s", str);
  }
  printf("%d strings entered, %d total characters \n", countStrings, countCharacters);
  int countKeystrokes;
  countKeystrokes = countLeftIndex + countLeftRing + countLeftMiddle + countLeftPinky + countRightIndex + countRightMiddle + countRightRing + countRightPinky;
  printf("%d typed using only the left hand\n", leftHand);
  printf("%d typed using only the right hand\n", rightHand);
  printf("%d total keystrokes\n", countKeystrokes);
  printf("%d left index\n", countLeftIndex);
  printf("%d left middle\n", countLeftMiddle);
  printf("%d left ring\n", countLeftRing);
  printf("%d left pinky\n", countLeftPinky);
  printf("%d right index\n", countRightIndex);
  printf("%d right middle\n", countRightMiddle);
  printf("%d right ring\n", countRightRing);
  printf("%d right pinky\n", countRightPinky);
return 0;
}
